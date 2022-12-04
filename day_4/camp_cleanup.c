// problem: https://adventofcode.com/2022/day/4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LIMIT 20

int get_line(char line[], int limit);
int contains_range(int list[2][2]);
int does_overlap(int list[2][2]);

int main() {
    int assignments[2][2] = {0}, counter = 0;
    char line[LINE_LIMIT], *sections[2], *assignment;
    while (get_line(line, LINE_LIMIT) > 0) {
        sections[0] = strtok(line, ",");
        sections[1] = strtok(NULL, ",");
        for (int i = 0; i < 2; i++) {
            assignment = strtok(sections[i], "-");
            assignments[i][0] = atoi(assignment);
            assignment = strtok(NULL, "-");
            assignments[i][1] = atoi(assignment);
        }
        if (does_overlap(assignments))
            ++counter;
    }
    printf("%d\n", counter);
    return 0;
}

int does_overlap(int list[2][2]) {
    if ((list[1][0] >= list[0][0] && list[1][0] <= list[0][1]) ||
            (list[0][0] >= list[1][0] && list[0][0] <= list[1][1]))
        return 1;
    else
        return 0;
}

int contains_range(int list[2][2]) {
    if ((list[0][0] <= list[1][0] && list[0][1] >= list[1][1]) ||
            (list[0][0] >= list[1][0] && list[0][1] <= list[1][1]))
        return 1;
    else
        return 0;
}

int get_line(char line[], int limit) {
    int i, c;
    for (i = 0; i < limit - 1; i++) {
        c = getchar();
        if (c == EOF || c == '\n')
            break;
        line[i] = c;
    }
    line[i] = '\0';
    return i;
}
