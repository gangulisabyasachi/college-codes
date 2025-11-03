#include <stdio.h>
#include <pthread.h>

// Global variables to store the numbers and results
int a, b;
int s, p;

// Function to calculate the sum of two numbers (to be run in a thread)
void *sum(void *args) {
    s = a + b;
    pthread_exit(NULL);
}

// Function to calculate the product of two numbers (to be run in a thread)
void *product(void *args) {
    p = a * b;
    pthread_exit(NULL);
}

int main() {
    // Thread identifiers
    pthread_t t1, t2;

    // Prompt user for input
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Create the first thread to execute the sum function
    pthread_create(&t1, NULL, sum, NULL);

    // Create the second thread to execute the product function
    pthread_create(&t2, NULL, product, NULL);

    // Wait for the sum thread to finish
    pthread_join(t1, NULL);

    // Wait for the product thread to finish
    pthread_join(t2, NULL);

    // Print the results
    printf("Product = %d\n", p);
    printf("Sum = %d\n", s);

    return 0;
}

// Enter two integers: 12 5
// Product = 60
// Sum = 17