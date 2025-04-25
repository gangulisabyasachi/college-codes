#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define LARGE_SIZE 10000  // Large dataset size

long long comparisons = 0; // Global counter for comparisons

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (first element as pivot)
int partition_first(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) {
            comparisons++;
            i++;
        }
        while (j >= low && arr[j] > pivot) {
            comparisons++;
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

// Partition function (last element as pivot)
int partition_last(int arr[], int low, int high) {
    swap(&arr[low], &arr[high]); // Move pivot to first position
    return partition_first(arr, low, high);
}

// Partition function (random element as pivot)
int partition_random(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(&arr[low], &arr[randomIndex]); // Move random pivot to first position
    return partition_first(arr, low, high);
}

// Quick Sort function
void quickSort(int arr[], int low, int high, int pivotType) {
    if (low < high) {
        int pIndex;
        if (pivotType == 1)
            pIndex = partition_first(arr, low, high);
        else if (pivotType == 2)
            pIndex = partition_last(arr, low, high);
        else
            pIndex = partition_random(arr, low, high);

        quickSort(arr, low, pIndex - 1, pivotType);
        quickSort(arr, pIndex + 1, high, pivotType);
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to measure sorting time for 10,000 elements
void sortLargeArray(int pivotChoice) {
    int arr[LARGE_SIZE];
    for (int i = 0; i < LARGE_SIZE; i++) {
        arr[i] = i + 1; // Filling array with ordered numbers 1 to 10000
    }

    comparisons = 0;
    clock_t start = clock();
    quickSort(arr, 0, LARGE_SIZE - 1, pivotChoice);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nSorting Time for 10,000 elements (Pivot: %s): %.6f seconds\n",
           (pivotChoice == 1) ? "First Element" :
           (pivotChoice == 2) ? "Last Element" : "Random Element",
           time_taken);
    printf("Total Comparisons: %lld\n", comparisons);
}

// Menu-driven function
void menu() {
    int choice, pivotChoice, outputChoice;

    while (1) {
        printf("\n========= MENU =========\n");
        printf("1. Sort 10 user-input elements\n");
        printf("2. Sort 10,000 elements (ordered 1 to 10,000) and measure time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting...\n");
            break;
        }

        printf("\n======== PIVOT SELECTION MENU ========\n");
        printf("1. First Element as Pivot\n");
        printf("2. Last Element as Pivot\n");
        printf("3. Random Element as Pivot\n");
        printf("Enter your choice: ");
        scanf("%d", &pivotChoice);

        if (pivotChoice < 1 || pivotChoice > 3) {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        if (choice == 1) { 
            int arr[MAX_SIZE];
            printf("\n====== ENTER 10 ELEMENTS ======\n");
            for (int i = 0; i < MAX_SIZE; i++) {
                printf("Element %d: ", i + 1);
                scanf("%d", &arr[i]);
            }

            comparisons = 0;
            quickSort(arr, 0, MAX_SIZE - 1, pivotChoice);
            printf("\nSorted array:\n");
            printArray(arr, MAX_SIZE);
            printf("Total Comparisons: %lld\n", comparisons);

            // Output format selection menu
            printf("\n======== OUTPUT FORMAT MENU ========\n");
            printf("1. Display Sorted Output\n");
            printf("2. Display Reverse Sorted Output\n");
            printf("3. Display Random Shuffled Output\n");
            printf("Enter your choice: ");
            scanf("%d", &outputChoice);

            if (outputChoice == 2) {
                for (int i = 0; i < MAX_SIZE / 2; i++) {
                    swap(&arr[i], &arr[MAX_SIZE - i - 1]);
                }
                printf("\nReverse Sorted Output:\n");
            } 
            else if (outputChoice == 3) {
                for (int i = MAX_SIZE - 1; i > 0; i--) {
                    int j = rand() % (i + 1);
                    swap(&arr[i], &arr[j]);
                }
                printf("\nRandom Shuffled Output:\n");
            } 
            else {
                printf("\nSorted Output:\n");
            }

            printArray(arr, MAX_SIZE);
            printf("Total Comparisons (in chosen output format): %lld\n", comparisons);

        } else if (choice == 2) {
            sortLargeArray(pivotChoice);
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator
    menu();
    return 0;
}