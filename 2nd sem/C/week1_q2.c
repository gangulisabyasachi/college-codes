/*Write a program to convert temperature from Fahrenheit to Celsius and vice versa.*/
#include <stdio.h>
int main() {
  double c, f;
  printf("Enter the temperature in Celsius: ");
  scanf("%lf", &c);
  f = ((c * 9) / 5 + 32);
  printf("Temperature in Fahreinheit: %lf\n", f);
  f = 0;
  c = 0;
  printf("Enter the temperature in Fahrenheit: ");
  scanf("%lf", &f);
  c = (f - 32) * 5 / 9;
  printf("Temperature in Celsius: %.2lf\n", c);
  return 0;
}


/*
Output
Enter the temperature in Celsius: 25
Temperature in Fahreinheit: 77.000000
Enter the temperature in Fahrenheit: 300
Temperature in Celsius: 148.89
*/