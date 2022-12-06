// problem: https://adventofcode.com/2022/day/5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LIMIT 100
#define STACK_SIZE 90

char pop_element(char str[]);
void add_element(char str[], char element);
int get_line(char line[], int limit);
void cut_and_join(char src[], char dest[], int position);

int main() {
  int INSTRUCTION_FLAG = 0, length, n, src, dest;
  char line[LINE_LIMIT] = {'\0'}, *i;
  char stacks[9][STACK_SIZE] = {"FCJPHTW",  "GRVFZJBH", "HPTR",
                                "ZSNPHT",   "NVFZHJCD", "PMGFWDZ",
                                "MVZWSJDP", "NDS",      "DZSFM"};
  while ((length = get_line(line, LINE_LIMIT)) > 0) {
    if (INSTRUCTION_FLAG) {
      i = strtok(line, " ");
      i = strtok(NULL, " ");
      n = atoi(i);
      i = strtok(NULL, " ");
      i = strtok(NULL, " ");
      src = atoi(i) - 1;
      i = strtok(NULL, " ");
      i = strtok(NULL, " ");
      dest = atoi(i) - 1;
      cut_and_join(stacks[src], stacks[dest], n);
    }
    if (length == 1) {
      INSTRUCTION_FLAG = 1;
    }
  }
  int last_element_position;
  for (int i = 0; i < 9; i++) {
    last_element_position = strlen(stacks[i]) - 1;
    printf("%c", stacks[i][last_element_position]);
  }
  printf("\n");
  return 0;
}

int get_line(char line[], int limit) {
  int i, c;
  for (i = 0; i < limit; i++) {
    c = getchar();
    if (c == EOF) {
      break;
    }
    line[i] = c;
    if (c == '\n') {
      ++i;
      break;
    }
  }
  line[i] = '\0';
  return i;
}

void add_element(char str[], char element) {
  int length = strlen(str);
  if (length + 1 <= STACK_SIZE) {
    str[length] = element;
  } else {
    printf("Failed to add element. Stack full.\n");
  }
  return;
}

char pop_element(char str[]) {
  char last_element = '\0';
  int length = strlen(str);
  if (length > 0) {
    last_element = str[length - 1];
    str[length - 1] = '\0';
  }
  return last_element;
}

// position is negetive indexed, ie starts from behind
void cut_and_join(char src[], char dest[], int position) {
  int src_length = strlen(src);
  int dest_length = strlen(dest);
  if (src_length >= position) {
    for (int i = 0; i < position; i++) {
      dest[dest_length + i] = src[src_length - position + i];
    }
    for (int i = src_length - position; i < STACK_SIZE; i++)
      src[i] = '\0';
  } else {
    printf("Error. Operation not possible.\n");
  }
}
