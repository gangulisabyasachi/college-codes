/*
Write a program to print the following pattern:

1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
  */

#include <stdio.h>
int main() {
  int i, j, rows;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  for (i = 1; i <= rows; i++) {
    for (j = 1; j <= i; j++) {
      printf("%d ", i);
    }
    printf("\n");
  }
  return 0;
}

/*
Output
Enter the number of rows: 5
1 
2 2 
3 3 3 
4 4 4 4 
5 5 5 5 5 
*/