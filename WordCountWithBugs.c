#include <stdio.h>
#define IN 1
#define OUT 0

void main() {
    int ch;
    int state = OUT;
    int newline = 0, word = 0, character = 0, bugs = 0;

    while ((ch = getchar()) != EOF) {
        ++character;

        if (ch == '\n') {
            ++newline;
        }

        if (ch == ' ' || ch == '\n' || ch == '\t') {

            if (state == OUT) {
                ++bugs;
            }

            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++word;
        }

    }

    printf("NewLines: %d\nWords: %d\nCharacters: %d\nBugs: %d\n", newline, word, character, bugs);

}