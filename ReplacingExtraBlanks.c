#include <stdio.h>

void main() {
    int ch, n1 = 0;

    while ((ch = getchar()) != EOF) {

        if (ch == ' ' && n1 == 0) {
            n1 = 1;
            putchar(ch);
        } else if (ch != ' ') {
            n1 = 0;
            putchar(ch);
        }

    }

}

// OutPut
// This  Test    is valid    or   not
// This Test is valid or not