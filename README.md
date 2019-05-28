### 2 užduotis

## Duomenų apdorojimas

### Kaip susikompiliuoti?

Parsisiunčiant programos versiją (senesnė negu v0.3) pakanka konsolėje, kuri buvo atidaryta failų aplanke (naudojant Windows OS) ir įvesti "g++ main.cpp -o main; .\main". Norint sukompiliuoti naujesnę versiją naudojame "g++ main.cpp funkcijos.cpp -o main; .\main".  

### Changelog

# [v1.0.1]()

**Pakeitimai**
* Pridėtas CMakeLists.txt failas.
* Sutvarkytas galutinai kodas, kad galėtų būti atliekami testavimai.

# [v1.0](https://github.com/grovcat/2-uzduotis/releases/tag/v1.0)

**Pakeitimai**
* Atlikti bandymai su dviem skirtingomis strategijomis:
  * Skaidant duomenis į 2 skirtingus konteinerius.
  * Sukuriant vieną naują konteinerį ir ištrinant nereikalingus duomenis iš originalo.
  
**Testavimas**

![Testo rezultatai](https://i.imgur.com/HkBUQOp.png)

Kaip ir tikėjausi atlikdamas v0.5 versijos testavimą, mano kodas nebuvo paruoštas naudoti std::vector. Tačiau pasitelkiant bet kurią iš šių strategijų pastebime, kad std::vector atlieka darbą greičiausiai. Žinant, kad std::list ir std::vector iš esmės yra tas pats konteineris, tačiau atlieka savo darbą skirtingai, std::list rezultatai manes daug nenustebino. std::deque rezultatai parodė, kad kurimas naujų struktūrų, bei ištrinimas kainuoja labai daug laiko lyginant su kitais konteineriais.

# [v0.5](https://github.com/grovcat/2-uzduotis/releases/tag/v0.5)

**Pakeitimai**
* Pridėti 2 konteineriai: list ir deque.
* Galimybė parsisiųsti kitus konteinerius naudojant skirtingus branch'us.

**Testavimas**

![Testo rezultatai](https://i.imgur.com/JdO8UZj.png)

Testavimas parodė, kad visiškai neoptimiziuojant kodo std::list atlieka darbą greičiausiai, tačiau tam prireikė daugiausia laiko perrašyti iš std::vector konteinerio. Tačiau, std::vector nedaug atsilieka spartumu. Aš manau, kad mano dabartinis kodas nėra tiek optimizutuojas dirbti su vektoriais kaip galėtų būti.

# [v0.4](https://github.com/grovcat/2-uzduotis/releases/tag/v0.4)

**Pakeitimai**
* Pridėta galimybė sukurti duomenų failą
* Rezultatas spausdinamas į 2 skirtingus failus

# [v0.3](https://github.com/grovcat/2-uzduotis/releases/tag/v0.3)

**Pakeitimai**
* Pridėtas "Exception handling" duomenų failui.
* Sukurtas naujas .cpp failas funkcijoms
* Sukurtas header failas, kuriame saugomas struct ir naudojamos bibliotekos

# [v0.2](https://github.com/grovcat/2-uzduotis/releases/tag/v0.2)

**Pakeitimai**
* Pridėta galimybė naudoti .txt failą kaip duomenų šaltinį.

# [v0.1.1](https://github.com/grovcat/2-uzduotis/releases/tag/v0.1.1)

**Pakeitimai**
* Pridėta galimybė generuoti pažymius

# [v0.1](https://github.com/grovcat/2-uzduotis/releases/tag/v0%2C1)

**Pakeitimai**
* Įkelta pirmoji programos versija.
* Galimybė apskaičiuoti vidurkį ir medianą.
* Rezultatas išspausdinamas konsolėje.
