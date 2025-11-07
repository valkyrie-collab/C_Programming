#include <stdio.h>

void main() {
    int nDigit[10];
    int ch; 
    int nWhite = 0, nOther = 0;

    for (int i = 0; i < 10; i++) {nDigit[i] = 0;}

    while ((ch = getchar()) != EOF) {

        if (ch >= '0' && ch <= '9') {
            ++nDigit[ch - '0'];
        } else if (ch == ' ') {
            ++nWhite;
        } else {
            ++nOther;
        }

    }

    printf("Digits Count: ");

    for (int i = 0; i < 10; i++) {
        printf(" %d", nDigit[i]);
    }

    if (nWhite > 0) {printf("\nWhiteSpace Count: %d", nWhite);}

    if (nOther > 0) {printf("\nOther Symbol Count: %d\n", nOther);}

}