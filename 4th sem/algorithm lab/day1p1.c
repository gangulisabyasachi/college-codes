#include <stdio.h>
#include <stdlib.h>

int **allocateMat(int n, int c)
{
    int i;
    int **mat = (int **)malloc(n * sizeof(int *));
    if (!mat)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (i = 0; i < n; i++)
    {
        mat[i] = (int *)malloc(c * sizeof(int));
        if (!mat[i])
        {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }
    return mat;
}

void printMat(int **mat, int n, int c)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int **mulMat(int **mat1, int n1, int c1, int **mat2, int c2)
{
    int i, j, k;
    int **mat = allocateMat(n1, c2); // Corrected the dimensions
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            mat[i][j] = 0; // Initialize result matrix
            for (k = 0; k < c1; k++)
            {
                mat[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return mat;
}

int isValid(int c1, int n2)
{
    return c1 == n2;
}

void freeMat(int **mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

int main()
{
    int n1, c1, n2, c2;
    printf("First row count: \n");
    scanf("%d", &n1);
    printf("First col count: \n");
    scanf("%d", &c1);
    printf("Second row count: \n");
    scanf("%d", &n2);
    printf("Second col count: \n");
    scanf("%d", &c2);

    if (!isValid(c1, n2))
    {
        printf("Multiplication not possible\n");
        return 0;
    }

    int **mat1 = allocateMat(n1, c1);
    int **mat2 = allocateMat(n2, c2);

    int i, j;

    printf("Enter values for mat1: \n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter values for mat2: \n");
    for (i = 0; i < n2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    printf("Matrix 1:\n");
    printMat(mat1, n1, c1);
    printf("\nMatrix 2:\n");
    printMat(mat2, n2, c2);

    int **ans = mulMat(mat1, n1, c1, mat2, c2);
    printf("The answer is: \n");
    printMat(ans, n1, c2);

    freeMat(mat1, n1);
    freeMat(mat2, n2);
    freeMat(ans, n1);

    return 0;
}
