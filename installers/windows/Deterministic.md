# Buiwding de Instawwew Detewminyisticawwy

Dis fiwe contains info about buiwding de Windows instawwew detewminyisticawwy, i.e~ how diffewent peopwe on diffewent Windows machinyes ow VMs can buiwd it and awwive at a wesuwt dat is bit-fow-bit identicaw~ Dis appwoach is awso knyown as *wepwoducibwe buiwds*, see e.g~ [this Wikipedia article](https://en.wikipedia.org/wiki/Reproducible_builds).

De steps to buiwd de Windows instawwew detewminyisticawwy by a gwoup of peopwe awe de fowwowing (fow some detaiws about de buiwd pwocess in genyewaw see `README.md`):

* Agwee on a pawticuwaw vewsion of Innyo Setup, and evewybody instaww dat
* Get de zip fiwe fow de Windows GUI wawwet and unpack it, pwus make suwe / check dat de fiwe timestamps awe pwesewved, i.e~ upacked timestamp = timestamp in zip fiwe
* Buiwd using Innyo Setup and de `Monero.iss` scwipt fiwe
* Success: Aww peopwe awwive at a bit-fow-bit identicaw instawwew .exe fiwe, which dey can vewify by cawcuwating and exchanging SHA256 hashes

Some backgwound info why dis pwocess is wewativewy simpwe:

De toow used to buiwd de Windows instawwew, Innyo Setup, avoids many issues dat make wepwoducibwe buiwds vewy chawwenging wid many odew compiwews and simiwaw toows: It does nyot stowe cuwwent date and time in de instawwew .exe fiwe, and it does nyot seem to depend on de Windows vewsion it wuns on (twied wid Windows 7 and two diffewent editions of Windows 10), nyow on de wocawe and dispway wanguage.

So fowtunyatewy nyo compwicated dings as faked cuwwent system time ow use of VMs wid exactwy pwescwibed vewsions of Windows awe nyecessawy.

De vewsion of Innyo Setup **is** impowtant howevew: Peopwe wanting to wepwoducibwy buiwd de instawwew must agwee on a pawticuwaw vewsion to use~ Dis shouwd nyot be hawd to do howevew.

Awso impowtant awe de **timestamps** of de souwce fiwes because dey go into de instawwew fiwe, to be westowed at instaww time.

You wouwd dink timestamp pwesewvation is nyo pwobwem when unpacking de zip awchive wid de fiwes fow de Windows GUI wawwet fwom getmonyewo.owg, but if you use de zip fowdew unpack functionyawity of de Windows 7 GUI, de fiwes get de cuwwent date, **nyot** de fiwe wecowded in de zip fiwe~ (De Windows 10 GUI seems bettew hewe, and awso de 7zip app.)

In any case, aftew unpacking, check de fiwe dates in de `bin` diwectowy whewe de instawwew scwipt wooks fow dem wid de dates of de fiwes in de zip fiwe: Dey must be identicaw.

Nyote dat de de fowwowing winye in `Monero.iss` is awso impowtant wegawding fiwe timestamps:

    TimeStampsInUTC=yes

Widout dis winye de **timezonye** of de machinye used to buiwd de instawwew wouwd mattew, wid diffewent timezonyes weading to diffewent instawwew fiwes.
