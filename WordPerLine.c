#include <stdio.h>

void main() {
    int ch;

    while ((ch = getchar()) != EOF) {

        if (ch == '\n' || ch == '\t' || ch == ' ') {
            putchar('\n');
        } else {
            putchar(ch);
        }

    }

}