door(salon, kuchnia).
door(salon, oranzeria).
door(kuchnia, korytarz).
door(kuchnia, sypialnia).
door(korytarz, piwnica).
door(ubikacja, piwnica).
door(korytarz, ubikacja).
door(oranzeria, lazienka).

exit(oranzeria).

go(X,Visited):-
    exit(X) ->  write('[znalazlem wyjscie]'), nl, !;
      ((door(X, Z);door(Z,X)),\+member(Z, Visited)) ->  
          write('[przechodze z '), write(X), write(' do '), write(Z), write(']'), nl, go(Z, [Z|Visited]);
    	  	write('[wychodze z '), write(X), write(']'), nl.

