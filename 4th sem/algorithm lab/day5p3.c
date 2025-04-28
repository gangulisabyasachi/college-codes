#include <stdio.h>

int comparisons_recursive = 0;  // Counter for comparisons in recursive binary search

// Recursive binary search function
int binarySearchRecursive(int arr[], int low, int high, int key) {
    // Base case: If the range is valid
    if (low <= high) {
        comparisons_recursive++;  // Increment comparison counter
        int mid = low + (high - low) / 2;

        // If key is present at mid
        if (arr[mid] == key) {
            return mid;
        }

        // If key is smaller than mid
        if (arr[mid] > key) {
            return binarySearchRecursive(arr, low, mid - 1, key);
        }
        // If key is larger than mid
        else {
            return binarySearchRecursive(arr, mid + 1, high, key);
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

    // Testing Recursive Binary Search
    comparisons_recursive = 0;  // Reset comparison count for recursive search
    int result_recursive = binarySearchRecursive(arr, 0, size - 1, key);

    if (result_recursive != -1) {
        printf("Recursive Binary Search: Element found at index %d\n", result_recursive);
    } else {
        printf("Recursive Binary Search: Element not found\n");
    }
    printf("Comparisons in recursive search: %d\n", comparisons_recursive);

    return 0;
}
