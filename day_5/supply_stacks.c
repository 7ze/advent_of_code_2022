// problem: https://adventofcode.com/2022/day/5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LIMIT 100
#define STACK_SIZE 90

char pop_element(char str[]);
void add_element(char str[], char element);
int get_line(char line[], int limit);

int main() {
    int INSTRUCTION_FLAG = 0, length, n, src, dest;
    char line[LINE_LIMIT] = {'\0'}, *i, crate;
    char stacks[9][STACK_SIZE] = {"FCJPHTW", "GRVFZJBH", "HPTR", "ZSNPHT", "NVFZHJCD",
        "PMGFWDZ", "MVZWSJDP", "NDS",  "DZSFM"};
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
            for (int j = 0; j < n; j++) {
                crate = pop_element(stacks[src]);
                if (!crate) {
                    printf("Error. Stack empty!\n");
                    return 1;
                }
                add_element(stacks[dest], crate);
            }
        }
        if (length == 1) {
            INSTRUCTION_FLAG = 1;
        }
    }
    int last_element_position;
    for(int i = 0; i<9; i++) {
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
    }
    else {
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
