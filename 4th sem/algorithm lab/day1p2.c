#include <stdio.h>
#include <stdlib.h>

void printMat(int **mat, int n, int c) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int isValid(int c1, int n2) {
    return c1 == n2;
}

void mulMat(int **mat1, int n1, int c1, int **mat2, int c2) {
    FILE *ans = fopen("/Users/sabyasachiganguli/Desktop/code/college codes/4th sem/algorithm lab/file3.txt", "w");
    if (!ans) {
        printf("Error opening file3.txt for writing\n");
        return;
    }

    fprintf(ans, "%d %d\n", n1, c2);

    int i, j, k, val;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < c2; j++) {
            val = 0;
            for (k = 0; k < c1; k++) {
                val += mat1[i][k] * mat2[k][j];
            }
            fprintf(ans, "%d ", val);
        }
        fprintf(ans, "\n");
    }

    fclose(ans);
}

void getMats() {
    FILE *f1, *f2;
    f1 = fopen("/Users/sabyasachiganguli/Desktop/code/college codes/4th sem/algorithm lab/file1.txt", "r");
    f2 = fopen("/Users/sabyasachiganguli/Desktop/code/college codes/4th sem/algorithm lab/file2.txt", "r");

    if (!f1 || !f2) {
        printf("Error opening files.\n");
        return;
    }

    int n1, c1, n2, c2;
    fscanf(f1, "%d %d", &n1, &c1);
    fscanf(f2, "%d %d", &n2, &c2);

    if (!isValid(c1, n2)) {
        printf("Multiplication not possible\n");
        fclose(f1);
        fclose(f2);
        return;
    }

    int i, j;
    int **mat1 = (int **)malloc(n1 * sizeof(int *));
    for (i = 0; i < n1; i++) {
        mat1[i] = (int *)malloc(c1 * sizeof(int));
    }
    
    for (i = 0; i < n1; i++) {
        for (j = 0; j < c1; j++) {
            fscanf(f1, "%d", &mat1[i][j]);
        }
    }
    fclose(f1);

    int **mat2 = (int **)malloc(n2 * sizeof(int *));
    for (i = 0; i < n2; i++) {
        mat2[i] = (int *)malloc(c2 * sizeof(int));
    }
    
    for (i = 0; i < n2; i++) {
        for (j = 0; j < c2; j++) {
            fscanf(f2, "%d", &mat2[i][j]);
        }
    }
    fclose(f2);

    printf("Matrix 1:\n");
    printMat(mat1, n1, c1);
    printf("Matrix 2:\n");
    printMat(mat2, n2, c2);

    mulMat(mat1, n1, c1, mat2, c2);

    for (i = 0; i < n1; i++) free(mat1[i]);
    free(mat1);
    for (i = 0; i < n2; i++) free(mat2[i]);
    free(mat2);
}

int main() {
    getMats();
    return 0;
}
