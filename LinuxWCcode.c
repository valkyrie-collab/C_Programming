#include <stdio.h>
#define IN 1
#define OUT 0

void main() {
    int state = OUT;
    int newline = 0, word = 0, character = 0, ch;

    while ((ch = getchar()) != EOF) {
        ++character;

        if (ch == '\n') {
            ++newline;
        }

        if (ch == ' ' || ch == '\n' || ch == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++word;
        }

    }

    printf("%d, %d, %d \n", newline, character, word);

}