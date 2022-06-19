# Koncept
Konceptem na gre był popularny w ostanim czasie gatunek rouge-like. Wzorowana była na grach typu the binding of issac, enter the gungeon, nuclear throne. Gracz miałby za zadanie dostać się do boss poziomu przez losowo generowany poziom i go pokonac, aby przejść do następnego etapu. Po drodzę gracz natrafiłby na pomniejszych wrogów, znajdzki typu dodatkowego życia czy pięniędzy. Ekspolrujac poziom można by również znaleśc pomieszczenia takie jak sklep, czy pokój z ulepszeniem. 

# Realizacja

### Proceduralnie generowane poziomy
Niestety przez brak czasu nie udało mi sie wyknoać tego co sobie założyłem. W pierwszym koncepcie poziom generowany miał być za pomocą algortmu walkera 
które wykorzystują najnowsze gry. Pozwala on tworzyć bardzo ciekawe poziomy. Niestety poziom skąplikowania i dos†epny czas mnie przewyższył. 
Z tego też powodu zmienił sie również koncept gry z typu otwartego na zamknięte przestrzenie, nazywane dalej pokojami. Gra miała przypominać grę the binding of issac.  

W celu generowania jednak poziomu stworzyłem algorytm procedularnie generowania poziomu. Cały poziom umieszczony został na planie siatki 8x8. W pierwszym kroku wybieramy miejsce gdzie będzie znajdował się punkt startowy poziomu ponieważ od niego dalej odprowadzamy kolejne odnogi. punkt startowy znajduje się zawsze na srodu naszej plany aby dalesze odnogi były nie przewidywalne. Jest on umieszczany zawsze w granicach x <3,4> i y <3,4>. Nastepnie wybierane jest położenie pokoju z Bossem. Jest on zawsze położony na którejś z band naszej przestrzeni, gwarantujemy sobie tym że będzie on w jakieś odległości od startu.
Następnie rysowna jest droga z miejsca startowego do pokoju z Bossem abysmy byli pewnie mozliwości ukończenia poziomu. Dokładana ścieżka jest również 
losowa, przyczym zawsze jest to droga optymalna. Następnie powtarzamy takie same czynności dla sklepu i pokoju z ulepszeniem. Położenie każdego z pokoi 
do których rysujemy droga jest nie kolidujące z pozostałymi. W taki sposób zapełniamy zmienna którą przechowuje wygląd mapy pomieszczeń. Jest to zwykła
tablica intów, która jest poźniej odczytywana i przypisywane są na tej podstawie położenia pomieszczeń. Dla 0 - jest to pomieszczenie puste gdzie nie toczy się rozgrywka, 1 - pomieszczenie z pomiejszymi wrogami które ma gdzieś nas zaprowadzić, 2 - miejsce startowe, 5 - sklep, 7 - pokój z ulepszeniem, 9 - Boss.

### Procedularne rysowanie poziomów

Rysowanie poszczególnych poziomów odbywa się po podczytaniu kodowania wizualnego , podobnie jak przy poziomach, z pomoca odczytywania tablicy intów 8x8. Każda klasa dziedzicąca po klasie Room posiada zapisane własne układy pomieszczeń, przy czym są to tablice trójwymiare intów, a rysowanie odbywa się w 
sposób procedularny według określnych reguł, więc możliwości zapisania różnych wyglądów pomieszczeń jest prawie nieskończoność. Odpowiednio dla wartości 
0 - rysowana jest przestrzeń niedstępna dla gracza, dla wartości 1-8 rysowane są różne wariacje podłogi. 9 - zejście do kolejnego poziomu, 10-12 wariacje ścian widziane od frontu, 13 sciana prawy górny róg, 14 - ściana lewy górny róg, 15 - lewa ściana, 16 - ściana lewy dolny róg, 17 - prawy dolny róg, 18 - prawa ściana, 19 - dolna śćiana, 20 - podest dla przedmiotów.

### Pozstałe elementy

Niestety na ten moment tylko tyle udało mi sie zawrzeć w grze z powodu braku czasu. Postaram się dokończyć projekt jak najszybciej , możliwe że dzisiaj jednak nie ukrywając jest obecnie sesja ,i czasu jest na wszystko bardzo mało. Opowiem więc chociaż co chciałbym jeszcze dodać i omówić z grubsza implementacje. 


### Bohater

Dalszym celem na pewno było by dodanie naszego bohatera. Poruszać możnaby się za pomoca strzałek lub W, A, S, D. Posiadałby on jedną z broni, które różniłby się głównie strzałami. 
Myszka stanowiła by wskaz dla kierunku naszych pocisków. Z wykorzystaniem poliformizmu i obiektowości można by dodatać na wybranych broniach strzał specialny aktywowany prawym przyciskiem myszy. 
W przypadku kiedy dla przykładu broń początkowa nie posiadała by możliwości strzału specialnego, wykorzytanie poliformizmu nie powodowałoby dzięki niemu problemu w kodzie i ułatwiło by implementacje. 
Niestety nie byłem wstanie utworzyć vectora dla klasy wirtualnej po którym dziedziczą pokoje, aby ułtawić implementacje generowania pomieszczeń i wykorzystać polimofrizm z powdów ograniczeń kompilatora i bezpieczeństwa pamięci. 
Wracajac do bohatera, jak każdy obiekt po klasie Postacie dziedziczyłbym on zdrowie, animacje i wykrywanie kolizji. Miałby on również statystyki które możnaby podnosić przy pomocy odpowiednich przedmiotów.

### Przeciwnicy 

Dziedziczyli by oni wartosci po klasie Postac jednoczesnie Utworzona by była nowa Klasa Enemies po której poszczególni wrogowie, możliwy by był dodatkowy podział na zwykłych wrogów i Bossów w celu łatwiejszej implementacji. 
W momemencie dotknięcia bohatera zadawali by oni odpowiednie obrażenia po których liczony byłby czas od poprzednich obrażeń aby unikać sytuacji w której nasz bohater może bardzo szybko zginąc. 
Nie którzy wrogowie moglby dodatkowo strzelać różnymi strzałami, np spowolniającymi. Po zabiciu kazdego z wrogów była by mała szansa na upuszczenie przez niego monetki lub też apteczki. Po zabiciu wszystkich przeciwników na planszy, otwierały by się odpowiednie przejścia do kolejnych pokoi. 
Gracza ograniczały by ściany, po pokonaniu wszystkich na danej planszy odpwoiednie przejćia otwierałyby się, umożliwiając przejście do dalszych pokoi. Dotknięcie krawędzi ekranu przez bohatera było by dla nas sygnałem że pragnie przejść dalej i kierunek jego przejścia byłby wnioskowany na podstawie dotknięcia odpowiedniej krawędzi ekranu. 
Po przejściu dalej odpowiedni poziom rysowałby się od nowa, a ściany zamykały na czas życia przeciwnków. 

### Sklep 

Gracz miałby również kupienia chcoiażby dodatkowe leczenie za zbierane podczas rozgrywki monetki. Ceny mogłby być losowane w ramach jakiegos przedialu cenowego. 


### Item room 

Każdy poziom miałby specialne pomieszczenie, które zawierałoby jakaś broń lub znaczne ulepszenie statystyk bohatera. 


