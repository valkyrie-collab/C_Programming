#include <stdio.h>

void main() {
    int ch;

    while ((ch = getchar()) != EOF) {

        if (ch == '\t') {
            printf("\\t");
        } else if (ch == '\b') {
            printf("\\b --replaced");
        } else {
            printf("%c", ch);
        }

    }

}