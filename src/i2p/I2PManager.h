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

#ifndef I2PMANAGER_H
#define I2PMANAGER_H

#include <QObject>
#include <QProcess>
#include <QMutex>
#include <QDir>
#include <QMap>
#include <QString>
#include <QVariant>
#include "qt/FutureScheduler.h"

class I2PManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString i2pPath READ i2pPath NOTIFY i2pPathChanged)
    Q_PROPERTY(bool isInstalled READ isInstalled NOTIFY isInstalledChanged)
    Q_PROPERTY(bool isRunning READ isRunning NOTIFY statusChanged)
    Q_PROPERTY(QString address READ address NOTIFY addressChanged)

public:
    explicit I2PManager(QObject *parent = nullptr);
    ~I2PManager();

    enum DownloadFailure {
        ConnectionIssue,
        HashVerificationFailed,
        BinaryNotAvailable,
        InstallationFailed
    };
    Q_ENUM(DownloadFailure)

    Q_INVOKABLE void download();
    Q_INVOKABLE bool start(const QString &flags = "");
    Q_INVOKABLE void stop();
    Q_INVOKABLE void exit();
    Q_INVOKABLE void getStatus();
    Q_INVOKABLE QString i2pPath() const;
    Q_INVOKABLE bool isInstalled();
    Q_INVOKABLE bool isRunning() const;
    Q_INVOKABLE QString address() const;
    Q_INVOKABLE QString getDefaultFlags() const;

signals:
    void i2pDownloadSuccess();
    void i2pDownloadFailure(DownloadFailure failure);
    void i2pStartFailure();
    void i2pStatus(bool running, QString address);
    void i2pPathChanged();
    void isInstalledChanged();
    void statusChanged();
    void addressChanged();

private slots:
    void readOutput();
    void readError();
    void stateChanged(QProcess::ProcessState state);

private:
    FutureScheduler m_scheduler;
    QProcess *m_i2pd = nullptr;
    QString m_i2pPath;
    QString m_i2p;
    QString m_address;
    bool started = false;
    QMutex m_mutex;

    void initialize();
    void updateStatus();
};

#endif // I2PMANAGER_H
