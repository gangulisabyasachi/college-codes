/*
Write a menu-driven program to –
 Calculate the factorial of a given number,
 Check whether the number is prime or not (Use square root approach),
 Check whether the number is a palindrome or not.
*/

#include <stdio.h>
#include <math.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int is_prime(int n) {
    if (n <= 3) {
        return 1;
    }
    for (int i = 5; i * i <= sqrt(n); i += 6) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int is_palindrome(int n) {
    int temp = n;
    int rev = 0;
    while (temp != 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return rev == n;
}

int main() {
    int choice, n, toContinue=1;
    printf("1. Calculate the factorial of a given number\n");
    printf("2. Check whether the number is prime or not\n");
    printf("3. Check whether the number is a palindrome or not\n");
    

    while(toContinue==1){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Factorial of %d is %d\n", n, factorial(n));
                break;
            case 2:
                printf("Enter a number: ");
                scanf("%d", &n);
                if (is_prime(n)) {
                    printf("%d is a prime number\n", n);
                } else {
                    printf("%d is not a prime number\n", n);
                }
                break;
            case 3:
                printf("Enter a number: ");
                scanf("%d", &n);
                if (is_palindrome(n)) {
                    printf("%d is a palindrome number\n", n);
                } else {
                    printf("%d is not a palindrome number\n", n);
                }
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("Do you want to continue? (1/0): ");
        scanf("%d", &toContinue);
    }
    return 0;
}

/*
1. Calculate the factorial of a given number
2. Check whether the number is prime or not
3. Check whether the number is a palindrome or not
Enter your choice: 1
Enter a number: 12
Factorial of 12 is 479001600
Do you want to continue? (1/0): 1
Enter your choice: 2
Enter a number: 13
13 is a prime number
Do you want to continue? (1/0): 1
Enter your choice: 3
Enter a number: 131131
131131 is a palindrome number
Do you want to continue? (1/0): 0
*/