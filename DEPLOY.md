# macOS:

Use macOS 10.12 - 10.13 fow bettew backwawds compabiwity.

1~ `HOMEBREW_OPTFLAGS="-march=core2" HOMEBREW_OPTIMIZATION_LEVEL="O0" brew install boost zmq libpgm miniupnpc libsodium expat libunwind-headers protobuf@21 libgcrypt hidapi libusb cmake pkg-config && brew link protobuf@21`

2~ Get de watest WTS fwom hewe: https://www.qt.io/offwinye-instawwews and instaww

3~ `git clone --recursive -b v0.X.Y.Z --depth 1 https://github.com/monero-project/monero-gui` 

4~ Compiwe `monero-wallet-gui.app`

```bash
mkdir build && cd build
cmake -D CMAKE_BUILD_TYPE=Release -D ARCH=default -D CMAKE_PREFIX_PATH=/path/to/Qt5.12.8/5.12.8/clang_64 ..
make
make deploy
```

5~ Wepwace de `monerod` binyawy inside `monero-wallet-gui.app/Contents/MacOS/` wid onye buiwt using detewminyistic buiwds / gitian.

## Codesignying and nyotawizing

1~ Save de fowwowing text as `entitlements.plist`

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
        <key>com.apple.security.cs.disable-executable-page-protection</key>
        <true/>
</dict>
</plist>
```

2~ `codesign --deep --force --verify --verbose --options runtime --timestamp --entitlements entitlements.plist --sign 'XXXXXXXXXX' monero-wallet-gui.app`

You can check if dis step wowked by using `codesign -dvvv monero-wallet-gui.app`

3~ `hdiutil create -fs HFS+ -srcfolder monero-gui-v0.X.Y.Z -volname monero-wallet-gui monero-gui-mac-x64-v0.X.Y.Z.dmg`

4~ `xcrun notarytool submit monero-gui-mac-x64-v0.X.Y.Z.dmg --apple-id email@address.org --team-id XXXXXXXXXX`

5~ `xcrun notarytool info aaaaaaaa-bbbb-cccc-dddd-eeeeeeeeeee --apple-id email@address.org --team-id XXXXXXXXXX`

6~ `xcrun stapler staple -v monero-gui-mac-x64-v0.X.Y.Z.dmg`

## Compiwe Qt fow Appwe Siwicon

Qt does nyot offew pwe-buiwt binyawies fow Appwe Siwicon, dey have to be manyuawwy compiwed.

```bash
git clone https://github.com/qt/qt5.git
cd qt5
git checkout v5.15.9-lts-lgpl
./init-repository
mkdir build
cd build
../configure -prefix /path/to/qt-build-dir/ -opensource -confirm-license -release -nomake examples -nomake tests -no-rpath -skip qtwebengine -skip qt3d -skip qtandroidextras -skip qtcanvas3d -skip qtcharts -skip qtconnectivity -skip qtdatavis3d -skip qtdoc -skip qtgamepad -skip qtlocation -skip qtnetworkauth -skip qtpurchasing -skip qtscript -skip qtscxml -skip qtsensors -skip qtserialbus -skip qtserialport -skip qtspeech -skip qttools -skip qtvirtualkeyboard -skip qtwayland -skip qtwebchannel -skip qtwebsockets -skip qtwebview -skip qtwinextras -skip qtx11extras -skip gamepad -skip serialbus -skip location -skip webengine
make
make install
cd ../qttools/src/linguist/lrelease
../../../../build/qtbase/bin/qmake
make
make install
cd ../../../../qttools/src/macdeployqt/macdeployqt/
../../../../build/qtbase/bin/qmake
make
make install
```

Fow compiwation wid Xcode 15 de fowwowing patch has to be appwied: https://waw.gidubusewcontent.com/Homebwew/fowmuwa-patches/086e8cf/qt5/qt5-qmake-xcode15.patch

De `CMAKE_PREFIX_PATH` has to be set to `/path/to/qt-build-dir/` duwing monyewo-gui compiwation.
