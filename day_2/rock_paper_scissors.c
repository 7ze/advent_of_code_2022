// problem: https://adventofcode.com/2022/day/2

#include <stdio.h>
#include <stdlib.h>

#define ROUNDS 2500
#define LINE_LIMIT 5

#define WIN 6
#define DRAW 3
#define LOSS 0

int score(int b);
int total_score(int scoreboard[], int rounds);
int get_line(char line[], int limit);
int get_value(char x);
int get_shape(int a, char result);
int win, loss, draw;

int main() {
    char line[LINE_LIMIT];
    int scoreboard[ROUNDS], turns, i = 0, a, b, result, final_score;
    while ((turns = get_line(line, LINE_LIMIT)) > 0) {
        if (turns != 2) {
            printf("Error: Invalid entry.\n");
            return 1;
        }
        a = get_value(line[0]);
        result = line[1];
        b = get_shape(a, result);
        if (a == 0 || b == 0) {
            printf("Error: Invalid entry.\n");
            return 1;
        }
        scoreboard[i] = score(b);
        i++;
    }
    final_score = total_score(scoreboard, i);
    printf("%d\n", final_score);
    return 0;
}

int score(int b) { return WIN * win + DRAW * draw + LOSS * loss + b; }

int total_score(int scoreboard[], int rounds) {
    int sum = 0;
    for (int i = 0; i < rounds; i++) {
        sum += scoreboard[i];
    }
    return sum;
}

int get_line(char line[], int limit) {
    int c, i = 0;
    while ((c = getchar())) {
        if (c == EOF || c == '\n')
            break;
        if (c != ' ') {
            line[i] = c;
            i++;
        }
    }
    return i;
}

int get_value(char x) {
    switch (x) {
        case 'A':
            return 1;
        case 'B':
            return 2;
        case 'C':
            return 3;
        default:
            return 0;
    }
}

int get_shape(int a, char result) {
    switch (result) {
        case 'X':
            loss = 1;
            draw = 0;
            win = 0;
            return a == 1 ? 3 : a - 1;
        case 'Y':
            draw = 1;
            win = 0;
            loss = 0;
            return a;
        case 'Z':
            win = 1;
            loss = 0;
            draw = 0;
            return a == 3 ? 1 : a + 1;
        default:
            return 0;
    }
}
