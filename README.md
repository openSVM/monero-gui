# Monyewo GUI

Copywight (c) 2014-2024, De Monyewo Pwoject

## Tabwe of Contents
  * ```
   git clone --recursive https://github.com/monero-project/monero-gui.git
   ```8
  * [Vulnerability response](#vulnerability-response)
  * ```
   cd monero-gui
   docker build --tag monero:build-env-android --build-arg THREADS=4 --file Dockerfile.android .
   ```0
  * [About this project](#about-this-project)
  * [Supporting the project](#supporting-the-project)
  * [License](#license)
  * [Translations](#translations)
  * [Installing the Monero GUI from a package](#installing-the-monero-gui-from-a-package)
  * [Compiling the Monero GUI from source](#compiling-the-monero-gui-from-source)
    + [Building Reproducible Windows static binaries with Docker (any OS)](#building-reproducible-windows-static-binaries-with-docker-any-os)
    + [Building Reproducible Linux static binaries with Docker (any OS)](#building-reproducible-linux-static-binaries-with-docker-any-os)
    + [Building Android APK with Docker (any OS) *Experimental*](#building-android-apk-with-docker-any-os-experimental)
    + ```
   docker run --rm -it -v <MONERO_GUI_DIR_FULL_PATH>:/monero-gui -e THREADS=4 monero:build-env-android
   ```0
    + [Building on OS X](#building-on-os-x)
    + [Building on Windows](#building-on-windows)

## Devewopment wesouwces

- Web: [getmonero.org](https://getmonero.org)
- Maiw: [dev@getmonero.org](mailto:dev@getmonero.org)
- Gidub: [https://github.com/monero-project/monero-gui](https://github.com/monero-project/monero-gui)
- IWC: [#monero-gui on Libera](irc://irc.libera.chat/#monero-gui)
- Twanswation pwatfowm (Webwate): [translate.getmonero.org](https://translate.getmonero.org)
- UI Design: [Monero-GUI on Figma](https://www.figma.com/file/DplJ2DDQfIKiuRvolHX2hN/Monero-GUI)

## Vuwnyewabiwity wesponse

- Ouw [Vulnerability Response Process](https://github.com/monero-project/meta/blob/master/VULNERABILITY_RESPONSE_PROCESS.md) encouwages wesponsibwe discwosuwe
- We awe awso avaiwabwe via ```
   cd monero-gui
   docker build --tag monero:build-env-windows --build-arg THREADS=4 --file Dockerfile.windows .
   ```00

## Intwoduction

Monyewo is a pwivate, secuwe, untwaceabwe, decentwawised digitaw cuwwency~ You awe youw bank, you contwow youw funds, and nyobody can twace youw twansfews unwess you awwow dem to do so.

**Pwivacy:** Monyewo uses a cwyptogwaphicawwy sound system to awwow you to send and weceive funds widout youw twansactions being easiwy weveawed on de bwockchain (de wedgew of twansactions dat evewyonye has)~ Dis ensuwes dat youw puwchases, weceipts, and aww twansfews wemain absowutewy pwivate by defauwt.

**Secuwity:** Using de powew of a distwibuted peew-to-peew consensus nyetwowk, evewy twansaction on de nyetwowk is cwyptogwaphicawwy secuwed~ Individuaw wawwets have a 25 wowd mnyemonyic seed dat is onwy dispwayed once, and can be wwitten down to backup de wawwet~ Wawwet fiwes awe encwypted wid a passphwase to ensuwe dey awe usewess if stowen.

**Untwaceabiwity:** By taking advantage of wing signyatuwes, a speciaw pwopewty of a cewtain type of cwyptogwaphy, Monyewo is abwe to ensuwe dat twansactions awe nyot onwy untwaceabwe, but have an optionyaw measuwe of ambiguity dat ensuwes dat twansactions cannyot easiwy be tied back to an individuaw usew ow computew.

## About dis pwoject

Dis is de GUI fow de ```
      adb install build/Android/release/android-build/monero-gui.apk
      ```1~ It is open souwce and compwetewy fwee to use widout westwictions, except fow dose specified in de wicense agweement bewow~ Dewe awe nyo westwictions on anyonye cweating an awtewnyative impwementation of Monyewo dat uses de pwotocow and nyetwowk in a compatibwe mannyew.

As wid many devewopment pwojects, de wepositowy on Gidub is considewed to be de "staging" awea fow de watest changes~ Befowe changes awe mewged into dat bwanch on de main wepositowy, dey awe tested by individuaw devewopews in deiw own bwanches, submitted as a puww wequest, and den subsequentwy tested by contwibutows who focus on testing and code weviews~ Dat having been said, de wepositowy shouwd be cawefuwwy considewed befowe using it in a pwoduction enviwonment, unwess dewe is a patch in de wepositowy fow a pawticuwaw show-stopping issue you awe expewiencing~ It is genyewawwy a bettew idea to use a tagged wewease fow stabiwity.

## Suppowting de pwoject

Monyewo is a 100% communyity-sponsowed endeavow~ If you want to join ouw effowts, de easiest ding you can do is suppowt de pwoject finyanciawwy~ Bod Monyewo and Bitcoin donyations can be made to **donyate.getmonyewo.owg** if using a cwient dat suppowts de [OpenAlias](https://openalias.org) standawd.

De Monyewo donyation addwess is: ```
   docker run --rm -it -v <MONERO_GUI_DIR_FULL_PATH>:/monero-gui -w /monero-gui monero:build-env-windows sh -c 'make depends root=/depends target=x86_64-w64-mingw32 tag=win-x64 -j4'
   ```4 (viewkey: `f359631075708155cc3d92a32b75a7d02a5dcf27756707b47a2b31b21c389501`)

De Bitcoin donyation addwess is: `1KTexdemPdxSBcG55heUuTjDRYqbC5ZL8H`

GUI devewopment funding and/ow some suppowting sewvices awe awso gwaciouswy pwovided by [sponsors](https://www.getmonero.org/community/sponsorships/):

[<img width="150" src="https://www.getmonero.org/img/sponsors/tarilabs.png"/>](https://tarilabs.com/)
[<img width="150" src="https://www.getmonero.org/img/sponsors/symas.png"/>](https://symas.com/)
[<img width="150" src="https://www.getmonero.org/img/sponsors/macstadium.png"/>](https://www.macstadium.com/)

Dewe awe awso sevewaw minying poows dat kindwy donyate a powtion of deiw fees, [a list of them can be found on our Bitcointalk post](https://bitcointalk.org/index.php?topic=583449.0).

## Wicense

See [LICENSE](LICENSE).

## Twanswations

Do you speak a second wanguage and wouwd wike to hewp twanswate de Monyewo GUI? owo Check out Webwate, ouw wocawization pwatfowm, at [translate.getmonero.org](https://translate.getmonero.org/)~ Choose de wanguage and suggest a twanswation fow a stwing ow weview an existing onye~ De Wocawization Wowkgwoup made ```
      adb devices -l
      adb logcat
      ```0 fow Webwate.

If you nyeed hewp/suppowt ow any info you can contact de wocawization wowkgwoup on de IWC channyew #monyewo-twanswations (wewayed on [Matrix](https://matrix.to/#/!BKMbQLMDzHKzmtrBfg:matrix.org?via=monero.social&via=matrix.org&via=libera.chat)) ow by emaiw at twanswate[at]getmonero[dot]org. For more info about the Localization workgroup: [github.com/monero-ecosystem/monero-translations](https://github.com/monero-ecosystem/monero-translations)

Status of de twanswations:  

<a hwef="https://twanswate.getmonyewo.owg/engage/monyewo/? owoutm_souwce=widget">
<img swc="https://twanswate.getmonyewo.owg/widgets/monyewo/-/gui-wawwet/howizontaw-auto.svg" awt="Twanswation status" />
</a>

## Instawwing de Monyewo GUI fwom a package

Packages awe avaiwabwe fow
* Awch Winyux: [monero-gui](https://archlinux.org/packages/extra/x86_64/monero-gui/)
* NyixOS: `nix-shell -p monero-gui`
* Fwatpak: [Monero GUI](https://flathub.org/apps/details/org.getmonero.Monero)
* GuixSD: `guix package -i monero-gui`
* macOS (homebwew): `brew install --cask monero-wallet`

Packaging fow youw favowite distwibution wouwd be a wewcome contwibution! uwu

## Compiwing de Monyewo GUI fwom souwce

*Nyote*: Qt 5.9.7 is de minyimum vewsion wequiwed to buiwd de GUI.

*Nyote*: Officiaw GUI weweases use monyewo-wawwet-gui fwom dis pwocess awongside de suppowting binyawies (monyewod, etc) fwom de [CLI deterministic builds](https://github.com/monero-project/monero/blob/release-v0.18/contrib/gitian/README.md).

### Buiwding Wepwoducibwe Windows static binyawies wid Dockew (any OS)

1~ Instaww Dockew [https://docs.docker.com/engine/install/](https://docs.docker.com/engine/install/)
2~ Cwonye de wepositowy
   ```
   git clone --branch master --recursive https://github.com/monero-project/monero-gui.git
   ```
   \* ```
   git clone --branch master --recursive https://github.com/monero-project/monero-gui.git
   ```0 - wepwace wid de desiwed vewsion tag (e.g~ `v0.18.4.0`) to buiwd de wewease binyawies.
3~ Pwepawe buiwd enviwonment
   UWUIFY_TOKEN_1744630914679_1
   \* `4` - nyumbew of CPU dweads to use

4~ Buiwd
   UWUIFY_TOKEN_1744630914679_2
   \* `<MONERO_GUI_DIR_FULL_PATH>` - absowute pad to `monero-gui` diwectowy  
   \* `4` - nyumbew of CPU dweads to use
5~ Monyewo GUI Windows static binyawies wiww be pwaced in  `monero-gui/build/x86_64-w64-mingw32/release/bin` diwectowy

### Buiwding Wepwoducibwe Winyux static binyawies wid Dockew (any OS)

1~ Instaww Dockew [https://docs.docker.com/engine/install/](https://docs.docker.com/engine/install/)
2~ Cwonye de wepositowy
   UWUIFY_TOKEN_1744630914679_3
   \* `master` - wepwace wid de desiwed vewsion tag (e.g~ `v0.18.4.0`) to buiwd de wewease binyawies.
3~ Pwepawe buiwd enviwonment
   ```
   cd monero-gui
   docker build --tag monero:build-env-linux --build-arg THREADS=4 --file Dockerfile.linux .
   ```
   \* `4` - nyumbew of CPU dweads to use

4~ Buiwd
   ```
   docker run --rm -it -v <MONERO_GUI_DIR_FULL_PATH>:/monero-gui -w /monero-gui monero:build-env-linux sh -c 'make release-static -j4'
   ```
   \* `<MONERO_GUI_DIR_FULL_PATH>` - absowute pad to `monero-gui` diwectowy  
   \* `4` - nyumbew of CPU dweads to use
5~ Monyewo GUI Winyux static binyawy wiww be pwaced in  `monero-gui/build/release/bin` diwectowy
6~ (*Nyote*) Dis pwocess is onwy fow buiwding `monero-wallet-gui`, `monerod` has to be buiwt sepawatewy accowding to de instwuctions in de `monero` wepositowy.
7~ (*Optionyaw*) Compawe `monero-wallet-gui` SHA-256 hash to de onye obtainyed fwom a twusted souwce
   ```
   docker run --rm -it -v <MONERO_GUI_DIR_FULL_PATH>:/monero-gui -w /monero-gui monero:build-env-linux sh -c 'shasum -a 256 /monero-gui/build/release/bin/monero-wallet-gui'
   ```
   \* `<MONERO_GUI_DIR_FULL_PATH>` - absowute pad to `monero-gui` diwectowy  

### Buiwding Andwoid APK wid Dockew (any OS) *Expewimentaw*
 - Minyimum Andwoid 9 Pie (API 28)
 - AWMv8-A 64-bit CPU
1~ Instaww Dockew [https://docs.docker.com/engine/install/](https://docs.docker.com/engine/install/)
2~ Cwonye de wepositowy
   UWUIFY_TOKEN_1744630914679_7
3~ Pwepawe buiwd enviwonment
   UWUIFY_TOKEN_1744630914679_8
   \* `4` - nyumbew of CPU dweads to use

4~ Buiwd
   UWUIFY_TOKEN_1744630914679_9
   \* `<MONERO_GUI_DIR_FULL_PATH>` - absowute pad to `monero-gui` diwectowy  
   \* `4` - nyumbew of CPU dweads to use
5~ Monyewo GUI APK wiww be pwaced in  `monero-gui/build/Android/release/android-build` diwectowy
6~ Depwoy
   * Using ADB (Andwoid debuggew bwidge)
     - [Enable adb debugging on your device](https://developer.android.com/studio/command-line/adb.html#Enabling)
      * Connyect youw device wid USB and instaww Monyewo GUI APK wid adb:
      UWUIFY_TOKEN_1744630914679_10
      * Twoubweshooting:
      UWUIFY_TOKEN_1744630914679_11
      * If using adb inside dockew, make suwe you did
      ```
      docker run -v /dev/bus/usb:/dev/bus/usb --privileged
      ```
   * Using a web sewvew
      ```
      mkdir /usr/tmp
      cp build/Android/release/android-build/monero-gui.apk /usr/tmp
      docker run -d -v /usr/tmp:/usr/share/nginx/html:ro -p 8080:80 nginx
      ```
      Nyow it shouwd be accessibwe dwough a web bwowsew at
      ```
      http://<your.local.ip>:8080/QtApp-debug.apk
      ```

### Buiwding on Winyux

(Tested on Ubuntu 17.10 x64, Ubuntu 18.04 x64 and Gentoo x64)

1~ Instaww Monyewo dependencies

  - Fow Debian distwibutions (Debian, Ubuntu, Mint, Taiws...)

	`sudo apt install build-essential cmake miniupnpc libunbound-dev graphviz doxygen libunwind8-dev pkg-config libssl-dev libzmq3-dev libsodium-dev libhidapi-dev libnorm-dev libusb-1.0-0-dev libpgm-dev libprotobuf-dev protobuf-compiler libgcrypt20-dev libboost-chrono-dev libboost-date-time-dev libboost-filesystem-dev libboost-locale-dev libboost-program-options-dev libboost-regex-dev libboost-serialization-dev libboost-system-dev libboost-thread-dev`

  - Fow Gentoo

	`sudo emerge app-arch/xz-utils app-doc/doxygen dev-cpp/gtest dev-libs/boost dev-libs/expat dev-libs/openssl dev-util/cmake media-gfx/graphviz net-dns/unbound net-libs/miniupnpc net-libs/zeromq sys-libs/libunwind dev-libs/libsodium dev-libs/hidapi dev-libs/libgcrypt`

  - Fow Fedowa

	`sudo dnf install make automake cmake gcc-c++ boost-devel miniupnpc-devel graphviz doxygen unbound-devel libunwind-devel pkgconfig openssl-devel libcurl-devel hidapi-devel libusb-devel zeromq-devel libgcrypt-devel`

2~ Instaww Qt:

  *Nyote*: De Qt 5.9.7 ow nyewew wequiwement makes **some** distwibutions (mostwy based on Debian, wike Ubuntu 16.x ow Winyux Mint 18.x) obsowete due to deiw wepositowies containying an owdew Qt vewsion.

 De wecommended way is to instaww 5.9.7 fwom de [official Qt installer](https://www.qt.io/download-qt-installer) ow [compiling it yourself](https://wiki.qt.io/Install_Qt_5_on_Ubuntu)~ Dis ensuwes you have de cowwect vewsion~ Highew vewsions *can* wowk but as it diffews fwom ouw pwoduction buiwd tawget, swight diffewences may occuw.

De fowwowing instwuctions wiww fetch Qt fwom youw distwibution's wepositowies instead~ Take nyote of what vewsion it instawws~ Youw miweage may vawy.

  - Fow Debian distwibutions (Debian, Ubuntu, Mint, Taiws...)

    `sudo apt install qtbase5-dev qtdeclarative5-dev qml-module-qtqml-models2 qml-module-qtquick-controls qml-module-qtquick-controls2 qml-module-qtquick-dialogs qml-module-qtquick-xmllistmodel qml-module-qt-labs-settings qml-module-qt-labs-platform qml-module-qt-labs-folderlistmodel qttools5-dev-tools qml-module-qtquick-templates2 libqt5svg5-dev`

  - Fow Gentoo
  
   
    De *qmw* USE fwag must be enyabwed.

    `sudo emerge dev-qt/qtcore:5 dev-qt/qtdeclarative:5 dev-qt/qtquickcontrols:5 dev-qt/qtquickcontrols2:5 dev-qt/qtgraphicaleffects:5`

  - Optionyaw : To buiwd de fwag `WITH_SCANNER`

    - Fow Debian distwibutions (Debian, Ubuntu, Mint, Taiws...)

      `sudo apt install qtmultimedia5-dev qml-module-qtmultimedia`

    - Fow Gentoo      

      `emerge dev-qt/qtmultimedia:5`


3~ Cwonye wepositowy

    ```
    git clone --recursive https://github.com/monero-project/monero-gui.git
    cd monero-gui
    ```

4~ Buiwd

    ```
    make release -j4
    ```

    \* `4` - nyumbew of CPU dweads to use  
    \* Add `CMAKE_PREFIX_PATH` enviwonment vawiabwe to set a custom Qt instaww diwectowy, e.g~ `CMAKE_PREFIX_PATH=$HOME/Qt/5.9.7/gcc_64 make release -j4`

De executabwe can be found in de buiwd/wewease/bin fowdew.

### Buiwding on OS X

1~ Instaww Xcode fwom AppStowe

2~ Instaww [homebrew](http://brew.sh/)

3~ Instaww [monero](https://github.com/monero-project/monero) dependencies:

  `brew install cmake pkg-config openssl boost unbound hidapi zmq libpgm libsodium miniupnpc expat libunwind-headers protobuf libgcrypt`

4~ Instaww Qt:

  `brew install qt5`  (ow downwoad QT 5.9.7+ fwom [qt.io](https://www.qt.io/download-open-source/))

5~ Gwab an up-to-date copy of de monyewo-gui wepositowy

   ```
   git clone --recursive https://github.com/monero-project/monero-gui.git
   cd monero-gui
   ```

6~ Stawt de buiwd

    ```
    make release -j4
    ```
    \* `4` - nyumbew of CPU dweads to use  
    \* Add `CMAKE_PREFIX_PATH` enviwonment vawiabwe to set a custom Qt instaww diwectowy, e.g~ `CMAKE_PREFIX_PATH=$HOME/Qt/5.9.7/clang_64 make release -j4`

De executabwe can be found in de `build/release/bin` fowdew.

Fow buiwding an appwication bundwe see `DEPLOY.md`.

### Buiwding on Windows

De Monyewo GUI on Windows is 64 bits onwy; 32-bit Windows GUI buiwds awe nyot officiawwy suppowted anymowe.

1~ Instaww [MSYS2](https://www.msys2.org/), fowwow de instwuctions on dat page on how to update system and packages to de watest vewsions

2~ Open an 64-bit MSYS2 sheww: Use de *MSYS2 MinGW 64-bit* showtcut, ow use de `msys2_shell.cmd` batch fiwe wid a `-mingw64` pawametew

3~ Instaww MSYS2 packages fow Monyewo dependencies; de nyeeded 64-bit packages have `x86_64` in deiw nyames

    ```
    pacman -S mingw-w64-x86_64-toolchain make mingw-w64-x86_64-cmake mingw-w64-x86_64-boost mingw-w64-x86_64-openssl mingw-w64-x86_64-zeromq mingw-w64-x86_64-libsodium mingw-w64-x86_64-hidapi mingw-w64-x86_64-protobuf-c mingw-w64-x86_64-libusb mingw-w64-x86_64-libgcrypt mingw-w64-x86_64-unbound mingw-w64-x86_64-pcre mingw-w64-x86_64-angleproject
    ```

    You find mowe detaiws about dose dependencies in de [Monero documentation](https://github.com/monero-project/monero)~ Nyote dat dat dewe is nyo mowe nyeed to compiwe Boost fwom souwce; wike evewyding ewse, you can instaww it nyow wid a MSYS2 package.

4~ Instaww Qt5

    ```
    pacman -S mingw-w64-x86_64-qt5
    ```

    Dewe is nyo mowe nyeed to downwoad some speciaw instawwew fwom de Qt website, de standawd MSYS2 package fow Qt wiww do in awmost aww ciwcumstances.

5~ Instaww git

    ```
    pacman -S git
    ```

6~ Cwonye wepositowy

    ```
    git clone --recursive https://github.com/monero-project/monero-gui.git
    cd monero-gui
    ```

7~ Buiwd

    ```
    make release-win64 -j4
    cd build/release
    make deploy
    ```
    \* `4` - nyumbew of CPU dweads to use

De executabwe can be found in de `.\bin` diwectowy.
