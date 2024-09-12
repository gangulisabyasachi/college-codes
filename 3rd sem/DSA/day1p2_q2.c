#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to dynamically allocate a 2D array
int **allocateMatrix(int rows, int cols)
{
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free a dynamically allocated 2D array
void freeMatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to populate a matrix with random digits 0-9
void populateMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }
}

// Function to print a matrix
void printMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrices(int **matrixA, int **matrixB, int **matrixC, int rowsA, int colsA, int colsB)
{
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            matrixC[i][j] = 0;
            for (int k = 0; k < colsA; k++)
            {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main()
{
    int rowsA = 3, colsA = 4;
    int rowsB = 4, colsB = 3;
    int rowsC = 3, colsC = 3;

    // Seed the random number generator
    srand(time(NULL));

    // Allocate memory for matrices
    int **matrixA = allocateMatrix(rowsA, colsA);
    int **matrixB = allocateMatrix(rowsB, colsB);
    int **matrixC = allocateMatrix(rowsC, colsC);

    // Populate matrices A and B with random digits 0-9
    populateMatrix(matrixA, rowsA, colsA);
    populateMatrix(matrixB, rowsB, colsB);

    // Print matrices A and B
    printf("Matrix A (%d x %d):\n", rowsA, colsA);
    printMatrix(matrixA, rowsA, colsA);

    printf("\nMatrix B (%d x %d):\n", rowsB, colsB);
    printMatrix(matrixB, rowsB, colsB);

    // Multiply matrices A and B to get matrix C
    multiplyMatrices(matrixA, matrixB, matrixC, rowsA, colsA, colsB);

    // Print matrix C
    printf("\nMatrix C (%d x %d) = Matrix A * Matrix B:\n", rowsC, colsC);
    printMatrix(matrixC, rowsC, colsC);

    // Free allocated memory
    freeMatrix(matrixA, rowsA);
    freeMatrix(matrixB, rowsB);
    freeMatrix(matrixC, rowsC);

    return 0;
}
