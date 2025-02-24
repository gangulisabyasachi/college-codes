#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMat(int **mat, int n, int c) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c; j++) {
            printf("%2d ", mat[i][j]);  // Neater output
        }
        printf("\n");
    }
}

int isValid(int c1, int n2) {
    return c1 == n2;
}

void mulMat(int **mat1, int n1, int c1, int **mat2, int c2) {
    FILE *ans = fopen("filen3.txt", "w");  // Relative path
    if (!ans) {
        printf("Error opening result file.\n");
        return;
    }

    fprintf(ans, "%d %d\n", n1, c2);

    int **result = (int **)malloc(n1 * sizeof(int *));
    for (int i = 0; i < n1; i++) {
        result[i] = (int *)malloc(c2 * sizeof(int));
    }

    printf("Resultant Matrix:\n");
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < c2; j++) {
            int val = 0;
            for (int k = 0; k < c1; k++) {
                val += mat1[i][k] * mat2[k][j];
            }
            result[i][j] = val;
            fprintf(ans, "%d ", val);
            printf("%2d ", val);
        }
        fprintf(ans, "\n");
        printf("\n");
    }

    fclose(ans);

    for (int i = 0; i < n1; i++) {
        free(result[i]);
    }
    free(result);
}

void getMats() {
    srand(time(0));
    FILE *f1 = fopen("filen1.txt", "w");
    FILE *f2 = fopen("filen2.txt", "w");

    if (!f1 || !f2) {
        printf("Error opening input files for writing.\n");
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        return;
    }

    int n1, c1, n2, c2;
    printf("Enter dimensions of Matrix 1 (rows cols): ");
    scanf("%d %d", &n1, &c1);
    printf("Enter dimensions of Matrix 2 (rows cols): ");
    scanf("%d %d", &n2, &c2);

    if (!isValid(c1, n2)) {
        printf("Matrix multiplication not possible!\n");
        fclose(f1);
        fclose(f2);
        return;
    }

    fprintf(f1, "%d %d\n", n1, c1);
    fprintf(f2, "%d %d\n", n2, c2);

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < c1; j++) {
            fprintf(f1, "%d ", rand() % 10);
        }
        fprintf(f1, "\n");
    }

    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < c2; j++) {
            fprintf(f2, "%d ", rand() % 10);
        }
        fprintf(f2, "\n");
    }

    fclose(f1);
    fclose(f2);

    f1 = fopen("filen1.txt", "r");
    f2 = fopen("filen2.txt", "r");

    if (!f1 || !f2) {
        printf("Error opening input files for reading.\n");
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        return;
    }

    fscanf(f1, "%d %d", &n1, &c1);
    fscanf(f2, "%d %d", &n2, &c2);

    int **mat1 = (int **)malloc(n1 * sizeof(int *));
    for (int i = 0; i < n1; i++) {
        mat1[i] = (int *)malloc(c1 * sizeof(int));
        for (int j = 0; j < c1; j++) {
            fscanf(f1, "%d", &mat1[i][j]);
        }
    }
    fclose(f1);

    int **mat2 = (int **)malloc(n2 * sizeof(int *));
    for (int i = 0; i < n2; i++) {
        mat2[i] = (int *)malloc(c2 * sizeof(int));
        for (int j = 0; j < c2; j++) {
            fscanf(f2, "%d", &mat2[i][j]);
        }
    }
    fclose(f2);

    printf("Matrix 1:\n");
    printMat(mat1, n1, c1);
    printf("Matrix 2:\n");
    printMat(mat2, n2, c2);

    mulMat(mat1, n1, c1, mat2, c2);

    for (int i = 0; i < n1; i++) free(mat1[i]);
    free(mat1);
    for (int i = 0; i < n2; i++) free(mat2[i]);
    free(mat2);
}

int main() {
    getMats();
    return 0;
}
