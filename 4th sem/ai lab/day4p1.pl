member(X, [X|_]).
member(X, [_|Tail]):- member(X,Tail).

vowel(X):- member(X, ['a','e','i','o','u','A','E','I','O','U']).

symbol(X):- member(X, ['!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+']).

octal(X):- member(X, [0,1,2,3,4,5,6,7]).

hexadecimal(X):- member(X, [0,1,2,3,4,5,6,7,8,9,'A','B','C','D','E','F']).

binary(X):- member(X, [0,1]).

lengthlist([],0).
lengthlist([_|T],L):- lengthlist(T,L1), L is L1+1.

sumlist([H],H).
sumlist([H|T],Sum):- sumlist(T,Sum1), Sum is Sum1+H.

kthelem([X|_],1,X).
kthelem([_|T],K,N):- K1 is K-1, kthelem(T,K1,N).
