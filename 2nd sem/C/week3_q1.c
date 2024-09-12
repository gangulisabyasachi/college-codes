//Write a program to check whether a year (user input) is Leap Year or not.

#include <stdio.h>

int main() {
  int year;
  printf("Enter a year: ");
  scanf("%d", &year);
  

  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    printf("%d is a Leap Year.", year);
  } else {
    printf("%d is not a Leap Year.", year);
  }

  return 0;
}

/*
Output

Enter a year: 2020
2020 is a Leap Year.

Enter a year: 2100
2100 is not a Leap Year.*/