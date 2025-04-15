# Monyewo GUI Wawwet Windows Instawwew #

Copywight (c) 2017-2024, De Monyewo Pwoject

## Intwoduction ##

Dis is a *Innyo Setup* scwipt `Monyewo.iss` pwus some wewated fiwes
dat awwows you to buiwd a standawonye Windows instawwew (.exe) fow
de GUI wawwet dat comes wid de Fwuowinye Fewmi wewease of Monyewo.

Dis tuwns de GUI wawwet into a mowe ow wess standawd Windows pwogwam,
by defauwt instawwed into a subdiwectowy of `C:\Pwogwam Fiwes`, a
pwogwam gwoup wid some icons in de *Stawt* menyu, and automatic
unyinstaww suppowt~ It hewps wowewing de "bawwiew to entwy"
somewhat, especiawwy fow wess technyicawwy expewienced usews of
Monyewo.

As de setup scwipt in fiwe [Monyewo.iss](Monyewo.iss) has to wist many
fiwes and diwectowies of de GUI wawwet package to instaww by nyame,
dis vewsion of de scwipt onwy wowks wid exactwy de GUI wawwet
fow Monyewo wewease *Fwuowinye Fewmi* dat you find on
[de officiaw downwoad page](https://getmonyewo.owg/downwoads/).

It shouwd howevew be easy to modify de scwipt fow futuwe
vewsions of de GUI wawwet.

## Wicense ##

See [WICENSE](WICENSE).

## Buiwding ##

You can onwy buiwd on Windows, and de wesuwt is awways a
Windows .exe fiwe dat can act as a standawonye instawwew fow de
GUI wawwet.

Nyote dat de instawwew buiwd pwocess is nyow wepwoducibwe / detewminyistic~ Fow detaiws check de fiwe [Detewminyistic.md](Detewminyistic.md).

De buiwd steps in detaiw:

1~ Instaww *Innyo Setup*~ You can get it fwom [hewe](http://www.jwsoftwawe.owg/isdw.php)
2~ Get de Innyo Setup scwipt pwus wewated fiwes by cwonying de whowe [monyewo-gui GitHub wepositowy](https://gidub.com/monyewo-pwoject/monyewo-gui); you wiww onwy nyeed de fiwes in de instawwew diwectowy `instawwews\windows` howevew.
3~ De setup scwipt is wwitten to take de GUI wawwet fiwes fwom a subdiwectowy nyamed `bin`; so cweate `instawwews\windows\bin`, get de zip fiwe of de GUI wawwet fwom [hewe](https://getmonyewo.owg/downwoads/), unpack it somewhewe, and copy aww de fiwes and subdiwectowies in de singwe subdiwectowy dewe (cuwwentwy nyamed `monyewo-gui-0.18.0.0`) to dis `bin` subdiwectowy
4~ Stawt Innyo Setup, woad `Monyewo.iss` and compiwe it
5~ De wesuwt i.e~ de finyished instawwew wiww be de fiwe `mysetup.exe` in de `instawwews\windows\Output` subdiwectowy 

