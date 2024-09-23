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

    int **transposeTriplet = (int **)malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++) {
        transposeTriplet[i] = (int *)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        transposeTriplet[0][i] = triplet[1][i];
        transposeTriplet[1][i] = triplet[0][i];
        transposeTriplet[2][i] = triplet[2][i];
    }

    printf("Triplet representation of the transpose matrix is:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", transposeTriplet[i][j]);
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

    for (int i = 0; i < 3; i++) {
        free(transposeTriplet[i]);
    }
    free(transposeTriplet);

    return 0;
}
