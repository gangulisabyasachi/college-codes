#include <stdio.h>
#include <stdlib.h>

void readMatrix(int rows, int cols, int ***matrix) {
    *matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &(*matrix)[i][j]);
        }
    }
}

void convertToTriplet(int rows, int cols, int **matrix, int ***triplet, int *size) {
    *size = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                (*size)++;
            }
        }
    }

    *triplet = (int **)malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++) {
        (*triplet)[i] = (int *)malloc(*size * sizeof(int));
    }

    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                (*triplet)[0][k] = i;
                (*triplet)[1][k] = j;
                (*triplet)[2][k] = matrix[i][j];
                k++;
            }
        }
    }
}

void addTriplets(int **triplet1, int size1, int **triplet2, int size2, int ***result, int *resultSize) {
    *resultSize = 0;
    *result = (int **)malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++) {
        (*result)[i] = (int *)malloc((size1 + size2) * sizeof(int));
    }

    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (triplet1[0][i] < triplet2[0][j] || (triplet1[0][i] == triplet2[0][j] && triplet1[1][i] < triplet2[1][j])) {
            (*result)[0][k] = triplet1[0][i];
            (*result)[1][k] = triplet1[1][i];
            (*result)[2][k] = triplet1[2][i];
            i++;
        } else if (triplet1[0][i] > triplet2[0][j] || (triplet1[0][i] == triplet2[0][j] && triplet1[1][i] > triplet2[1][j])) {
            (*result)[0][k] = triplet2[0][j];
            (*result)[1][k] = triplet2[1][j];
            (*result)[2][k] = triplet2[2][j];
            j++;
        } else {
            (*result)[0][k] = triplet1[0][i];
            (*result)[1][k] = triplet1[1][i];
            (*result)[2][k] = triplet1[2][i] + triplet2[2][j];
            i++;
            j++;
        }
        k++;
    }

    while (i < size1) {
        (*result)[0][k] = triplet1[0][i];
        (*result)[1][k] = triplet1[1][i];
        (*result)[2][k] = triplet1[2][i];
        i++;
        k++;
    }

    while (j < size2) {
        (*result)[0][k] = triplet2[0][j];
        (*result)[1][k] = triplet2[1][j];
        (*result)[2][k] = triplet2[2][j];
        j++;
        k++;
    }

    *resultSize = k;
}

void printTriplet(int **triplet, int size) {
    printf("Triplet representation:\n");
    for (int i = 0; i < size; i++) {
        printf("%d %d %d\n", triplet[0][i], triplet[1][i], triplet[2][i]);
    }
}

int main() {
    int rows, cols;
    int **matrix1, **matrix2;
    int **triplet1, **triplet2, **result;
    int size1, size2, resultSize;

    printf("Enter the number of rows and columns of the matrices: ");
    scanf("%d %d", &rows, &cols);

    printf("Matrix 1:\n");
    readMatrix(rows, cols, &matrix1);
    printf("Matrix 2:\n");
    readMatrix(rows, cols, &matrix2);

    convertToTriplet(rows, cols, matrix1, &triplet1, &size1);
    convertToTriplet(rows, cols, matrix2, &triplet2, &size2);

    addTriplets(triplet1, size1, triplet2, size2, &result, &resultSize);

    printf("Resultant matrix in triplet representation:\n");
    printTriplet(result, resultSize);

    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);

    for (int i = 0; i < 3; i++) {
        free(triplet1[i]);
        free(triplet2[i]);
        free(result[i]);
    }
    free(triplet1);
    free(triplet2);
    free(result);

    return 0;
}
