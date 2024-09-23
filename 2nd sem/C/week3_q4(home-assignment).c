/*Consider a currency system in which there are notes of six denominations, namely, Re.1, Rs.
2, Rs.5, Rs.10, Rs. 50 and Rs. 100. If a sum of Rs. N is entered through the keyboard, write a
program to compute the smallest number of notes that will combine to give Rs. N.*/

#include <stdio.h>

int main() {
  int amount, notes = 0;

  printf("Enter the amount in rupees: ");
  scanf("%d", &amount);

  // Count Rs. 100 notes
  notes += amount / 100;
  amount %= 100;

  // Count Rs. 50 notes
  notes += amount / 50;
  amount %= 50;

  // Count Rs. 10 notes
  notes += amount / 10;
  amount %= 10;

  // Count Rs. 5 notes
  notes += amount / 5;
  amount %= 5;

  // Count Rs. 2 notes
  notes += amount / 2;
  amount %= 2;

  // Count Rs. 1 notes
  notes += amount;

  printf("The smallest number of notes required: %d\n", notes);

  return 0;
}

/*
Output
Enter the amount in rupees: 5000
The smallest number of notes required: 50
*/