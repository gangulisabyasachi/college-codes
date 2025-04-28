/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_1 10000
#define SIZE_2 100000
#define SIZE_3 1000000

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

// Function to fill array with ordered numbers
void fillArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

// Function to sort and measure comparisons
void sortAndMeasure(int size, int pivotType) {
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    fillArray(arr, size);

    comparisons = 0;
    quickSort(arr, 0, size - 1, pivotType);

    double avgComparisons = (double)comparisons / size;

    // Printing the result
    printf("| %10d | %-16s | %12lld | %17.3f |\n", 
        size,
        (pivotType == 1) ? "First Element" :
        (pivotType == 2) ? "Last Element" : "Random Element",
        comparisons,
        avgComparisons
    );

    free(arr);
}

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator

    printf("-----------------------------------------------------------------------------\n");
    printf("|  Array Size |    Pivot Type    | Comparisons  | Avg. Comparisons/Element |\n");
    printf("-----------------------------------------------------------------------------\n");

    int sizes[] = {SIZE_1, SIZE_2, SIZE_3};

    for (int i = 0; i < 3; i++) {
        sortAndMeasure(sizes[i], 1); // First Element as Pivot
        sortAndMeasure(sizes[i], 2); // Last Element as Pivot
        sortAndMeasure(sizes[i], 3); // Random Element as Pivot
    }

    printf("-----------------------------------------------------------------------------\n");

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_1 10000
#define SIZE_2 100000
#define SIZE_3 1000000

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

        quickSort(arr, low, pIndex - 1, pivotType); // Sort left part
        quickSort(arr, pIndex + 1, high, pivotType); // Sort right part
    }
}

// Function to fill array with ordered numbers
void fillArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

// Function to sort and measure comparisons
void sortAndMeasure(int size, int pivotType) {
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed for size %d!\n", size);
        return;
    }

    fillArray(arr, size);

    comparisons = 0;
    quickSort(arr, 0, size - 1, pivotType);

    double avgComparisons = (double)comparisons / size;

    // Printing the result
    printf("| %10d | %-16s | %12lld | %17.3f |\n", 
        size,
        (pivotType == 1) ? "First Element" :
        (pivotType == 2) ? "Last Element" : "Random Element",
        comparisons,
        avgComparisons
    );

    free(arr);
}

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator

    printf("-----------------------------------------------------------------------------\n");
    printf("|  Array Size |    Pivot Type    | Comparisons  | Avg. Comparisons/Element |\n");
    printf("-----------------------------------------------------------------------------\n");

    int sizes[] = {SIZE_1, SIZE_2, SIZE_3};

    for (int i = 0; i < 3; i++) {
        sortAndMeasure(sizes[i], 1); // First Element as Pivot
        sortAndMeasure(sizes[i], 2); // Last Element as Pivot
        sortAndMeasure(sizes[i], 3); // Random Element as Pivot
    }

    printf("-----------------------------------------------------------------------------\n");

    return 0;
}
