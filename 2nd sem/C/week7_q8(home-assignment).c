

#include <stdio.h>
#include <string.h>

void strncpy_func(char *dest, const char *src, int n) {
  if (dest == NULL || src == NULL || n <= 0) {
    printf("Error: Invalid arguments\n");
    return;
  }
  int i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  dest[i] = '\0'; // Null terminate the destination string
}

void strcat_func(char *dest, const char *src) {
  if (dest == NULL || src == NULL) {
    printf("Error: Invalid arguments\n");
    return;
  }
  int i = strlen(dest);
  int j;
  for (j = 0; src[j] != '\0'; i++, j++) {
    dest[i] = src[j];
  }
  dest[i] = '\0'; // Null terminate the destination string
}

void strncat_func(char *dest, const char *src, int n) {
  if (dest == NULL || src == NULL || n <= 0) {
    printf("Error: Invalid arguments\n");
    return;
  }
  int i = strlen(dest);
  int j;
  for (j = 0; j < n && src[j] != '\0'; i++, j++) {
    dest[i] = src[j];
  }
  dest[i] = '\0'; // Null terminate the destination string
}

int strcmp_func(const char *str1, const char *str2) {
  if (str1 == NULL || str2 == NULL) {
    printf("Error: Invalid arguments\n");
    return -2;
  }
  int i = 0;
  while (str1[i] == str2[i]) {
    if (str1[i] == '\0') {
      return 0; // Strings are equal
    }
    i++;
  }
  return str1[i] - str2[i];
}

char *strtok_func(char *str, const char *delim) {
  static char *ptr;
  if (delim == NULL) {
    printf("Error: Invalid delimiter\n");
    return NULL;
  }
  if (str != NULL) {
    ptr = str;
  }
  if (ptr == NULL || *ptr == '\0') {
    return NULL;
  }
  char *start = ptr;
  char *end = strpbrk(ptr, delim);
  if (end != NULL) {
    *end = '\0';
    ptr = end + 1;
  } else {
    ptr = NULL;
  }
  return start;
}

int main(void) {
  char str1[100], str2[100], delim[10];
  int n;

  printf("Enter the string 1: ");
  scanf("%s", str1);
  printf("Enter the string 2: ");
  scanf("%s", str2);

  printf("Enter the number of characters to be copied: ");
  scanf("%d", &n);
  strncpy_func(str1, str2, n);
  printf("The copied string is: %s\n", str1);

  strcat_func(str1, str2);
  printf("The concatenated string is: %s\n", str1);

  printf("Enter the number of characters to be concatenated: ");
  scanf("%d", &n);
  strncat_func(str1, str2, n);
  printf("The concatenated string is: %s\n", str1);

  printf("Enter the string 1: ");
  scanf("%s", str1);
  printf("Enter the string 2: ");
  scanf("%s", str2);

  int result = strcmp_func(str1, str2);
  if (result == 0) {
    printf("The strings are equal\n");
  } else {
    printf("The strings are not equal\n");
  }

  printf("Enter the string: ");
  scanf("%s", str1);
  printf("Enter the delimiter: ");
  scanf("%s", delim);

  char *token = strtok_func(str1, delim);
  while (token != NULL) {
    printf("%s\n", token);
    token = strtok_func(NULL, delim);
  }

  return 0;
}