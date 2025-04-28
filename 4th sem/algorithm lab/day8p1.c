#include <stdio.h>
#include <limits.h>

// Function prototype
void printOptimalParenthesis(int s[][5], int i, int j);

// Function to multiply a chain of matrices optimally using DP
void matrixChainOrder(int p[], int n) {
    int m[n][n]; // m[i][j] will store the minimum number of multiplications needed to multiply matrices i to j
    int s[n][n]; // s[i][j] stores the index of the matrix after which the chain is split optimally

    // m[i][i] is 0 because a single matrix requires no multiplication
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // l is the chain length
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX; // Set to a large number initially

            // Find the minimum cost for multiplying matrices i to j
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // Output the minimum number of multiplications
    printf("Minimum number of scalar multiplications: %d\n", m[1][n - 1]);

    // Function to print the optimal order of matrices
    printf("Optimal parenthesization: ");
    printOptimalParenthesis(s, 1, n - 1);
    printf("\n");
}

// Function to print the optimal parenthesization
void printOptimalParenthesis(int s[][5], int i, int j) {
    if (i == j) {
        printf("M%d", i);
    } else {
        printf("(");
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n;
    
    // Taking input for number of matrices
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    
    int dimensions[n + 1];
    
    // Taking input for the dimensions of the matrices
    printf("Enter the dimensions (for n matrices, enter n+1 numbers): ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &dimensions[i]);
    }

    // Call the matrix chain multiplication function
    matrixChainOrder(dimensions, n + 1);
    
    return 0;
}
