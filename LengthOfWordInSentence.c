#include <stdio.h>
#define IN 1
#define OUT 0

void main() {
    int ch;
    int state = OUT;
    int count = 0, schar = 0;
    
    while ((ch = getchar()) != EOF) {

        if (ch == ' ' || ch == '\t' || ch == '\n') {
            state = OUT;
            schar++;

            while (count > 0) {
                printf(" * ");
                count--;
            }

            printf("\n");

        } else if (state == OUT) {
            state = IN;
            count++;
            putchar(ch);
        } else {
            count++;
            putchar(ch);
        }

    }

}