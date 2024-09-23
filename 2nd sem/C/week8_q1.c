/*Write a program, using pointers, to multiply two matrices. Use dynamic memory
allocation to allocate the matrices. NB: Check proper conditions for matrix
multiplication.*/

#include <stdio.h>
#include <stdlib.h>

int **allocateMatrix(int rows, int cols) {
  int i;
  int **matrix = (int **)(malloc(rows * sizeof(int *)));
  for (i = 0; i < rows; i++)
    matrix[i] = (int *)(malloc(cols * sizeof(int)));
  return matrix;
}

void freeMatrix(int **matrix, int rows) {
  int i;
  for (i = 0; i < rows; i++)
    free(matrix[i]);
  free(matrix);
}

int **multiplyMatrix(int **matrix1, int **matrix2, int rows1, int cols1,
                     int cols2) {
  int **result = allocateMatrix(rows1, cols2);
  int i, j, k;
  for (i = 0; i < rows1; i++) {
    for (j = 0; j < cols2; j++) {
      result[i][j] = 0;
      for (k = 0; k < cols1; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  return result;
}

void printMatrix(int **matrix, int rows, int cols) {
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int rows1, cols1, rows2, cols2;
  printf("Enter the number of rows and columns of the first matrix: ");
  scanf("%d %d", &rows1, &cols1);
  printf("Enter the number of rows and columns of the second matrix: ");
  scanf("%d %d", &rows2, &cols2);
  if (cols1 != rows2) {
    printf("Error: The number of columns of the first matrix must be equal to "
           "the number of rows of the second matrix");
    return 1;
  }
  int **matrix1 = allocateMatrix(rows1, cols1);
  int **matrix2 = allocateMatrix(rows2, cols2);
  int i, j;
  printf("Enter the elements of the first matrix:\n");
  for (i = 0; i < rows1; i++) {
    for (j = 0; j < cols1; j++) {
      scanf("%d", &matrix1[i][j]);
    }
  }
  printf("Enter the elements of the second matrix:\n");
  for (i = 0; i < rows2; i++) {
    for (j = 0; j < cols2; j++) {
      scanf("%d", &matrix2[i][j]);
    }
  }
  int **result = multiplyMatrix(matrix1, matrix2, rows1, cols1, cols2);
  printf("The result of the multiplication is:\n");
  printMatrix(result, rows1, cols2);
  freeMatrix(matrix1, rows1);
  freeMatrix(matrix2, rows2);
  freeMatrix(result, rows1);
  return 0;
}

/*
Output
Enter the number of rows and columns of the first matrix: 3
3
Enter the number of rows and columns of the second matrix: 3
3
Enter the elements of the first matrix:
1
2
3
4
5
6
7
8
9
Enter the elements of the second matrix:
1
2
3
4
5
6
7
8
9
The result of the multiplication is:
30 36 42
66 81 96
102 126 150


Enter the number of rows and columns of the first matrix: 3
3
Enter the number of rows and columns of the second matrix: 2
2
Error: The number of columns of the first matrix must be equal to the number of
rows of the second matrix

*/