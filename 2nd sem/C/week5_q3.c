/*Write an iterative program to find factorial of a single digit number.*/

#include <stdio.h>

int factorial(int n) {
  int fact = 1;
  for (int i = 1; i <= n; i++) {
    fact *= i;
  }
  return fact;
}

int main() {
  int n;
  printf("Enter a single digit number: ");
  scanf("%d", &n);
  printf("The factorial of %d is %d\n", n, factorial(n));
  return 0;
}

/*
Output
Enter a single digit number: 5
The factorial of 5 is 120
*/
