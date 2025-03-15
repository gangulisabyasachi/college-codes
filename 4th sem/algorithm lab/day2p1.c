#include <stdio.h>
#include <stdlib.h>

int power_O_n(int x, int n, int comparisons)
{
    int result = 1;
    int i;
    for (i = 0; i < n; i++)
    {
        result *= x;
        comparisons++;
    }
    printf("Comparisons: %d\n", comparisons);
    printf("Result: %d\n", result);
    return 0;
}

int power_O_log_n(int x, int n, int comparisons_a)
{
    int result_a = 1;
    while (n > 0)
    {
        comparisons_a++;
        if (n % 2 == 1)
        {
            result_a *= x;
        }
        x *= x;
        n /= 2;
    }
    printf("Comparisons: %d\n", comparisons_a);
    printf("Result: %d\n", result_a);
    return 0;
}

int main()
{
    int x, n, comparisons_n, choice, result_O_log_n, comparisons_O_n, comparisons_O_log_n;
    int comparisons_log_n = 0;
    int result_O_n = 0;

    FILE *file = fopen("/Users/sabyasachiganguli/Desktop/code/college codes/4th sem/algorithm lab/expo.txt", "r");
    if (file == NULL)
    {
        printf("Could not open file");
        return 1;
    }
    fscanf(file, "%d %d", &x, &n);
    fclose(file);

    if (n < 0)
    {
        printf("This program supports positive values only.");
        return 1;
    }

    printf("Input read: X = %d, N = %d\n", x, n);
    do
    {
        printf("Power Calculation\n");
        printf("1. O(n)\n");
        printf("2. O(logn)\n");
        printf("3. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            comparisons_n = 0;
            power_O_n(x, n, comparisons_n);
            break;
        case 2:
            comparisons_n = 0;
            power_O_log_n(x, n, comparisons_n);
            break;
        case 3:
            printf("Exiting...");
            return 0;
        default:
            printf("Invalid");
            break;
        }
    } while (1);

    return 0;
}