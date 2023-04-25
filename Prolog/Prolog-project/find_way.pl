drzwi(salon,kuchnia).
drzwi(salon,oranzeria).
drzwi(kuchnia,sypialnia).
drzwi(korytarz,piwnica).
drzwi(ubikacja,piwnica).
drzwi(korytarz,ubikacja).
drzwi(kuchnia,korytarz).
drzwi(oranzeria,lazienka).

wyjscie(ubiekacja).
wyjscie(oranzeria).


klucz(lazienka,klucz_duzy).
klucz(oranzeria,klucz_maly).
klucz(korytarz,klucz_z_sercem).

otwiera(ubikacja,klucz_maly).
otwiera(oranzeria,klucz_z_sercem).



find_way(Start,Path):-
    go(Start,NextDoor),
    