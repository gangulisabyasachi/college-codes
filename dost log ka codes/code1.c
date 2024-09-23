#include <stdio.h>
#include <stdlib.h>

void read_matrix(int **, int, int);
void print_matrix(int **, int, int);
void mult(int **, int **, int **, int, int, int);

int main() {
    int **a, **b, **c, r1, c1, r2, c2, i, j, k;

    printf("Enter the row and column of first matrix\n");
    scanf("%d %d", &r1, &c1);

    printf("Enter the row and column of second matrix\n");
    scanf("%d %d", &r2, &c2);

    // Check if matrices can be multiplied
    if (c1 != r2) {
        printf("Matrices cannot be multiplied\n");
        return 0;
    }

    // Allocate memory for first matrix
    a = (int **)malloc(sizeof(int *) * r1);
    for (i = 0; i < r1; i++)
        a[i] = (int *)malloc(sizeof(int) * c1);

    // Allocate memory for second matrix
    b = (int **)malloc(sizeof(int *) * r2);
    for (i = 0; i < r2; i++)
        b[i] = (int *)malloc(sizeof(int) * c2);

    // Allocate memory for resultant matrix
    c = (int **)malloc(sizeof(int *) * r1);
    for (i = 0; i < r1; i++)
        c[i] = (int *)malloc(sizeof(int) * c2);

    read_matrix(a, r1, c1);
    print_matrix(a, r1, c1);

    read_matrix(b, r2, c2);
    print_matrix(b, r2, c2);

    mult(a, b, c, r1, c1, c2);
    print_matrix(c, r1, c2);

    return 0;
}

void mult(int **a, int **b, int **c, int r1, int c1, int c2) {
    int i, j, k;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            c[i][j] = 0;
            for (k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
}

void print_matrix(int **ptr, int r, int c) {
    int i, j;
    printf("\nMatrix printed----\n");
    for (i = 0; i < r; i++) {
        printf("\n");
        for (j = 0; j < c; j++) {
            printf("%d ", ptr[i][j]);
        }
    }
}

void read_matrix(int **ptr, int r, int c) {
    int i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            printf("Enter the value for %d %d\n", i, j);
            scanf("%d", &ptr[i][j]);
        }
}
