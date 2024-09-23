#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to dynamically allocate a 2D array
int** allocateMatrix(int size) {
    int **matrix = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = malloc(size * sizeof(int));
    }
    return matrix;
}

// Function to free a dynamically allocated 2D array
void freeMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to populate a matrix with random digits 0-9
void populateMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int **matrixA, int **matrixB, int **matrixC, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrixC[i][j] = 0;
            for (int k = 0; k < size; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int sizes[] = {10000, 100000, 1000000};
    srand(time(NULL));  // Seed the random number generator

    for (int i = 0; i < 3; i++) {
        int size = sizes[i];
        printf("Matrix size: %dx%d\n", size, size);

        // Allocate memory for matrices
        int **matrixA = allocateMatrix(size);
        int **matrixB = allocateMatrix(size);
        int **matrixC = allocateMatrix(size);

        // Populate matrices A and B with random digits 0-9
        populateMatrix(matrixA, size);
        populateMatrix(matrixB, size);

        // Measure time taken for matrix multiplication
        clock_t start = clock();
        multiplyMatrices(matrixA, matrixB, matrixC, size);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken for multiplication: %f seconds\n", time_taken);

        // Free allocated memory
        freeMatrix(matrixA, size);
        freeMatrix(matrixB, size);
        freeMatrix(matrixC, size);

        printf("\n");
    }

    return 0;
}
