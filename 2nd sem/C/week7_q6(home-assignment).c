/*Write a program to find the transpose of a matrix using function*/
#include <stdio.h>
int main() {
  int a[10][10], b[10][10], r, c, i, j;
  printf("Enter the number of rows and columns:");
  scanf("%d%d", &r, &c);
  printf("Enter the elements of the matrix:\n");
  for (i = 0; i < r; i++){
    for (j = 0; j < c; j++)
      scanf("%d", &a[i][j]);
  }
  printf("The matrix is:\n");
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      printf("%d\t", a[i][j]);
    }
    printf("\n");
  }
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++)
      b[j][i] = a[i][j];
  }
  printf("The transpose of the matrix is:\n");
  for (i = 0; i < c; i++) {
    for (j = 0; j < r; j++) {
      printf("%d\t", b[i][j]);
    }
    printf("\n");
  }
  return 0;
}

/*
Output
Enter the number of rows and columns:3
3
Enter the elements of the matrix:
1
2
3
4
5
6
7
8
9
The matrix is:
1   2   3
4   5   6
7   8   9
The transpose of the matrix is:
1   4   7
2   5   8
3   6   9
*/