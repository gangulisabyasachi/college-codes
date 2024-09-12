/*Write a program to read in a line of text and count the number of blank
spaces, tabs and new lines in that line. Also rewrite the line of text with tabs
and new lines replaced by the visible sequences ‘\t’ ‘\n’*/

#include <stdio.h>
#include <string.h>
int main() {
  char line[100];
  int spaces = 0, tabs = 0, new_lines = 0, i;
  printf("Enter a line of text: ");
  fgets(line, sizeof(line), stdin);
  for (i = 0; i < strlen(line); i++) {
    if (line[i] == ' ') {
      spaces++;
    } else if (line[i] == '\t') {
      tabs++;
    } else if (line[i] == '\n') {
      new_lines++;
    }
  }
  for (i = 0; i < strlen(line); i++) {
    if (line[i] == '\t')
      printf("\\t");
    else if (line[i] == '\n')
      printf("\\n");
    else
      printf("%c", line[i]);
  }
  printf("\n");
  printf("Number of spaces: %d\n", spaces);
  printf("Number of tabs: %d\n", tabs);
  printf("Number of new lines: %d\n", new_lines);
  return 0;
}

/*
Output
Enter a line of text: Hello word
Hello word\n
Number of spaces: 1
Number of tabs: 0
Number of new lines: 1
*/