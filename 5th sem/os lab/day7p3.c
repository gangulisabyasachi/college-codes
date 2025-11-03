#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 100

// Global array and its size
int a[MAX];
int n;

// Struct to pass the range (low and high index) to the sorting threads
typedef struct {
    int low;
    int high;
} range;

// Merge function to combine two sorted subarrays
void mrg(int l, int m, int h) {
    int n1 = m - l + 1;
    int n2 = h - m;

    // Create temporary arrays
    int left[n1], right[n2];
    int i, j;

    // Copy data to temp arrays left[] and right[]
    for (i = 0; i < n1; i++)
        left[i] = a[l + i];
    for (j = 0; j < n2; j++)
        right[j] = a[m + 1 + j];

    // Merge the temp arrays back into a[l..h]
    i = 0;    // Initial index of first subarray
    j = 0;    // Initial index of second subarray
    int k = l; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            a[k++] = left[i++];
        } else {
            a[k++] = right[j++];
        }
    }

    // Copy the remaining elements of left[], if there are any
    while (i < n1) {
        a[k++] = left[i++];
    }

    // Copy the remaining elements of right[], if there are any
    while (j < n2) {
        a[k++] = right[j++];
    }
}

// Standard recursive merge sort function
void msort(int l, int h) {
    if (l < h) {
        int m = l + (h - l) / 2; // Avoids overflow for large l, h
        msort(l, m);
        msort(m + 1, h);
        mrg(l, m, h);
    }
}

// Thread function to sort a part of the array
void *tsort(void *arg) {
    range *r = (range *)arg;
    msort(r->low, r->high);
    return NULL;
}

// Thread function to merge the two sorted halves
void *mgh(void *arg) {
    // Merge the first half (0 to n/2 - 1) and the second half (n/2 to n-1)
    mrg(0, (n / 2) - 1, n - 1);
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Define the ranges for the two halves of the array
    range r1 = {0, (n / 2) - 1};
    range r2 = {n / 2, n - 1};

    // Create two threads to sort the two halves concurrently
    pthread_create(&t1, NULL, tsort, &r1);
    pthread_create(&t2, NULL, tsort, &r2);

    // Wait for both sorting threads to complete
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Create a third thread to merge the sorted halves
    pthread_create(&t3, NULL, mgh, NULL);
    
    // Wait for the merging thread to complete
    pthread_join(t3, NULL);

    printf("Sorted: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");

    return 0;
}

// Enter size: 8
// Enter elements:
// 80 10 30 90 40 50 70 20
// Sorted: 10	20	30	40	50	70	80	90