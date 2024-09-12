/*Write a program to read a line of text from the keyboard and convert it into a coded
text by changing its characters by adding a code number to them. This code number
must be taken as input. For checking the correctness of your program, you should get
your original text back after encoding.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

void encodeText(char text[], int code) {
  int i;
  for (i = 0; text[i] != '\0'; i++) {
    if (text[i] != ' ') {
      text[i] += code;
    }
  }
}

void decodeText(char text[], int code) {
  int i;
  for (i = 0; text[i] != '\0'; i++) {
    if (text[i] != ' ') {
      text[i] -= code;
    }
  }
}

int main() {
  char text[MAX_LENGTH];
  int code;
  printf("Enter a line of text: ");
  fgets(text, MAX_LENGTH, stdin);
  text[strcspn(text, "\n")] = '\0';
  printf("Enter a code number: ");
  scanf("%d", &code);
  encodeText(text, code);
  printf("Encoded text: %s\n", text);
  decodeText(text, code);
  printf("Decoded text: %s\n", text);
  return 0;
}

/*
Output
Enter a line of text: hello 
Enter a code number: 3
Encoded text: khoor
Decoded text: hello
*/