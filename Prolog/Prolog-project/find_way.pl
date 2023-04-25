door(salon, kuchnia).
door(salon, oranzeria).
door(kuchnia, sypialnia).
door(korytarz, piwnica).
door(ubikacja, piwnica).
door(korytarz, ubikacja).
door(kuchnia, korytarz).
door(oranzeria, lazienka).

exit(ubikacja).
exit(oranzeria).

go(X,Visited) :-
    exit(X),
    write('[znalazlem wyjscie]'), nl, !.

go(X, Visited) :-
    ((\+ door(X, Z), \+ door(Z, X)); member(Z, Visited)),
    write('[wychodze z '), write(X), write(']'), nl.

go(X,Visited):-
    ((door(X, Z);door(Z,X)),\+member(Z, Visited)),
    write('[przechodze z '), write(X), write(' do '), write(Z), write(']'), nl,
    go(Z, [Z|Visited]).