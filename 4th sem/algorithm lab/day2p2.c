#include <stdio.h>

// Function to perform insertion sort and count comparisons
int insertionSort(int arr[], int n) {
    int i, j, key, comparisons = 0;
    
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Compare and shift elements
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            comparisons++; // Count comparisons inside loop
        }
        arr[j + 1] = key;

        if (j >= 0) { 
            comparisons++; // Count last comparison when loop exits
        }
    }
    return comparisons;
}

// Function to take user input for an array
void inputArray(int arr[], int n) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 10, choice;
    int arr[10], sortedArr[10], reverseArr[10], randomArr[10];

    printf("Enter 10 elements:\n");
    inputArray(arr, n);

    do {
        printf("\nMenu:\n");
        printf("1. Sort and Display Array\n");
        printf("2. Check Comparisons (Sorted Order)\n");
        printf("3. Check Comparisons (Reverse Order)\n");
        printf("4. Check Comparisons (Random Order)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Sort and display array
                for (int i = 0; i < n; i++) sortedArr[i] = arr[i];
                insertionSort(sortedArr, n);
                printf("Sorted Array: ");
                printArray(sortedArr, n);
                break;

            case 2:  // Check comparisons for sorted order
                for (int i = 0; i < n; i++) sortedArr[i] = arr[i];
                int sortedComparisons = insertionSort(sortedArr, n);
                printf("Comparisons (Sorted Order): %d\n", sortedComparisons);
                break;

            case 3:  // Check comparisons for reverse order
                for (int i = 0; i < n; i++) reverseArr[i] = arr[n - 1 - i];
                int reverseComparisons = insertionSort(reverseArr, n);
                printf("Comparisons (Reverse Order): %d\n", reverseComparisons);
                break;

            case 4:  // Check comparisons for random order (original input)
                for (int i = 0; i < n; i++) randomArr[i] = arr[i];
                int randomComparisons = insertionSort(randomArr, n);
                printf("Comparisons (Random Order): %d\n", randomComparisons);
                break;

            case 5:  // Exit
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
