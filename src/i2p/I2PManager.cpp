// Copyright (c) 2014-2023, The Monero Project
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "I2PManager.h"
#include <QCryptographicHash>
#include <QStandardPaths>
#include <QFileInfo>
#include <QDir>
#include <QDebug>
#include <QFile>
#include <QProcess>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QRegularExpression>
#include <QThread>
#include <QMutexLocker>
#include "qt/network.h"

I2PManager::I2PManager(QObject *parent)
    : QObject(parent)
{
    initialize();
}

I2PManager::~I2PManager()
{
    exit();
}

void I2PManager::initialize()
{
    m_i2pPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/i2p";
    QDir dir;
    if (!dir.exists(m_i2pPath)) {
        dir.mkpath(m_i2pPath);
    }

#ifdef Q_OS_WIN
    m_i2p = m_i2pPath + "/i2pd.exe";
#else
    m_i2p = m_i2pPath + "/i2pd";
#endif

    m_i2pd = new QProcess(this);
    connect(m_i2pd, &QProcess::readyReadStandardOutput, this, &I2PManager::readOutput);
    connect(m_i2pd, &QProcess::readyReadStandardError, this, &I2PManager::readError);
    connect(m_i2pd, &QProcess::stateChanged, this, &I2PManager::stateChanged);

    emit i2pPathChanged();
    emit isInstalledChanged();
}

QString I2PManager::i2pPath() const
{
    return m_i2pPath;
}

bool I2PManager::isInstalled()
{
    if (!QFileInfo(m_i2p).isFile())
    {
        return false;
    }
    return true;
}

bool I2PManager::isRunning() const
{
    return started;
}

QString I2PManager::address() const
{
    return m_address;
}

void I2PManager::download()
{
    m_scheduler.run([this] {
        QUrl url;
        QString fileName;
        QString validHash;
        
        #ifdef Q_OS_WIN
            url = "https://github.com/PurpleI2P/i2pd/releases/download/2.46.1/i2pd_2.46.1_win64.zip";
            fileName = m_i2pPath + "/i2pd_2.46.1_win64.zip";
            validHash = "e9e7e0d0c9a2e8a2a3a8b8d9d9f9e9d9c9a2e8a2a3a8b8d9d9f9e9d9c9a2e8a2"; // Replace with actual hash
        #elif defined(Q_OS_LINUX)
            url = "https://github.com/PurpleI2P/i2pd/releases/download/2.46.1/i2pd_2.46.1_linux_x64.tar.gz";
            fileName = m_i2pPath + "/i2pd_2.46.1_linux_x64.tar.gz";
            validHash = "e9e7e0d0c9a2e8a2a3a8b8d9d9f9e9d9c9a2e8a2a3a8b8d9d9f9e9d9c9a2e8a2"; // Replace with actual hash
        #elif defined(Q_OS_MAC)
            url = "https://github.com/PurpleI2P/i2pd/releases/download/2.46.1/i2pd_2.46.1_osx.tar.gz";
            fileName = m_i2pPath + "/i2pd_2.46.1_osx.tar.gz";
            validHash = "e9e7e0d0c9a2e8a2a3a8b8d9d9f9e9d9c9a2e8a2a3a8b8d9d9f9e9d9c9a2e8a2"; // Replace with actual hash
        #else
            emit i2pDownloadFailure(BinaryNotAvailable);
            return;
        #endif

        QFile file(fileName);
        
        Network network;
        std::shared_ptr<HttpClient> httpClient = std::static_pointer_cast<HttpClient>(network.newClient());
        httpClient->setCallback([this, &file, &httpClient](const std::string& err, const http_response_info* info, const std::string& body) {
            if (!err.empty()) {
                qCritical() << "Failed to download I2P:" << QString::fromStdString(err);
                emit i2pDownloadFailure(ConnectionIssue);
                return false;
            }
            
            if (info->m_response_code != 200) {
                qCritical() << "Failed to download I2P, HTTP response code:" << info->m_response_code;
                if (info->m_response_code == 404) {
                    emit i2pDownloadFailure(BinaryNotAvailable);
                } else {
                    emit i2pDownloadFailure(ConnectionIssue);
                }
                return false;
            }
            
            return true;
        });
        
        bool success = false;
        std::string response;
        QString error = network.get(httpClient, url.toString(), response);
        success = error.isEmpty();
        
        if (!success) {
            emit i2pDownloadFailure(ConnectionIssue);
            return;
        }
        
        QByteArray data(response.c_str(), response.length());
        QByteArray hashData = QCryptographicHash::hash(data, QCryptographicHash::Sha256);
        QString hash = hashData.toHex();
        
        // Uncomment when we have actual hashes
        /*
        if (hash != validHash) {
            emit i2pDownloadFailure(HashVerificationFailed);
            return;
        }
        */
        
        file.open(QIODevice::WriteOnly);
        file.write(data);
        file.close();
        
        // Extract the archive
        #ifdef Q_OS_WIN
            QProcess::execute("powershell", {"-Command", "Expand-Archive", "-Path", fileName, "-DestinationPath", m_i2pPath, "-Force"});
        #else
            QProcess::execute("tar", {"-xzf", fileName, "-C", m_i2pPath});
        #endif
        
        QFile::remove(fileName);
        
        if (isInstalled()) {
            emit i2pDownloadSuccess();
            emit isInstalledChanged();
        } else {
            emit i2pDownloadFailure(InstallationFailed);
        }
    });
}

bool I2PManager::start(const QString &flags)
{
    if (!isInstalled()) {
        qCritical() << "I2P is not installed";
        emit i2pStartFailure();
        return false;
    }
    
    if (started) {
        qDebug() << "I2P is already running";
        return true;
    }
    
    QStringList arguments;
    
    // Add default arguments
    arguments << "--datadir" << m_i2pPath + "/data";
    arguments << "--conf=" + m_i2pPath + "/i2pd.conf";
    arguments << "--tunnelsconf=" + m_i2pPath + "/tunnels.conf";
    
    // Add user-provided flags
    foreach (const QString &str, flags.split(" ")) {
        qDebug() << QString(" [%1] ").arg(str);
        if (!str.isEmpty())
            arguments << str;
    }
    
    // Create data directory if it doesn't exist
    QDir dir;
    QString dataDir = m_i2pPath + "/data";
    if (!dir.exists(dataDir)) {
        dir.mkpath(dataDir);
    }
    
    // Create default config files if they don't exist
    QFile confFile(m_i2pPath + "/i2pd.conf");
    if (!confFile.exists()) {
        confFile.open(QIODevice::WriteOnly);
        confFile.write("[http]\nenabled = true\naddress = 127.0.0.1\nport = 7070\n\n");
        confFile.write("[httpproxy]\nenabled = true\naddress = 127.0.0.1\nport = 4444\n\n");
        confFile.write("[socksproxy]\nenabled = true\naddress = 127.0.0.1\nport = 4447\n\n");
        confFile.close();
    }
    
    QFile tunnelsFile(m_i2pPath + "/tunnels.conf");
    if (!tunnelsFile.exists()) {
        tunnelsFile.open(QIODevice::WriteOnly);
        tunnelsFile.write("[monero-rpc]\ntype = client\naddress = 127.0.0.1\nport = 18081\ndestination = 127.0.0.1\ndestinationport = 18081\nkeys = monero-rpc.dat\n\n");
        tunnelsFile.close();
    }
    
    qDebug() << "Starting I2P with arguments:" << arguments;
    m_i2pd->start(m_i2p, arguments);
    
    if (!m_i2pd->waitForStarted()) {
        qCritical() << "I2P start error:" << m_i2pd->errorString();
        emit i2pStartFailure();
        return false;
    }
    
    started = true;
    emit statusChanged();
    
    // Wait a bit for I2P to initialize and then get the status
    QThread::sleep(2);
    getStatus();
    
    return true;
}

void I2PManager::stop()
{
    if (!started) {
        return;
    }
    
    m_i2pd->terminate();
    if (!m_i2pd->waitForFinished(3000)) {
        m_i2pd->kill();
    }
    
    started = false;
    m_address = "";
    emit statusChanged();
    emit addressChanged();
}

void I2PManager::exit()
{
    qDebug("I2PManager: exit()");
    stop();
}

void I2PManager::getStatus()
{
    if (!started) {
        emit i2pStatus(false, "");
        return;
    }
    
    m_scheduler.run([this] {
        // Try to get the I2P address from the HTTP console
        Network network;
        std::shared_ptr<HttpClient> httpClient = std::static_pointer_cast<HttpClient>(network.newClient());
        
        std::string response;
        QString error = network.get(httpClient, "http://127.0.0.1:7070/", response);
        
        if (error.isEmpty() && !response.empty()) {
            // I2P is running
            // Try to extract the local I2P address
            QRegularExpression re("Router Identity:</b>\\s*([a-zA-Z0-9\\.]+)");
            QRegularExpressionMatch match = re.match(QString::fromStdString(response));
            
            if (match.hasMatch()) {
                QString address = match.captured(1);
                if (m_address != address) {
                    m_address = address;
                    emit addressChanged();
                }
                emit i2pStatus(true, address);
                return;
            }
        }
        
        // If we couldn't get the address but the process is running, still report as running
        emit i2pStatus(started, m_address);
    });
}

void I2PManager::readOutput()
{
    QByteArray output = m_i2pd->readAllStandardOutput();
    QString outputString = QString::fromUtf8(output);
    
    // Look for the I2P address in the output
    QRegularExpression re("Router identity: ([a-zA-Z0-9\\.]+)");
    QRegularExpressionMatch match = re.match(outputString);
    
    if (match.hasMatch()) {
        QString address = match.captured(1);
        if (m_address != address) {
            m_address = address;
            emit addressChanged();
        }
    }
    
    qDebug() << "I2P output:" << outputString;
}

void I2PManager::readError()
{
    QByteArray error = m_i2pd->readAllStandardError();
    qDebug() << "I2P error:" << QString::fromUtf8(error);
}

void I2PManager::stateChanged(QProcess::ProcessState state)
{
    if (state == QProcess::NotRunning) {
        if (started) {
            started = false;
            m_address = "";
            emit statusChanged();
            emit addressChanged();
        }
    }
}

QString I2PManager::getDefaultFlags() const
{
    return "--http.enabled=true --httpproxy.enabled=true --socksproxy.enabled=true";
}

void I2PManager::updateStatus()
{
    if (started) {
        getStatus();
    } else {
        emit i2pStatus(false, "");
    }
}
