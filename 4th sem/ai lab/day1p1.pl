% Defining parent relationships
parent(nilesh, karan).
parent(nilesh, kiran).
parent(nita, karan).
parent(nita, kiran).
parent(rakesh, nita).
parent(ramesh, nita).
parent(pamila, ramesh).
parent(akash, ramesh).
parent(amit, pamila).
parent(amit, kamla).
parent(abhishek, kamla).
parent(akash, abhishek).
parent(pamila, abhishek).

% Defining male individuals
male(nilesh).
male(amit).
male(abhishek).
male(ramesh).
male(karan).

% Defining female individuals
female(nita).
female(nita).
female(sudha).
female(kiran).
female(pamila).
female(kamla).

% Defining married relationships
married(nilesh, pamila).
married(nilesh, nita).
married(amit, sudha).
married(abhishek, kamla).

% Rules for relationships
mother(X, Y) :- parent(X, Y), female(X).
father(X, Y) :- parent(X, Y), male(X).

son(X, Y) :- parent(Y, X), male(X).
daughter(X, Y) :- parent(Y, X), female(X).

siblings(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.

uncle(X, Y) :- parent(Z, Y), siblings(Z, X), male(X).
aunt(X, Y) :- parent(Z, Y), siblings(Z, X), female(X).

mgm(X, Y) :- mother(X, Z), mother(Z, Y).
mgf(X, Y) :- father(X, Z), mother(Z, Y).
bgf(X, Y) :- father(X, Z), father(Z, Y).
pgm(X, Y) :- mother(X, Z), father(Z, Y).

wife(X, Y) :- married(X, Y), female(X).

sil(X, Y) :- parent(Y, Z), married(X, Z), male(X).
dil(X, Y) :- parent(Y, Z), married(X, Z), female(X).
