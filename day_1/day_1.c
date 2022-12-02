// problem: https://adventofcode.com/2022/day/1

#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10
#define ELVES 300

int get_line(char line[], int limit);
long get_max(long list[], int length);
void reset_list(long list[], int length);
void sort_list(long list[], int length);
int nsum(long list[], int n);

int main() {
    int length, i = 0;
    long calories, total_calories[ELVES];
    char line[LIMIT];
    reset_list(total_calories, ELVES);
    while ((length = get_line(line, LIMIT)) > 0) {
        if (length == 1) {
            i++;
            continue;
        }
        calories = atoi(line);
        total_calories[i] += calories;
    }
    sort_list(total_calories, i);
    // get sum of top 3 elves' calories
    long result = nsum(total_calories, 3);
    printf("%ld\n", result);
    return 0;
}

int nsum(long list[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += list[i];
    }
    return sum;
}

void sort_list(long list[], int length) {
    int temp;
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (list[i] < list[j]) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

void reset_list(long list[], int length) {
    for (int i = 0; i < length; i++) {
        list[i] = 0;
    }
}

long get_max(long list[], int length) {
    long max = list[0];
    for (int i = 1; i < length; i++) {
        if (max < list[i])
            max = list[i];
    }
    return max;
}

int get_line(char line[], int limit) {
    int i, c;
    for (i = 0; i < limit - 1; i++) {
        c = getchar();
        if (c == EOF) {
            break;
        }
        line[i] = c;
        if (c == '\n') {
            i++;
            break;
        }
    }
    line[i] = '\0';
    return i;
}
