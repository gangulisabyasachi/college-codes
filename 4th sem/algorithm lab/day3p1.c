#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp = 0; // Global variable to count comparisons

// Function to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Merge function to combine two sorted halves
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Allocate memory dynamically to avoid stack overflow
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    // Merge the two arrays back into arr[l...r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        comp++; // Counting comparisons
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    // Copy remaining elements of L[], if any
    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    // Copy remaining elements of R[], if any
    while (j < n2)
    {
        arr[k++] = R[j++];
    }

    // Free allocated memory
    free(L);
    free(R);
}

// Merge Sort function
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2; // Avoids integer overflow
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Function to take input from the user
void getUserInput(int arr[], int n)
{
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

// Function to generate random numbers
void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100; // Random numbers between 0-99
    }
}

// Main function
int main()
{
    int n, choice;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(NULL));

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Enter elements in sorted order (Best Case)\n");
        printf("2. Enter elements in reverse order (Worst Case)\n");
        printf("3. Generate random elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        { // Best Case: Sorted order
            comp = 0;
            printf("Enter %d sorted elements:\n", n);
            getUserInput(arr, n);
        }
        else if (choice == 2)
        { // Worst Case: Reverse order
            comp = 0;
            printf("Enter %d elements in reverse order:\n", n);
            getUserInput(arr, n);
        }
        else if (choice == 3)
        { // Random Case
            comp = 0;
            generateRandomArray(arr, n);
            printf("Randomly generated array:\n");
            printArray(arr, n);
        }
        else if (choice == 4)
        { // Exit
            printf("Exiting program.\n");
            break;
        }
        else
        {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        printf("Original Array: ");
        printArray(arr, n);

        mergeSort(arr, 0, n - 1);

        printf("Sorted Array: ");
        printArray(arr, n);
        printf("Total Comparisons: %d\n", comp);
    }

    return 0;
}