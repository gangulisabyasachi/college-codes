#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random permutation of 0 to n-1
void generateRandomPermutation(int arr[], int n) {
    // Fill the array with numbers from 0 to n-1
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    // Fisher-Yates Shuffle to generate a random permutation
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Partition function for First Element as Pivot
int partition_first(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high;

    // Partitioning the array around the pivot
    while (i <= j) {
        while (i <= high && arr[i] <= pivot) i++; // Move i to the right
        while (j >= low && arr[j] > pivot) j--;  // Move j to the left
        if (i < j) {
            // Swap elements at i and j
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap pivot with element at j
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j; // Return pivot index
}

// QuickSort using First Element as Pivot
void quickSort_first(int arr[], int low, int high) {
    if (low < high) {
        int p = partition_first(arr, low, high); // Partition the array
        quickSort_first(arr, low, p - 1);  // Sort left part
        quickSort_first(arr, p + 1, high); // Sort right part
    }
}

// Partition function for Random Pivot
int partition_random(int arr[], int low, int high) {
    // Randomly select a pivot and swap with the first element
    int randomIndex = low + rand() % (high - low + 1);
    int temp = arr[low];
    arr[low] = arr[randomIndex];
    arr[randomIndex] = temp;

    // Call the partition function (same as first element pivot)
    return partition_first(arr, low, high);
}

// QuickSort using Random Pivot
void quickSort_random(int arr[], int low, int high) {
    if (low < high) {
        int p = partition_random(arr, low, high); // Partition with random pivot
        quickSort_random(arr, low, p - 1);  // Sort left part
        quickSort_random(arr, p + 1, high); // Sort right part
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to test the sorting algorithms and measure time
void testSortingAlgorithms(int n) {
    int arr1[n], arr2[n];
    srand(time(NULL)); // Seed for randomness

    // Generate random permutation for both arrays
    generateRandomPermutation(arr1, n);
    for (int i = 0; i < n; i++) {
        arr2[i] = arr1[i]; // Copy arr1 to arr2 for fair comparison
    }

    printf("Random Permutation:\n");
    printArray(arr1, n);

    // Measure time for QuickSort with First Element as Pivot
    clock_t start = clock();
    quickSort_first(arr1, 0, n - 1);
    clock_t end = clock();
    double time_first = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted using First Element Pivot:\n");
    printArray(arr1, n);
    printf("Time Taken (First Element Pivot): %.8f seconds\n", time_first);

    // Measure time for QuickSort with Random Pivot
    start = clock();
    quickSort_random(arr2, 0, n - 1);
    end = clock();
    double time_random = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted using Random Pivot:\n");
    printArray(arr2, n);
    printf("Time Taken (Random Pivot): %.8f seconds\n", time_random);
}

int main() {
    int n = 10; // Size of the array
    testSortingAlgorithms(n); // Test sorting algorithms and measure performance
    return 0;
}
