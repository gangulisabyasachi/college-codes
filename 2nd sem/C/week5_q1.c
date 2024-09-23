/*Write a program to evaluate the summation of the following series, where the
number of terms N and independent variable X are taken as input from the user:
1-X/1! +X^2/2! - X^3/3! +...........*/
#include <math.h>
#include <stdio.h>

float summation(int N, int X);
int factorial(int num);
int factorial(int num) {
  if (num == 0)
    return 1;
  else
    return num * factorial(num - 1);
}
float summation(int N, int X) {
  float sum;
  int i;
  for (i = 0; i < N; i++) {
    float term = pow(-1, i) * pow(X, i) / factorial(i);
    sum += term;
  }
  return sum;
}
int main() {
  int N, X;
  printf("Enter the value of N: ");
  scanf("%d", &N);
  printf("Enter the term (X): ");
  scanf("%d", &X);
  printf("summation is %.2f\n", summation(N, X));
  return 0;
}

/*
Output
Enter the value of N: 5
Enter the term (X): 6
summation is 31.00
*/