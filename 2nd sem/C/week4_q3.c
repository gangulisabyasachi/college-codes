/*Write a program to print the first N Fibonacci numbers, where N is taken as
 * input.*/

#include <stdio.h>

int main() {
  int n, first = 0, second = 1, next;

  printf("Enter the number of Fibonacci numbers: ");
  scanf("%d", &n);

  printf("First %d Fibonacci numbers:\n", n);

  for (int i = 0; i < n; i++) {
    if (i <= 1) {
      next = i;
    } else {
      next = first + second;
      first = second;
      second = next;
    }
    printf("%d ", next);
  }

  return 0;
}

/*
Output
Enter the number of Fibonacci numbers: 5
First 5 Fibonacci numbers:
0 1 1 2 3
*/