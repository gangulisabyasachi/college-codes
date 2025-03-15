max(X,Y,X):-X>Y.
max(X,Y,Y):-X<Y.
min(X,Y,X):-X<Y.
min(X,Y,Y):-X>Y.

max(X,Y,Z,X):- X>=Y, X>=Z.
max(X,Y,Z,Y):- Y>=X, Y>=Z.
max(X,Y,Z,Z):- Z>=Y, Z>=Y.

min(X,Y,Z,X):- X=<Y, X=<Z.
min(X,Y,Z,Y):- Y=<X, Y=<Z.
min(X,Y,Z,Z):- Z=<X, Z=<Y.
