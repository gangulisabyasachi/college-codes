#include <stdio.h>
#include <stdlib.h>

// Function to add two polynomials
void addPolynomials(int *poly1, int deg1, int *poly2, int deg2, int *result) {
    // Initialize the result array
    for (int i = 0; i <= (deg1 > deg2 ? deg1 : deg2); i++) {
        result[i] = 0;
    }

    // Add coefficients of the first polynomial to result
    for (int i = 0; i <= deg1; i++) {
        result[i] = poly1[i];
    }

    // Add coefficients of the second polynomial to result
    for (int i = 0; i <= deg2; i++) {
        result[i] += poly2[i];
    }
}

// Function to print a polynomial
void printPolynomial(int *poly, int degree) {
    int firstTerm = 1; // Flag to handle the sign of the first term

    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            if (!firstTerm && poly[i] > 0) {
                printf("+ ");
            }
            if (i == 0) {
                printf("%d ", poly[i]);
            } else if (i == 1) {
                printf("%dx ", poly[i]);
            } else {
                printf("%dx^%d ", poly[i], i);
            }
            firstTerm = 0; // After the first term, we need to consider the sign
        }
    }
    if (firstTerm) {
        printf("0"); // If no term was printed, print "0"
    }
    printf("\n");
}

int main() {
    // Define the first polynomial (example: 3x^2 + 2x + 1)
    int poly1[] = {1, 2, 3}; // 3x^2 + 2x + 1
    int deg1 = sizeof(poly1) / sizeof(poly1[0]) - 1;

    // Define the second polynomial (example: 5x^3 + 4x^1 + 2)
    int poly2[] = {2, 4, 0, 5}; // 5x^3 + 4x + 2
    int deg2 = sizeof(poly2) / sizeof(poly2[0]) - 1;

    // Determine the degree of the resulting polynomial
    int maxDeg = (deg1 > deg2) ? deg1 : deg2;

    // Allocate memory for the result polynomial
    int *result = (int *)malloc((maxDeg + 1) * sizeof(int));
    if (result == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Print the input polynomials
    printf("First polynomial: ");
    printPolynomial(poly1, deg1);

    printf("Second polynomial: ");
    printPolynomial(poly2, deg2);

    // Add the two polynomials
    addPolynomials(poly1, deg1, poly2, deg2, result);
    
    // Print the resulting polynomial
    printf("Resulting polynomial: ");
    printPolynomial(result, maxDeg);

    // Free allocated memory
    free(result);

    return 0;
}
