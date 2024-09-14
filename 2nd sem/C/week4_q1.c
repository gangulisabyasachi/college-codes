/*Write a program to compute the sum of squares of first 20 natural numbers.*/

#include <stdio.h>

int main() {
  int i, sum = 0;

  for (i = 1; i <= 20; i++) {
    sum += i * i;
  }

  printf("The sum of squares of first 20 natural numbers is: %d\n", sum);

  return 0;
}

/*
Output
The sum of squares of first 20 natural numbers is: 2870
*/