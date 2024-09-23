/*Write a program to print a Pascal's triangle for an input N*/

#include <stdio.h>
int factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}
int binomialCoefficient(int n, int k) {
  return factorial(n) / (factorial(k) * factorial(n - k));
}

void PascalTriangle(int n) {
  int line, j, i;
  for (line = 0; line < n; line++) {
    for (i = 0; i < (n - line - 1); i++) {
      printf(" ");
    }
    for (j = 0; j <= line; j++) {
      printf("%d ", binomialCoefficient(line, j));
    }
    printf("\n");
  }
}

int main() {
  int n;
  printf("Enter the number of rows: ");
  scanf("%d", &n);
  PascalTriangle(n);
}

/*
Output
Enter the number of rows: 5
    1 
   1 1 
  1 2 1 
 1 3 3 1 
1 4 6 4 1 
*/