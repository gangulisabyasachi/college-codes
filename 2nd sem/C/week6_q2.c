/*
Write a recursive function to convert a decimal integer, taken as input, to its
hexadecimal equivalent.
*/

#include <stdio.h>
#include <math.h>

void decToHex(int n) {
    if (n == 0) {
        return;
    }
    decToHex(n / 16);
    int rem = n % 16;
    if (rem < 10) {
        printf("%d", rem);
    } else {
        printf("%c", rem - 10 + 'A');
    }
}

int main() {
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    printf("Hexadecimal equivalent: ");
    decToHex(n);
    printf("\n");
    return 0;
}

/*
Enter a decimal number: 12
Hexadecimal equivalent: C
Enter a decimal number: 1311
Hexadecimal equivalent: 51F
Enter a decimal number: 459
Hexadecimal equivalent: 1CB
*/