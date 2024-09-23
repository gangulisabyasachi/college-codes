/*Write a recursive function to find the maximum and minimum of a list of numbers*/

#include <math.h>
#include <stdio.h>

int findMax(int arr[], int size);
int findMin(int arr[], int size);

int main() {
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int arr[size], i;
  printf("Enter the elements of the array: ");
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }
  int max = findMax(arr, size);
  int min = findMin(arr, size);
  printf("Maximum element: %d\n", max);
  printf("Minimum element: %d\n", min);
  return 0;
}

int findMax(int arr[], int size) {
  if (size == 1)
    return arr[0];
  else {
    int max_of_rest = findMax(arr, size - 1);
    return (arr[size - 1] > max_of_rest) ? arr[size - 1] : max_of_rest;
  }
}

int findMin(int arr[], int size) {
  if (size == 1)
    return arr[0];
  else {
    int min_of_rest = findMin(arr, size - 1);
    return (arr[size - 1] < min_of_rest) ? arr[size - 1] : min_of_rest;
  }
}

/*
Output
Enter the size of the array: 5
Enter the elements of the array: 1
3
2
9
43
Maximum element: 43
Minimum element: 1
*/