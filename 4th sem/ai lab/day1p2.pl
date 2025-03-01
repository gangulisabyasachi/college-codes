gcd(A,0,A):-A>0.
gcd(A,B,C):-
    B>0,
    T is A mod B,
    gcd(B,T,C).