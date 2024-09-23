//Write a program to swap the values of two variables, entered by the user. (Use a 3rd variable).
#include <stdio.h>
int main() {
  int num1, num2, temp;

  printf("Enter value of num1: ");
  scanf("%d", &num1);

  printf("Enter value of num2: ");
  scanf("%d", &num2);

  temp = num1;
  num1 = num2;
  num2 = temp;

  printf("After swapping, num1 = %d and num2 = %d", num1, num2);

  return 0;
}

/*
Output
Enter value of num1: 9
Enter value of num2: 2
After swapping, num1 = 2 and num2 = 9
*/