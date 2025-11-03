#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1, pid2;

    printf("Original Parent (Grandparent): pid=%d\n", getpid());

    if ((pid1 = fork()) == 0)
    {
        // First child (Parent)
        printf("Process 1 (Parent): pid=%d, ppid=%d\n", getpid(), getppid());

        if ((pid2 = fork()) == 0)
        {
            // Second child (Grandchild)
            printf("Process 2 (Child): pid=%d, ppid=%d\n", getpid(), getppid());
            exit(0);
        }
        else if (pid2 > 0)
        {
            // First child waits for grandchild
            wait(NULL);
            printf("Process 1 (Parent): child=%d finished.\n", pid2);
            exit(0);
        }
        else
        {
            perror("Fork failed");
            exit(1);
        }
    }
    else if (pid1 > 0)
    {
        // Original parent waits for first child
        wait(NULL);
        printf("Original Parent (Grandparent): child=%d finished.\n", pid1);
    }
    else
    {
        perror("Fork failed");
        exit(1);
    }

    return 0;
}
