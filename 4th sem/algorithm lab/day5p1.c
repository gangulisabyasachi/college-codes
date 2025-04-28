#include <stdio.h>

// Recursive function to solve the Towers of Hanoi problem
void solveTowersOfHanoi(int n, char source, char destination, char auxiliary) {
    // Base case: If only one disk is left, move it directly
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary, so they are out of the way
    solveTowersOfHanoi(n - 1, source, auxiliary, destination);

    // Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move the n-1 disks from auxiliary to destination
    solveTowersOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;

    // Taking user input for the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Solving the Towers of Hanoi problem
    printf("\nThe moves required to solve the Towers of Hanoi problem are:\n");
    solveTowersOfHanoi(n, 'A', 'C', 'B'); // 'A' is the source, 'C' is the destination, and 'B' is the auxiliary pole

    return 0;
}

