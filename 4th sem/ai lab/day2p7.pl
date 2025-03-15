var_y(X,Y):-
    Y is X*1+0.5, X<1;
    Y is X*1.2+0.5, X>1, X=<2;
    Y is X*1.4+0.5, X>2.