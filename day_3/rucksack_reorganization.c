// problem: https://adventofcode.com/2022/day/3

#include <stdio.h>
#include <string.h>

#define LINE_LIMIT 100

int get_line(char line[], int limit);
int get_item_priority(char item);
int get_common_item_priority(char line1[], char line2[], char line3[]);

int main() {
    int i = 0, length, res = 0;
    char line[LINE_LIMIT] = {'\0'}, rucksacks[3][LINE_LIMIT] = {'\0'};
    while ((length = get_line(line, LINE_LIMIT)) > 0) {
        strcpy(rucksacks[i], line);
        i++;
        if (i == 3) {
            res += get_common_item_priority(rucksacks[0], rucksacks[1], rucksacks[2]);
            i = 0;
        }
    }
    printf("%d\n", res);
    return 0;
}

int get_line(char line[], int limit) {
    int i, c;
    for (i = 0; i < limit; i++) {
        c = getchar();
        if (c == EOF || c == '\n')
            break;
        line[i] = c;
    }
    line[i] = '\0';
    return i;
}

// returns a -> 1 to z -> 26
// returns A -> 27 to Z -> 52
int get_item_priority(char item) {
    if (item >= 'a' && item <= 'z')
        return item - 97 + 1; // ascii value of a = 97
    else if (item >= 'A' && item <= 'Z')
        return item - 65 + 27; // ascii value of A = 65
    return 0;
}

int get_common_item_priority(char line1[], char line2[], char line3[]) {
    int i, index, common_item_priority = 0;
    char c, occurance[52][3] = {'\0'};
    for (i = 0; i < strlen(line1); i++) {
        c = line1[i];
        index = get_item_priority(c) - 1;
        occurance[index][0] = 1;
    }
    for (i = 0; i < strlen(line2); i++) {
        c = line2[i];
        index = get_item_priority(c) - 1;
        occurance[index][1] = 1;
    }
    for (i = 0; i < strlen(line3); i++) {
        c = line3[i];
        index = get_item_priority(c) - 1;
        occurance[index][2] = 1;
    }
    for (i = 0; i < 52; i++) {
        if (occurance[i][0] == 1 && occurance[i][1] == 1 && occurance[i][2] == 1)
            common_item_priority = i + 1;
    }
    return common_item_priority;
}
