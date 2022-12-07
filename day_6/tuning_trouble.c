// problem: https://adventofcode.com/2022/day/6

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define SEQ_LIMIT 14

size_t remove_first_n_elements(char *str, int n);
int index_of(char *str, char c);

/* loop:
 *   save characters into array till repition conflict occurs
 *   in case of repition conflict:
 *      remove first n characters upto the first occurance
 *      of the repeating character including the repeating
 *      character
 *      append new characters to the array normally as you would
 *   exit loop when you populate the array
 * count the total iterations in loop and return it
 * */

int main() {
    int i, n = 0, pos;
    char c, characters[SEQ_LIMIT] = {'\0'};
    for (i = 0; (c = getchar()) != EOF; i++) {
        if (n == SEQ_LIMIT)
            break;
        if ((pos = index_of(characters, c)) != -1) {
            n = remove_first_n_elements(characters, pos + 1);
            characters[n] = c;
            n++;
        } else {
            characters[n] = c;
            n++;
        }
    }
    printf("%d\n", i);
    return 0;
}

// returns index of first instance of the character in the string
// returns -1 if not found
int index_of(char *str, char c) {
    for (int i = 0; i < strlen(str); i++)
        if (c == str[i])
            return i;
    return -1;
}

// removes first n elements of a string and returns length
size_t remove_first_n_elements(char *str, int n) {
    size_t i, len = strlen(str);
    assert(len >= n);
    for (i = 0; i < len - n; i++)
        str[i] = str[n + i];
    for (i = len - n; i < len; i++)
        str[i] = '\0';
    return len - n;
}
