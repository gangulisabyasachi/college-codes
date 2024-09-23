/*Write a program to check whether a given number is palindrome or not.*/
#include <stdio.h>
int main() {

  int num, reversedNum = 0, remainder, originalNum;

  printf("Enter a number: ");
  scanf("%d", &num);

  originalNum = num;

  while (num != 0) {
    remainder = num % 10;
    reversedNum = reversedNum * 10 + remainder;
    num /= 10;
  }

  if (originalNum == reversedNum) {
    printf("%d is a palindrome.\n", originalNum);
  } else {
    printf("%d is not a palindrome.\n", originalNum);
  }
  return 0;
}

/*
Output

Enter a number: 123
123 is not a palindrome.

Enter a number: 121
121 is a palindrome.
*/