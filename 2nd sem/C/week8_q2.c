/*Write a program, using pointers, that accepts a string and converts all its
characters to upper or lower case*/
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main(void) {
  char str[100];
  char *p;
  int i;
  printf("Enter a string: ");
  scanf("%[^\n]s", str);
  p = str;
  for (i = 0; i < strlen(str); i++) {
    if (islower(*p))
      *p = toupper(*p);
    else if (isupper(*p))
      *p = tolower(*p);
    p++;
  }
  printf("Converted string: %s", str);
  return 0;
}

/*
Output
Enter a string: HeLlO GaIj
Converted string: hElLo gAiJ
*/