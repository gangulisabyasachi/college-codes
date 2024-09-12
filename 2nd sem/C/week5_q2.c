/*Write a program to print the following pattern where the number of rows in the
  pattern is a user input.

  1
  2 3 2
  3 4 5 4 3
  4 5 6 7 6 5 4
  5 6 7 8 9 8 7 6 5*/
#include <stdio.h>
int main() {
  int rows, i, j, k, space;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  for (i = 1; i <= rows; i++) {
    for (space = 1; space <= rows - i; space++)
      printf(" ");
    int start_number = i;
    for (j = 1; j <= i; j++)
      printf("%d", start_number++);
    start_number -= 2;
    for (k = 1; k < i; k++)
      printf("%d", start_number--);
    printf("\n");
  }
  return 0;
}

/*
Output
Enter the number of rows: 5
    1
   232
  34543
 4567654
567898765
  */