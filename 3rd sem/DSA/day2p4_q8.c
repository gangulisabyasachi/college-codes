#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, size = 0;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) {
                size++;
            }
        }
    }

    int **triplet = (int **)malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++) {
        triplet[i] = (int *)malloc(size * sizeof(int));
    }

    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                triplet[0][k] = i;
                triplet[1][k] = j;
                triplet[2][k] = matrix[i][j];
                k++;
            }
        }
    }

    printf("Triplet representation of the matrix is:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", triplet[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < 3; i++) {
        free(triplet[i]);
    }
    free(triplet);

    return 0;
}
