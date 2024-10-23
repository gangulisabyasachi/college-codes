#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Max Heapify function
void maxHeapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        maxHeapify(arr, n, largest);
    }
}

// Function to build a Max Heap
void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Heap sort function
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    buildMaxHeap(arr, n);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call maxHeapify on the reduced heap
        maxHeapify(arr, i, 0);
    }
}

// Min Heap node structure for merging arrays
struct MinHeapNode {
    int element;  // The element to be stored
    int i;        // Index of the array from which the element is taken
    int j;        // Index of the next element to be picked from the array
};

// Function to swap two MinHeapNode structures
void swapMinHeapNode(struct MinHeapNode* x, struct MinHeapNode* y) {
    struct MinHeapNode temp = *x;
    *x = *y;
    *y = temp;
}

// A function to heapify the node at index 'i' in a min heap of size 'heap_size'
void minHeapify(struct MinHeapNode harr[], int i, int heap_size) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap_size && harr[left].element < harr[smallest].element)
        smallest = left;

    if (right < heap_size && harr[right].element < harr[smallest].element)
        smallest = right;

    if (smallest != i) {
        swapMinHeapNode(&harr[i], &harr[smallest]);
        minHeapify(harr, smallest, heap_size);
    }
}

// Function to merge k sorted arrays using a min heap
int* mergeKSortedArrays(int arr[][MAX], int k, int n) {
    // Create a min heap of size k to store the first element of each array
    struct MinHeapNode* harr = (struct MinHeapNode*)malloc(k * sizeof(struct MinHeapNode));

    // Output array of size n*k
    int* output = (int*)malloc(n * k * sizeof(int));

    // Initialize the min heap with the first element of each array
    for (int i = 0; i < k; i++) {
        harr[i].element = arr[i][0];  // Store the first element
        harr[i].i = i;  // Index of the array
        harr[i].j = 1;  // Index of the next element to be picked from array
    }

    // Build the min heap
    for (int i = (k - 1) / 2; i >= 0; i--) {
        minHeapify(harr, i, k);
    }

    // Now one by one extract the minimum element from heap and replace it with the next element
    for (int count = 0; count < n * k; count++) {
        // Get the minimum element and store it in the output array
        output[count] = harr[0].element;

        // Find the next element to be replaced
        if (harr[0].j < n) {
            harr[0].element = arr[harr[0].i][harr[0].j];
            harr[0].j++;
        } else {
            harr[0].element = INT_MAX;  // No more elements in this array
        }

        // Heapify the root
        minHeapify(harr, 0, k);
    }

    free(harr);
    return output;
}

// Main function for menu-driven implementation
int main() {
    int choice;
    int arr[MAX], n;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Build Max Heap and Perform Heap Sort\n");
        printf("2. Merge K Sorted Arrays using Min Heap\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                printf("Enter the elements:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                heapSort(arr, n);
                printf("Sorted array: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 2: {
                int k, arrayLen;
                printf("Enter the number of arrays (k): ");
                scanf("%d", &k);

                printf("Enter the number of elements in each array: ");
                scanf("%d", &arrayLen);

                int arrays[k][MAX];  // Max size is set to MAX for simplicity

                for (int i = 0; i < k; i++) {
                    printf("Enter elements for array %d (sorted):\n", i + 1);
                    for (int j = 0; j < arrayLen; j++) {
                        scanf("%d", &arrays[i][j]);
                    }
                }

                // Merge the sorted arrays
                int* mergedArr = mergeKSortedArrays(arrays, k, arrayLen);

                // Print the merged array
                printf("Merged array: ");
                for (int i = 0; i < k * arrayLen; i++) {
                    printf("%d ", mergedArr[i]);
                }
                printf("\n");

                free(mergedArr);  // Free the allocated memory
                break;
            }

            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    }

    return 0;
}
