#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Function to check if a matrix is an identity matrix
bool isIdentityMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0)) {
                return false;
            }
        }
    }
    return true;
}

// Function to check if a matrix is a diagonal matrix
bool isDiagonalMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int n;

    // Input matrix size
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    // Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if the matrix is an identity matrix
    if (isIdentityMatrix(matrix, n)) {
        printf("The matrix is an identity matrix.\n");
    } else {
        printf("The matrix is not an identity matrix.\n");
    }

    // Check if the matrix is a diagonal matrix
    if (isDiagonalMatrix(matrix, n)) {
        printf("The matrix is a diagonal matrix.\n");
    } else {
        printf("The matrix is not a diagonal matrix.\n");
    }

    return 0;
}
