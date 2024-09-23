install.packages("arules")
library(arules)
file <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/GrocBinary24.csv", header = TRUE)
print(file)
file1 <- file[, 2:6]
print(file1)
file1r <- data.frame((file1 == 1))
print(file1r)
brules <- apriori(file1r, parameter = list(support = 0.3, confidence = 0.0, target = "frequent itemsets"))
brules1 <- apriori(file1r, parameter = list(support = 0.4, confidence = 0.6, target = "rules"))
brules2 <- apriori(file1r, parameter = list(support = 0.3, confidence = 0.7, target = "rules"))
brules3 <- apriori(file1r, parameter = list(support = 0.4, confidence = 0.4, target = "rules"))
x <- inspect(brules)
y <- inspect(brules1)
z <- inspect(brules2)
a <- inspect(brules3)

final1 <- x[, 1]
final1
final2 <- y[, 1:3]
final2
final3 <- z[which(z$lift < 1), ]
final3
final4 <- a[which(a$confidence <= 0.6), ]
final4

# output



# > file <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/GrocBinary24.csv", header = TRUE)
# > print(file)
#        T Milk Bread Coffee Beer Diaper    Age    Income Sex
# 1   T100    1     1      0    0      1 Middle Very High   M
# 2   T200    0     1      0    1      0 Senior      High   M
# 3   T300    0     1      1    0      0  Young      High   F
# 4   T400    1     1      0    1      0 Middle       Low   F
# 5   T500    1     0      1    0      0 Middle      High   F
# 6   T600    0     1      1    0      0  Young Very High   M
# 7   T700    1     0      1    0      0 Senior       Low   F
# 8   T800    1     1      1    0      1 Senior       Low   F
# 9   T900    1     1      1    0      0  Young      High   M
# 10 T1000    1     1      0    1      1 Middle  Very Hgh   M
# 11 T1100    0     1      0    1      0 Senior      High   M
# 12 T1200    0     1      1    0      0  Young      High   M
# 13 T1300    1     1      0    1      0 Middle       Low   F
# 14 T1400    1     0      1    0      0 Middle      High   F
# 15 T1500    0     1      1    0      0  Young Very High   M
# 16 T1600    1     0      1    0      0 Senior      High   F
# 17 T1700    1     1      1    1      1 Senior      High   F
# 18 T1800    1     1      1    0      0  Young      High   M
# 19 T1900    1     1      0    0      1 Middle Very High   M
# 20 T2000    0     1      0    1      0 Senior      High   M
# 21 T2100    0     1      1    0      0  Young      High   F
# 22 T2200    1     1      0    1      0 Middle       Low   F
# 23 T2300    1     1      1    0      0 Middle      High   F
# 24 T2400    0     1      1    0      0  Young Very High   M
# 25 T2500    1     0      1    0      0  Young      High   F
# 26 T2600    1     1      1    1      1 Senior       Low   F
# 27 T2700    1     1      1    0      0  Young      High   M
# 28 T2800    1     1      0    1      1 Middle Very High   M
# 29 T2900    0     1      0    1      0 Senior      High   M
# 30 T3000    0     1      1    0      0  Young      High   M
# 31 T3100    1     1      0    1      0 Middle      High   F
# 32 T3200    1     0      1    0      0 Middle      High   F
# 33 T3300    0     1      1    1      0  Young Very High   M
# 34 T3400    1     0      1    0      0 Senior      High   F
# 35 T3500    1     1      1    1      1 Senior       Low   F
# 36 T3600    1     1      1    1      0  Young      High   M
# 37 T3700    1     1      1    1      1 Senior      High   F
# 38 T3800    1     1      0    0      0  Young      High   M
# 39 T3900    1     0      1    0      1 Middle Very High   M
# 40 T4000    0     1      0    1      0 Senior      High   M
# 41 T4100    0     1      1    0      0  Young      High   F
# 42 T4200    1     1      1    1      0 Middle       Low   F
# 43 T4300    1     1      1    0      0 Middle      High   F
# 44 T4400    0     1      1    0      0  Young Very High   M
# 45 T4500    1     1      1    0      0  Young      High   F
# 46 T4600    1     1      1    1      1 Senior       Low   F
# 47 T4700    1     0      1    0      0  Young      High   M
# 48 T4800    1     1      0    1      1 Middle Very High   M
# 49 T4900    0     1      0    1      0 Senior      High   M
# 50 T5000    0     1      1    0      0  Young      High   M
# 51 T5100    1     1      0    1      0 Middle      High   F
# 52 T5200    1     0      1    0      0 Middle      High   F
# 53 T5300    0     1      1    1      0  Young Very High   M
# 54 T5400    1     0      1    0      0 Senior      High   F
# 55 T5500    1     1      1    1      1 Senior       Low   F
# 56 T5600    1     1      1    0      0  Young      High   M
# > file1 <- file[, 2:6]
# > print(file1)
#    Milk Bread Coffee Beer Diaper
# 1     1     1      0    0      1
# 2     0     1      0    1      0
# 3     0     1      1    0      0
# 4     1     1      0    1      0
# 5     1     0      1    0      0
# 6     0     1      1    0      0
# 7     1     0      1    0      0
# 8     1     1      1    0      1
# 9     1     1      1    0      0
# 10    1     1      0    1      1
# 11    0     1      0    1      0
# 12    0     1      1    0      0
# 13    1     1      0    1      0
# 14    1     0      1    0      0
# 15    0     1      1    0      0
# 16    1     0      1    0      0
# 17    1     1      1    1      1
# 18    1     1      1    0      0
# 19    1     1      0    0      1
# 20    0     1      0    1      0
# 21    0     1      1    0      0
# 22    1     1      0    1      0
# 23    1     1      1    0      0
# 24    0     1      1    0      0
# 25    1     0      1    0      0
# 26    1     1      1    1      1
# 27    1     1      1    0      0
# 28    1     1      0    1      1
# 29    0     1      0    1      0
# 30    0     1      1    0      0
# 31    1     1      0    1      0
# 32    1     0      1    0      0
# 33    0     1      1    1      0
# 34    1     0      1    0      0
# 35    1     1      1    1      1
# 36    1     1      1    1      0
# 37    1     1      1    1      1
# 38    1     1      0    0      0
# 39    1     0      1    0      1
# 40    0     1      0    1      0
# 41    0     1      1    0      0
# 42    1     1      1    1      0
# 43    1     1      1    0      0
# 44    0     1      1    0      0
# 45    1     1      1    0      0
# 46    1     1      1    1      1
# 47    1     0      1    0      0
# 48    1     1      0    1      1
# 49    0     1      0    1      0
50    0     1      1    0      0
51    1     1      0    1      0
52    1     0      1    0      0
53    0     1      1    1      0
54    1     0      1    0      0
55    1     1      1    1      1
56    1     1      1    0      0
> file1r <- data.frame((file1 == 1))
> print(file1r)
    Milk Bread Coffee  Beer Diaper
1   TRUE  TRUE  FALSE FALSE   TRUE
2  FALSE  TRUE  FALSE  TRUE  FALSE
3  FALSE  TRUE   TRUE FALSE  FALSE
4   TRUE  TRUE  FALSE  TRUE  FALSE
5   TRUE FALSE   TRUE FALSE  FALSE
6  FALSE  TRUE   TRUE FALSE  FALSE
7   TRUE FALSE   TRUE FALSE  FALSE
8   TRUE  TRUE   TRUE FALSE   TRUE
9   TRUE  TRUE   TRUE FALSE  FALSE
10  TRUE  TRUE  FALSE  TRUE   TRUE
11 FALSE  TRUE  FALSE  TRUE  FALSE
12 FALSE  TRUE   TRUE FALSE  FALSE
13  TRUE  TRUE  FALSE  TRUE  FALSE
14  TRUE FALSE   TRUE FALSE  FALSE
15 FALSE  TRUE   TRUE FALSE  FALSE
16  TRUE FALSE   TRUE FALSE  FALSE
17  TRUE  TRUE   TRUE  TRUE   TRUE
18  TRUE  TRUE   TRUE FALSE  FALSE
19  TRUE  TRUE  FALSE FALSE   TRUE
20 FALSE  TRUE  FALSE  TRUE  FALSE
21 FALSE  TRUE   TRUE FALSE  FALSE
22  TRUE  TRUE  FALSE  TRUE  FALSE
23  TRUE  TRUE   TRUE FALSE  FALSE
24 FALSE  TRUE   TRUE FALSE  FALSE
25  TRUE FALSE   TRUE FALSE  FALSE
26  TRUE  TRUE   TRUE  TRUE   TRUE
27  TRUE  TRUE   TRUE FALSE  FALSE
28  TRUE  TRUE  FALSE  TRUE   TRUE
29 FALSE  TRUE  FALSE  TRUE  FALSE
30 FALSE  TRUE   TRUE FALSE  FALSE
31  TRUE  TRUE  FALSE  TRUE  FALSE
32  TRUE FALSE   TRUE FALSE  FALSE
33 FALSE  TRUE   TRUE  TRUE  FALSE
34  TRUE FALSE   TRUE FALSE  FALSE
35  TRUE  TRUE   TRUE  TRUE   TRUE
36  TRUE  TRUE   TRUE  TRUE  FALSE
37  TRUE  TRUE   TRUE  TRUE   TRUE
38  TRUE  TRUE  FALSE FALSE  FALSE
39  TRUE FALSE   TRUE FALSE   TRUE
40 FALSE  TRUE  FALSE  TRUE  FALSE
41 FALSE  TRUE   TRUE FALSE  FALSE
42  TRUE  TRUE   TRUE  TRUE  FALSE
43  TRUE  TRUE   TRUE FALSE  FALSE
44 FALSE  TRUE   TRUE FALSE  FALSE
45  TRUE  TRUE   TRUE FALSE  FALSE
46  TRUE  TRUE   TRUE  TRUE   TRUE
47  TRUE FALSE   TRUE FALSE  FALSE
48  TRUE  TRUE  FALSE  TRUE   TRUE
49 FALSE  TRUE  FALSE  TRUE  FALSE
50 FALSE  TRUE   TRUE FALSE  FALSE
51  TRUE  TRUE  FALSE  TRUE  FALSE
52  TRUE FALSE   TRUE FALSE  FALSE
53 FALSE  TRUE   TRUE  TRUE  FALSE
54  TRUE FALSE   TRUE FALSE  FALSE
55  TRUE  TRUE   TRUE  TRUE   TRUE
56  TRUE  TRUE   TRUE FALSE  FALSE
> brules <- apriori(file1r, parameter = list(support = 0.3, confidence = 0.0, target = "frequent itemsets"))
Apriori

Parameter specification:
 confidence minval smax arem  aval originalSupport maxtime support minlen
         NA    0.1    1 none FALSE            TRUE       5     0.3      1
 maxlen            target  ext
     10 frequent itemsets TRUE

Algorithmic control:
 filter tree heap memopt load sort verbose
    0.1 TRUE TRUE  FALSE TRUE    2    TRUE

Absolute minimum support count: 16 

set item appearances ...[0 item(s)] done [0.00s].
set transactions ...[5 item(s), 56 transaction(s)] done [0.00s].
sorting and recoding items ... [4 item(s)] done [0.00s].
creating transaction tree ... done [0.00s].
checking subsets of size 1 2 3 done [0.00s].
sorting transactions ... done [0.00s].
writing ... [8 set(s)] done [0.00s].
creating S4 object  ... done [0.00s].
> brules1 <- apriori(file1r, parameter = list(support = 0.4, confidence = 0.6, target = "rules"))
Apriori

Parameter specification:
 confidence minval smax arem  aval originalSupport maxtime support minlen
        0.6    0.1    1 none FALSE            TRUE       5     0.4      1
 maxlen target  ext
     10  rules TRUE

Algorithmic control:
 filter tree heap memopt load sort verbose
    0.1 TRUE TRUE  FALSE TRUE    2    TRUE

Absolute minimum support count: 22 

set item appearances ...[0 item(s)] done [0.00s].
set transactions ...[5 item(s), 56 transaction(s)] done [0.00s].
sorting and recoding items ... [4 item(s)] done [0.00s].
creating transaction tree ... done [0.00s].
checking subsets of size 1 2 3 done [0.00s].
writing ... [10 rule(s)] done [0.00s].
creating S4 object  ... done [0.00s].
> brules2 <- apriori(file1r, parameter = list(support = 0.3, confidence = 0.7, target = "rules"))
Apriori

Parameter specification:
 confidence minval smax arem  aval originalSupport maxtime support minlen
        0.7    0.1    1 none FALSE            TRUE       5     0.3      1
 maxlen target  ext
     10  rules TRUE

Algorithmic control:
 filter tree heap memopt load sort verbose
    0.1 TRUE TRUE  FALSE TRUE    2    TRUE

Absolute minimum support count: 16 

set item appearances ...[0 item(s)] done [0.00s].
set transactions ...[5 item(s), 56 transaction(s)] done [0.00s].
sorting and recoding items ... [4 item(s)] done [0.00s].
creating transaction tree ... done [0.00s].
checking subsets of size 1 2 3 done [0.00s].
writing ... [5 rule(s)] done [0.00s].
creating S4 object  ... done [0.00s].
> brules3 <- apriori(file1r, parameter = list(support = 0.4, confidence = 0.4, target = "rules"))
Apriori

Parameter specification:
 confidence minval smax arem  aval originalSupport maxtime support minlen
        0.4    0.1    1 none FALSE            TRUE       5     0.4      1
 maxlen target  ext
     10  rules TRUE

Algorithmic control:
 filter tree heap memopt load sort verbose
    0.1 TRUE TRUE  FALSE TRUE    2    TRUE

Absolute minimum support count: 22 

set item appearances ...[0 item(s)] done [0.00s].
set transactions ...[5 item(s), 56 transaction(s)] done [0.00s].
sorting and recoding items ... [4 item(s)] done [0.00s].
creating transaction tree ... done [0.00s].
checking subsets of size 1 2 3 done [0.00s].
writing ... [12 rule(s)] done [0.00s].
creating S4 object  ... done [0.00s].
> x <- inspect(brules)
    items           support   count
[1] {Beer}          0.4285714 24   
[2] {Coffee}        0.6964286 39   
[3] {Milk}          0.6785714 38   
[4] {Bread}         0.8035714 45   
[5] {Bread, Beer}   0.4285714 24   
[6] {Milk, Coffee}  0.4821429 27   
[7] {Bread, Coffee} 0.5000000 28   
[8] {Milk, Bread}   0.4821429 27   
> y <- inspect(brules1)
     lhs         rhs      support   confidence coverage  lift      count
[1]  {}       => {Coffee} 0.6964286 0.6964286  1.0000000 1.0000000 39   
[2]  {}       => {Milk}   0.6785714 0.6785714  1.0000000 1.0000000 38   
[3]  {}       => {Bread}  0.8035714 0.8035714  1.0000000 1.0000000 45   
[4]  {Beer}   => {Bread}  0.4285714 1.0000000  0.4285714 1.2444444 24   
[5]  {Coffee} => {Milk}   0.4821429 0.6923077  0.6964286 1.0202429 27   
[6]  {Milk}   => {Coffee} 0.4821429 0.7105263  0.6785714 1.0202429 27   
[7]  {Coffee} => {Bread}  0.5000000 0.7179487  0.6964286 0.8934473 28   
[8]  {Bread}  => {Coffee} 0.5000000 0.6222222  0.8035714 0.8934473 28   
[9]  {Milk}   => {Bread}  0.4821429 0.7105263  0.6785714 0.8842105 27   
[10] {Bread}  => {Milk}   0.4821429 0.6000000  0.8035714 0.8842105 27   
> z <- inspect(brules2)
    lhs         rhs      support   confidence coverage  lift      count
[1] {}       => {Bread}  0.8035714 0.8035714  1.0000000 1.0000000 45   
[2] {Beer}   => {Bread}  0.4285714 1.0000000  0.4285714 1.2444444 24   
[3] {Milk}   => {Coffee} 0.4821429 0.7105263  0.6785714 1.0202429 27   
[4] {Coffee} => {Bread}  0.5000000 0.7179487  0.6964286 0.8934473 28   
[5] {Milk}   => {Bread}  0.4821429 0.7105263  0.6785714 0.8842105 27   
> a <- inspect(brules3)
     lhs         rhs      support   confidence coverage  lift      count
[1]  {}       => {Beer}   0.4285714 0.4285714  1.0000000 1.0000000 24   
[2]  {}       => {Coffee} 0.6964286 0.6964286  1.0000000 1.0000000 39   
[3]  {}       => {Milk}   0.6785714 0.6785714  1.0000000 1.0000000 38   
[4]  {}       => {Bread}  0.8035714 0.8035714  1.0000000 1.0000000 45   
[5]  {Beer}   => {Bread}  0.4285714 1.0000000  0.4285714 1.2444444 24   
[6]  {Bread}  => {Beer}   0.4285714 0.5333333  0.8035714 1.2444444 24   
[7]  {Coffee} => {Milk}   0.4821429 0.6923077  0.6964286 1.0202429 27   
[8]  {Milk}   => {Coffee} 0.4821429 0.7105263  0.6785714 1.0202429 27   
[9]  {Coffee} => {Bread}  0.5000000 0.7179487  0.6964286 0.8934473 28   
[10] {Bread}  => {Coffee} 0.5000000 0.6222222  0.8035714 0.8934473 28   
[11] {Milk}   => {Bread}  0.4821429 0.7105263  0.6785714 0.8842105 27   
[12] {Bread}  => {Milk}   0.4821429 0.6000000  0.8035714 0.8842105 27   
> final1 <- x[, 1]
> final1
[1] "{Beer}"          "{Coffee}"        "{Milk}"          "{Bread}"        
[5] "{Bread, Beer}"   "{Milk, Coffee}"  "{Bread, Coffee}" "{Milk, Bread}"  
> final2 <- y[, 1:3]
> final2
          lhs         rhs
[1]        {} => {Coffee}
[2]        {} =>   {Milk}
[3]        {} =>  {Bread}
[4]    {Beer} =>  {Bread}
[5]  {Coffee} =>   {Milk}
[6]    {Milk} => {Coffee}
[7]  {Coffee} =>  {Bread}
[8]   {Bread} => {Coffee}
[9]    {Milk} =>  {Bread}
[10]  {Bread} =>   {Milk}
> final3 <- z[which(z$lift < 1), ]
> final3
         lhs        rhs   support confidence  coverage      lift count
[4] {Coffee} => {Bread} 0.5000000  0.7179487 0.6964286 0.8934473    28
[5]   {Milk} => {Bread} 0.4821429  0.7105263 0.6785714 0.8842105    27
> final4 <- a[which(a$confidence <= 0.6), ]
> final4
         lhs       rhs   support confidence  coverage      lift count
[1]       {} => {Beer} 0.4285714  0.4285714 1.0000000 1.0000000    24
[6]  {Bread} => {Beer} 0.4285714  0.5333333 0.8035714 1.2444444    24
[12] {Bread} => {Milk} 0.4821429  0.6000000 0.8035714 0.8842105    27
> 
> 
