/*Write a program to find the roots (real and imaginary) of a quadratic equation of the
form ax2 + bx + c = 0.*/

#include <math.h>
#include <stdio.h>

int main() {
  float a, b, c;
  float discriminant, realPart, imagPart;

  printf("Enter coefficients a, b and c: ");
  scanf("%f %f %f", &a, &b, &c);

  discriminant = b * b - 4 * a * c;

  if (discriminant > 0) {
    float root1 = (-b + sqrt(discriminant)) / (2 * a);
    float root2 = (-b - sqrt(discriminant)) / (2 * a);
    printf("Roots are real and different: %.2f and %.2f\n", root1, root2);
  } else if (discriminant == 0) {
    float root = -b / (2 * a);
    printf("Roots are real and same: %.2f\n", root);
  } else {
    realPart = -b / (2 * a);
    imagPart = sqrt(-discriminant) / (2 * a);
    printf("Roots are complex and different: %.2f + %.2fi and %.2f - %.2fi\n",
           realPart, imagPart, realPart, imagPart);
  }

  return 0;
}

/*
Output

Enter coefficients a, b and c: 1
-6
9
Roots are real and same: 3.00

Enter coefficients a, b and c: 1
-5
6
Roots are real and different: 3.00 and 2.00

Enter coefficients a, b and c: 1
4
5
Roots are complex and different: -2.00 + 1.00i and -2.00 - 1.00i

*/