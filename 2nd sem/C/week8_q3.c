/*Write three functions, using pointers, to concatenate two strings, to compare
  two strings and to reverse a string, respectively. Test these functions in a
  complete program.*/

#include <stdio.h>
#include <string.h>

char *concatenate(char *p, char *q) {
  strcat(p, q);
  return (p);
}

void reverse(char *p) {
  int len = strlen(p);
  int i, j;
  for (i = 0, j = len - 1; i <= j; i++, j--) { 
    char c = p[i];
    p[i] = p[j];
    p[j] = c;
  }
  printf("\nReversed string is: %s", p);
}

void compare(char *p, char *q) {
  int i;
  i = strcmp(p, q);
  if (i == 0) {
    printf("\nStrings are equal");
  }
  if (i > 0) {
    printf("\nString 1 is greater than string 2");
  }
  if (i < 0) {
    printf("\nString 1 is less than string 2");
  }
}

int main() {
  char p[50];
  char q[50];
  printf("Enter the first string: ");
  scanf("%s", p);
  printf("Enter the second string: ");
  scanf("%s", q);
  concatenate(p, q);
  printf("\nConcatenated string is: %s", p);
  reverse(p);
  compare(p, q);
  return 0;
}

/*
Output
Enter the first string: Asmita
Enter the second string: Banerjee

Concatenated string is: AsmitaBanerjee
Reversed string is: eejrenaBatimsA
String 1 is greater than string 2
*/