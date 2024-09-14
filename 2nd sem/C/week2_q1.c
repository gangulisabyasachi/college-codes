//Write a program to calculate the area of a triangle.
#include <stdio.h>

int main() {
  float side1, side2, side3, s, area;

  printf("Enter the length of side 1: ");
  scanf("%f", &side1);

  printf("Enter the length of side 2: ");
  scanf("%f", &side2);

  printf("Enter the length of side 3: ");
  scanf("%f", &side3);

  s = (side1 + side2 + side3) / 2;
  area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

  printf("The area of the triangle is: %f\n", area);

  return 0;
}

/*
Output
Enter the length of side 1: 5
Enter the length of side 2: 4
Enter the length of side 3: 3
The area of the triangle is: 6.000000
*/