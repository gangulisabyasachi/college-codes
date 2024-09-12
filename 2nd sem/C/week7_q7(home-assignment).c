/*Write a program to read a line of text and count the number of words and
  characters in that text.*/

#include <stdio.h>
#include <string.h>

int main() {
  char line[1000];
  int words = 0, characters = 0;

  printf("Enter a line of text: ");
  fgets(line, sizeof(line), stdin);

  // Counting words and characters
  for (int i = 0; line[i] != '\0'; i++) {
    // Increment character count if not space or newline
    if (line[i] != ' ' && line[i] != '\n') {
      characters++;
    }
    // Increment word count if space or newline
    if (line[i] == ' ' || line[i] == '\n') {
      words++;
    }
  }

  printf("Number of words: %d\n", words);
  printf("Number of characters: %d\n", characters);

  return 0;
}

/*
Output
Enter a line of text: Hello
Number of words: 1
Number of characters: 5
*/