/*Write a program to print the sum of the following harmonic series for a given
value of n:

1+1/2+1/3+.....+1/n*/

#include <stdio.h>
float harmonic_sum(int n) {
  float i, sum = 1;
  for (i = 1; i <= n; i++) {
    sum += 1.0 / i;
  }
  return sum;
}

int main() {
  int n;
  printf("Enter the value of n: ");
  scanf("%d", &n);
  float sum = harmonic_sum(n);
  printf("The sum of the series upto %d terms is %.2f\n", n, sum);
  return 0;
}

/*
Output
Enter the value of n: 5
The sum of the series upto 5 terms is 3.28
*/