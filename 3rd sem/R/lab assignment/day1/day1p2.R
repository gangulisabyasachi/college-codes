# Write a program to input a student's score in a subject (out of hundred) and print a grade as output as per the following rules:
# i. Marks >= 90 --------- O
# ii. 89>=Marks>=80 ------ E
# iii. 79>=Marks>=70 ------ A
# iv. 69>=Marks>=60 ------ B
# v. 59>=Marks>=50 ------ C
# vi. 49>=Marks>=40 ------ D
# vii. 40>Marks ------ F

x <- readline("Enter your score: ")

if (x > 90) {
    print("O")
} else if (x <= 89 && x >= 80) {
    print("E")
} else if (x <= 79 && x >= 70) {
    print("A")
} else if (x <= 69 && x >= 60) {
    print("B")
} else if (x <= 59 && x >= 50) {
    print("C")
} else if (x <= 49 && x >= 40) {
    print("D")
} else {
    print("F")
}

# Output
# Enter your score: 78
# [1] "A"
