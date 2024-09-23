/*Write a program to find whether a given matrix is upper triangular or lower triangular.*/

#include <stdio.h>
#define SIZE 3

int is_upper_triangular(int mat[SIZE][SIZE]) {
  int i, j;
  for (i = 1; i < SIZE; i++) {
    for (j = 0; j < i; j++) {
      if (mat[i][j] != 0)
        return 0;
    }
  }
  return 1;
}

int is_lower_triangular(int mat[SIZE][SIZE]) {
  int i, j;
  for (i = 0; i < SIZE; i++) {
    for (j = i + 1; j < SIZE; j++) {
      if (mat[i][j] != 0)
        return 0;
    }
  }
  return 1;
}

int main() {
  int i, j, mat[SIZE][SIZE];
  printf("Enter elements of the %dx%d matrix:\n", SIZE, SIZE);
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++)
      scanf("%d", &mat[i][j]);
  }
  if (is_upper_triangular(mat))
    printf("The matrix is upper triangular.\n");
  else if (is_lower_triangular(mat))
    printf("The matrix is lower triangular.\n");
  else
    printf("The matrix is neither upper nor lower triangular.\n");
  return 0;
}

/*
Output
Enter elements of the 3x3 matrix:
1
2
3
4
5
6
7
8
9
The matrix is neither upper nor lower triangular.
  */