// Write a program to find out the area of a circle.
#include <stdio.h>

int main() {
  float radius, area;

  printf("Enter the radius of the circle: ");
  scanf("%f", &radius);

  area = 3.14159 * radius * radius;

  printf("The area of the circle is: %f\n", area);

  return 0;
}

/*
Output
Enter the radius of the circle: 25
The area of the circle is: 1963.493774
*/