/* demo.c: Accepts a range, calls pro1 to get the sum,
           and calls pro2 to check if the sum is prime. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // 1. Validate arguments for demo.c
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <low> <high>\n", argv[0]);
        return 1;
    }
    printf("Controller: Starting process for range [%s, %s].\n", argv[1], argv[2]);

    // 2. Set up pipe and fork to call pro1
    int pipe1[2];
    if (pipe(pipe1) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        return 1;
    }

    long long sum_res;

    if (pid1 == 0) { // --- Child Process (pro1) ---
        close(pipe1[0]);               // Close unused read end of the pipe
        dup2(pipe1[1], STDOUT_FILENO); // Redirect stdout to the pipe's write end
        close(pipe1[1]);               // Close the original write end

        // Execute pro1
        execlp("./pro1", "pro1", argv[1], argv[2], NULL);
        perror("execlp pro1"); // execlp only returns on error
        exit(1);
    } else { // --- Parent Process (demo.c) ---
        close(pipe1[1]); // Close unused write end

        // Read the sum from pro1's output via the pipe
        char buffer[32];
        read(pipe1[0], buffer, sizeof(buffer) - 1);
        close(pipe1[0]);
        wait(NULL); // Wait for the child (pro1) to finish

        sum_res = atoll(buffer);
        printf("Controller: Received sum from pro1 -> %lld\n", sum_res);
    }
    
    // 3. Convert sum to string to pass to pro2
    char sum_str[32];
    snprintf(sum_str, sizeof(sum_str), "%lld", sum_res);

    printf("Controller: Calling pro2 to check if %lld is prime...\n", sum_res);

    // 4. Fork and call pro2
    pid_t pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        return 1;
    }

    if (pid2 == 0) { // --- Child Process (pro2) ---
        execlp("./pro2", "pro2", sum_str, NULL);
        perror("execlp pro2"); // execlp only returns on error
        exit(1);
    } else { // --- Parent Process (demo.c) ---
        int status;
        waitpid(pid2, &status, 0); // Wait for pro2 and get its status

        // 5. Check the exit status of pro2
        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            if (exit_status == 0) {
                printf("Result: %lld is a Prime number.\n", sum_res);
            } else if (exit_status == 1) {
                printf("Result: %lld is NOT a Prime number.\n", sum_res);
            } else {
                fprintf(stderr, "Controller: pro2 exited with an error code: %d\n", exit_status);
            }
        }
    }

    return 0;
}


// gcc pro1.c -o pro1
// gcc pro2.c -o pro2 -lm
// gcc demo.c -o demo

// ./demo 1 2