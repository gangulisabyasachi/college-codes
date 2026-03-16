/* pro1.c: Calculates the sum of integers in a given range. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check for the correct number of command-line arguments.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <low> <high>\n", argv[0]);
        return 1;
    }

    // Convert string arguments to integers.
    int low = atoi(argv[1]);
    int high = atoi(argv[2]);
    long long sum = 0; // Use long long to prevent overflow with large sums.

    if (low > high) {
        fprintf(stderr, "Error: 'low' value cannot be greater than 'high' value.\n");
        return 1;
    }
    
    // Calculate the summation.
    for (int i = low; i <= high; i++) {
        sum += i;
    }

    // Print the result to standard output. This will be captured by demo.c.
    printf("%lld", sum);

    return 0;
}