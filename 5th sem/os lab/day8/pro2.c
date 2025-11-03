/* pro2.c: Checks if a given number is prime. */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check for primality.
// Returns 0 if prime, 1 if not prime. This matches our exit codes.
int is_prime(long long n) {
    if (n <= 1) return 1; // Not prime
    if (n <= 3) return 0; // Prime
    if (n % 2 == 0 || n % 3 == 0) return 1; // Not prime

    for (long long i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 1; // Not prime
        }
    }
    return 0; // Prime
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        exit(2); // Use a different exit code for usage errors.
    }

    long long num = atoll(argv[1]); // Use atoll for long long.

    // Exit with the result of the primality test.
    // This exit code will be checked by demo.c.
    exit(is_prime(num));
}