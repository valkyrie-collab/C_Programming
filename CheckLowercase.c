#include <stdio.h>
#include <ctype.h>

int main() {
    int c;

    c = 's';

    if (islower(c)) {
        printf("It is lower");
    } else {
        printf("it isnot lower:");
    }

    return 0;
}