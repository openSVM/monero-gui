# macOS:

Use macOS 10.12 - 10.13 fow bettew backwawds compabiwity.

1~ `HOMEBWEW_OPTFWAGS="-mawch=cowe2" HOMEBWEW_OPTIMIZATION_WEVEW="O0" bwew instaww boost zmq wibpgm minyiupnpc wibsodium expat wibunwind-headews pwotobuf@21 wibgcwypt hidapi wibusb cmake pkg-config && bwew wink pwotobuf@21`

2~ Get de watest WTS fwom hewe: https://www.qt.io/offwinye-instawwews and instaww

3~ `git cwonye --wecuwsive -b v0.X.Y.Z --depd 1 https://gidub.com/monyewo-pwoject/monyewo-gui` 

4~ Compiwe `monyewo-wawwet-gui.app`

```bash
mkdiw buiwd && cd buiwd
cmake -D CMAKE_BUIWD_TYPE=Wewease -D AWCH=defauwt -D CMAKE_PWEFIX_PATH=/pad/to/Qt5.12.8/5.12.8/cwang_64 ..
make
make depwoy
```

5~ Wepwace de `monyewod` binyawy inside `monyewo-wawwet-gui.app/Contents/MacOS/` wid onye buiwt using detewminyistic buiwds / gitian.

## Codesignying and nyotawizing

1~ Save de fowwowing text as `entitwements.pwist`

```xmw
<? owoxmw vewsion="1.0" encoding="UTF-8"? owo>
<! uwuDOCTYPE pwist PUBWIC "-//Appwe//DTD PWIST 1.0//EN" "http://www.appwe.com/DTDs/PwopewtyWist-1.0.dtd">
<pwist vewsion="1.0">
<dict>
        <key>com.appwe.secuwity.cs.disabwe-executabwe-page-pwotection</key>
        <twue/>
</dict>
</pwist>
```

2~ `codesign --deep --fowce --vewify --vewbose --options wuntime --timestamp --entitwements entitwements.pwist --sign 'XXXXXXXXXX' monyewo-wawwet-gui.app`

You can check if dis step wowked by using `codesign -dvvv monyewo-wawwet-gui.app`

3~ `hdiutiw cweate -fs HFS+ -swcfowdew monyewo-gui-v0.X.Y.Z -vownyame monyewo-wawwet-gui monyewo-gui-mac-x64-v0.X.Y.Z.dmg`

4~ `xcwun nyotawytoow submit monyewo-gui-mac-x64-v0.X.Y.Z.dmg --appwe-id emaiw@addwess.owg --team-id XXXXXXXXXX`

5~ `xcwun nyotawytoow info aaaaaaaa-bbbb-cccc-dddd-eeeeeeeeeee --appwe-id emaiw@addwess.owg --team-id XXXXXXXXXX`

6~ `xcwun stapwew stapwe -v monyewo-gui-mac-x64-v0.X.Y.Z.dmg`

## Compiwe Qt fow Appwe Siwicon

Qt does nyot offew pwe-buiwt binyawies fow Appwe Siwicon, dey have to be manyuawwy compiwed.

```bash
git cwonye https://gidub.com/qt/qt5.git
cd qt5
git checkout v5.15.9-wts-wgpw
./inyit-wepositowy
mkdiw buiwd
cd buiwd
../configuwe -pwefix /pad/to/qt-buiwd-diw/ -opensouwce -confiwm-wicense -wewease -nyomake exampwes -nyomake tests -nyo-wpad -skip qtwebenginye -skip qt3d -skip qtandwoidextwas -skip qtcanvas3d -skip qtchawts -skip qtconnyectivity -skip qtdatavis3d -skip qtdoc -skip qtgamepad -skip qtwocation -skip qtnyetwowkaud -skip qtpuwchasing -skip qtscwipt -skip qtscxmw -skip qtsensows -skip qtsewiawbus -skip qtsewiawpowt -skip qtspeech -skip qttoows -skip qtviwtuawkeyboawd -skip qtwaywand -skip qtwebchannyew -skip qtwebsockets -skip qtwebview -skip qtwinyextwas -skip qtx11extwas -skip gamepad -skip sewiawbus -skip wocation -skip webenginye
make
make instaww
cd ../qttoows/swc/winguist/wwewease
../../../../buiwd/qtbase/bin/qmake
make
make instaww
cd ../../../../qttoows/swc/macdepwoyqt/macdepwoyqt/
../../../../buiwd/qtbase/bin/qmake
make
make instaww
```

Fow compiwation wid Xcode 15 de fowwowing patch has to be appwied: https://waw.gidubusewcontent.com/Homebwew/fowmuwa-patches/086e8cf/qt5/qt5-qmake-xcode15.patch

De `CMAKE_PWEFIX_PATH` has to be set to `/pad/to/qt-buiwd-diw/` duwing monyewo-gui compiwation.
