#include <stdio.h>

int comparisons_iterative = 0;  // Counter for comparisons in iterative binary search

// Iterative binary search function
int binarySearchIterative(int arr[], int low, int high, int key) {
    while (low <= high) {
        comparisons_iterative++;  // Increment comparison counter
        int mid = low + (high - low) / 2;

        // If key is present at mid
        if (arr[mid] == key) {
            return mid;
        }

        // If key is smaller than mid
        if (arr[mid] > key) {
            high = mid - 1;
        }
        // If key is larger than mid
        else {
            low = mid + 1;
        }
    }
    return -1;  // If the key is not present
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};  // Example sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Testing Iterative Binary Search
    comparisons_iterative = 0;  // Reset comparison count for iterative search
    int result_iterative = binarySearchIterative(arr, 0, size - 1, key);

    if (result_iterative != -1) {
        printf("Iterative Binary Search: Element found at index %d\n", result_iterative);
    } else {
        printf("Iterative Binary Search: Element not found\n");
    }
    printf("Comparisons in iterative search: %d\n", comparisons_iterative);

    return 0;
}
