get_curr(V,R,I):- I is V/R, R\=0.
get_ress(V,I,R):- R is V/I, I\=0.
get_volt(I,R,V):- V is I*R.