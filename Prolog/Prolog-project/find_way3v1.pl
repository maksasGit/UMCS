door(salon, kuchnia).
door(salon, oranzeria).
door(kuchnia, korytarz).
door(kuchnia, sypialnia).
door(korytarz, piwnica).
door(ubikacja, piwnica).
door(korytarz, ubikacja).
door(oranzeria, lazienka).

klucz(salon,klucz_duzy).
klucz(salon,klucz_wielki).
klucz(oranzeria,klucz_maly).
klucz(korytarz,klucz_z_sercem).

otwiera(ubikacja,klucz_maly).
otwiera(oranzeria,klucz_z_sercem).

exit(Room):- otwiera(Room,_).
noexit(Room):- \+otwiera(Room,_).
%---------------------------------------------------
key_checker(Current, Keys) :-
    findall(Key, klucz(Current, Key), Keys),
    print_keys(Keys).

print_keys([]).
print_keys([Key|Keys]) :-
    format("[znalazlem klucz ~w]~n", [Key]),
    print_keys(Keys).
%---------------------------------------------------
dfs(Start) :-
  dfs_helper(Start, [Start], []).

dfs_helper(Exit, Visited, Keys) :-
  exit(Exit),
  write('[znalazlem wyjscie]'), nl,write(Visited),nl,write(Keys).

dfs_helper(Current, Visited, Keys) :-
  (door(Current, Next) ; door(Next, Current)),
  \+member(Next, Visited),
  (noexit(Next);otwiera(Next,Need_key),member(Need_key,Keys)),
   key_checker(Current,Find),
   write('[przechodze z '), write(Current), write(' do '), write(Next), write(']'), nl,
   dfs_helper(Next, [Next|Visited],[Find|Keys]).

dfs_helper(Current, Visited, Keys) :-
  write("[wychodze z "), write(Current), write("]"), nl,
  fail. 
