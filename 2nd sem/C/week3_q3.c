/*Develop a simple calculator to accept two floating point numbers from the key-board.
Then display a menu to the user and let him/her select a mathematical operation to be

performed on those two numbers. Then display the answer. A sample run of your
program should be similar to the following:
Enter number 1: 20
Enter number 2: 12
Mathematical Operations:
1 – Add
2 - Subtract
3 - Multiply
4 - Divide
Enter your preference: 2
Answer: 8.00*/

#include <stdio.h>

int main() {
  float num1, num2, result;
  int choice;

  printf("Enter number 1: ");
  scanf("%f", &num1);
  printf("Enter number 2: ");
  scanf("%f", &num2);

  printf("Mathematical Operations:\n");
  printf("1 - Add\n");
  printf("2 - Subtract\n");
  printf("3 - Multiply\n");
  printf("4 - Divide\n");
  printf("Enter your preference: ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    result = num1 + num2;
    break;
  case 2:
    result = num1 - num2;
    break;
  case 3:
    result = num1 * num2;
    break;
  case 4:
    if (num2 != 0) {
      result = num1 / num2;
    } else {
      printf("Cannot divide by zero.\n");
      return 1;
    }
    break;
  default:
    printf("Invalid choice\n");
    return 1;
  }

  printf("Answer: %.2f\n", result);

  return 0;
}

/*
Output
Enter number 1: 10
Enter number 2: 5
Mathematical Operations:
1 - Add
2 - Subtract
3 - Multiply
4 - Divide
Enter your preference: 1
Answer: 15.00

Enter number 1: 10
Enter number 2: 5
Mathematical Operations:
1 - Add
2 - Subtract
3 - Multiply
4 - Divide
Enter your preference: 2
Answer: 5.00

Enter number 1: 10
Enter number 2: 5
Mathematical Operations:
1 - Add
2 - Subtract
3 - Multiply
4 - Divide
Enter your preference: 3
Answer: 50.00

Enter number 1: 10
Enter number 2: 5
Mathematical Operations:
1 - Add
2 - Subtract
3 - Multiply
4 - Divide
Enter your preference: 4
Answer: 2.00
*/