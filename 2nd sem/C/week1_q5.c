/*Write a program to swap the value of two variables, entered by the user. (Without using a 3rd Variable).*/
#include <stdio.h>

int main() {
  int a, b;

  printf("Enter two numbers to swap: ");
  scanf("%d %d", &a, &b);

  printf("Numbers before swapping: a = %d, b = %d\n", a, b);

  a = a + b;
  b = a - b;
  a = a - b;

  printf("Numbers after swapping: a = %d, b = %d\n", a, b);

  return 0;
}

/*
Output
Enter two numbers to swap: 10
1
Numbers before swapping: a = 10, b = 1
Numbers after swapping: a = 1, b = 10
*/