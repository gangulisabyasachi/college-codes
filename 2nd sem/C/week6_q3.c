/*
Write a recursive function to calculate the GCD of two numbers
*/

#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
    return 0;
}

/*
Enter two numbers: 13
12
GCD of 13 and 12 is 1
architanant@Archits-MacBook-Air practice_c % ./p3.out
Enter two numbers: 12 6
GCD of 12 and 6 is 6
*/