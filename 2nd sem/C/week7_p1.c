/*Write a menu driven program to find the max, min, average, standard deviation
of the elements of an integer array using separate functions*/
#include <math.h>
#include <stdio.h>
#define MAX_SIZE 100
int main() {
  int arr[MAX_SIZE];
  int size, i;
  float sum, mean, variance, std_deviation;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  printf("Enter the elements of the array: ");
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }
  // Find the maximum element 
  int max = arr[0];
  for (i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  printf("Maximum element: %d\n", max);
  // Find the minimum element
  int min = arr[0];
  for (i = 1; i < size; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  printf("Minimum element: %d\n", min);
  // Find the average of the elements
  sum = 0;
  for (i = 0; i < size; i++) {
    sum += arr[i];
  }
  mean = sum / size;
  printf("Average: %.2f\n", mean);
  // Find the variance of the elements
  sum = 0;
  for (i = 0; i < size; i++) {
    sum += pow(arr[i] - mean, 2);
  }
  variance = sum / size;
  printf("Variance: %.2f\n", variance);
  // Find the standard deviation of the elements
  std_deviation = sqrt(variance);
  printf("Standard deviation: %.2f\n", std_deviation);
  return 0;
}

/*
Output
Enter the size of the array: 5
Enter the elements of the array: 1
2
4
2
99
Maximum element: 99
Minimum element: 1
Average: 21.60
Variance: 1498.64
Standard deviation: 38.71
*/