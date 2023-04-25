door(salon, kuchnia).
door(salon, oranzeria).
door(kuchnia, korytarz).
door(kuchnia, sypialnia).
door(korytarz, piwnica).
door(ubikacja, piwnica).
door(korytarz, ubikacja).
door(oranzeria, lazienka).

exit(sypialnia).

dfs(Start, Path) :-
  dfs_helper(Start, [Start], Path).

dfs_helper(Exit, Visited, Path) :-
  exit(Exit),
  write('[znalazlem wyjscie]'), nl,
  reverse(Visited, Path).

dfs_helper(Current, Visited, Path) :-
  (door(Current, Next) ; door(Next, Current)),
  \+member(Next, Visited),
  write('[przechodze z '), write(Current), write(' do '), write(Next), write(']'), nl,
  dfs_helper(Next, [Next|Visited], Path).

dfs_helper(Current, Visited, Path) :-
  write("[wychodze z "), write(Current), write("]"), nl,
  fail. 
