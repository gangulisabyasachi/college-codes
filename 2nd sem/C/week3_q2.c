/*Write a program to take the marks (out of hundred) of a particular student as an input
and print the corresponding grade as output based on the following rules:

i. Marks >= 90 --------- O
ii. 89>=Marks>=80 ------ E
iii. 79>=Marks>=70 ------ A
iv. 69>=Marks>=60 ------ B
v. 59>=Marks>=50 ------ C
vi. 49>=Marks>=40 ------ D
vii. 40>Marks ------ F*/
#include <stdio.h>

int main() {
    int marks;
    char grade;

    printf("Enter the marks (out of 100): ");
    scanf("%d", &marks);

    if (marks >= 90) {
        grade = 'O';
    } else if (marks >= 80) {
        grade = 'E';
    } else if (marks >= 70) {
        grade = 'A';
    } else if (marks >= 60) {
        grade = 'B';
    } else if (marks >= 50) {
        grade = 'C';
    } else if (marks >= 40) {
        grade = 'D';
    } else {
        grade = 'F';
    }

    printf("Grade: %c\n", grade);

    return 0;
}

/*
Output
Enter the marks (out of 100): 69
Grade: B
*/