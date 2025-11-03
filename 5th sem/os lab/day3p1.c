#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

long long factorial(int n)
{
    long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <num>\n", argv[0]);
        exit(1);
    }

    int num = atoi(argv[1]);
    pid_t pid1, pid2;

    // First child - factorial of num
    if ((pid1 = fork()) == 0)
    {
        printf("Process 1 (Factorial): pid=%d, ppid=%d\n", getpid(), getppid());
        long long fact = factorial(num);
        printf("Factorial of %d = %lld\n", num, fact);
        exit(0);
    }
    else if (pid1 > 0)
    {
        // Second child - sum of factorials
        if ((pid2 = fork()) == 0)
        {
            printf("Process 2 (Sum of factorials): pid=%d, ppid=%d\n", getpid(), getppid());
            long long sum = 0;
            for (int i = 1; i <= num; i++)
                sum += factorial(i);
            printf("Sum of factorials till %d = %lld\n", num, sum);
            exit(0);
        }
        else if (pid2 > 0)
        {
            // Parent waits for both children
            int status;
            waitpid(pid1, &status, 0);
            waitpid(pid2, &status, 0);
            printf("Parent process (pid=%d) finished. Children: %d, %d\n", getpid(), pid1, pid2);
        }
        else
        {
            perror("Fork failed");
            exit(1);
        }
    }
    else
    {
        perror("Fork failed");
        exit(1);
    }

    return 0;
}
