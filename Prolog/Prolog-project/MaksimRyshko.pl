drzwi(salon,kuchnia).
drzwi(salon,oranzeria).
drzwi(kuchnia,sypialnia).
drzwi(korytarz,piwnica).
drzwi(ubikacja,piwnica).
drzwi(korytarz,ubikacja).
drzwi(kuchnia,korytarz).
drzwi(oranzeria,lazienka).

klucz(salon,klucz_duzy).
klucz(oranzeria,klucz_maly).
klucz(korytarz,klucz_z_sercem).

otwiera(ubikacja,klucz_maly).
otwiera(oranzeria,klucz_z_sercem).
%--------------------------------------------------
 
exit(Room):- otwiera(Room,_).
noexit(Room):- \+otwiera(Room,_).

%---------------------------------------------------

:- dynamic(have_keys/1).

add_to_list(X) :-
  assertz(have_keys(X)).

print_list :-
  have_keys(List),
  write(List), nl.

%---------------------------------------------------

key_checker(Current) :-
    findall(Key, klucz(Current, Key), Keys),
    print_keys(Keys),
    add_to_list(Keys).

print_keys([]).
print_keys([Key|Keys]) :-
    write("[znalazlem_klucz, "),write(Key),write("]"),nl,
    print_keys(Keys).

%---------------------------------------------------

szukaj_wyjscia(Start,Gdzie_klucz,Wlasciwy_klucz,Gdzie_wyjscie) :-
  dfs_helper(Start, [Start],Gdzie_klucz,Wlasciwy_klucz,Gdzie_wyjscie).

dfs_helper(Exit, Visited,Gdzie_klucz,Wlasciwy_klucz,Gdzie_wyjscie) :-
  exit(Exit),Gdzie_wyjscie=Exit,otwiera(Exit,Wlasciwy_klucz),klucz(Gdzie_klucz,Wlasciwy_klucz),
  write('[znalazlem_wyjscie]').

dfs_helper(Current, Visited,Gdzie_klucz,Wlasciwy_klucz,Gdzie_wyjscie) :-
  (drzwi(Current, Next) ; drzwi(Next, Current)),
  \+member(Next, Visited),
  (noexit(Next);otwiera(Next,Need_key),have_keys(List),member(Need_key,List)),
   key_checker(Current),
   write('[przechodze_z, '), write(Current), write(', do, '), write(Next), write(']'), nl,
   dfs_helper(Next, [Next|Visited],Gdzie_klucz,Wlasciwy_klucz,Gdzie_wyjscie).

dfs_helper(Current, Visited,Gdzie_klucz,Wlasciwy_klucz,Gdzie_wyjscie) :-
  write("[wychodze_z, "), write(Current), write("]"), nl,
  fail. 
