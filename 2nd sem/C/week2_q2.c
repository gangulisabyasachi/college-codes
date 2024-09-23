//Write a program to find out the maximum of given two numbers.

#include <stdio.h>

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    if(num1 > num2) {
        printf("Maximum number is %d\n", num1);
    } else {
        printf("Maximum number is %d\n", num2);
    }

    return 0;
}

/*
Output
Enter two numbers: 5
6
Maximum number is 6
*/