#include <stdio.h>
#define SIZE 1000

int getlines(char str[], int limit) {
    int i, c;
    
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        str[i] = c;
    }

    if (c == '\n') {
        str[i++] = c;
    }

    str[i] = '\0';

    return i;
}

void reverse_str(char str[], int len, int start) {

    if (start >= len) {
        return;
    }

    if (str[start] != str[len]) {
        str[start] = str[start] ^ str[len];
        str[len] = str[start] ^ str[len];
        str[start] = str[start] ^ str[len];
    }

    reverse_str(str, --len, ++start);
}

int main() {
    char str[SIZE];
    int len;

    len = getlines(str, SIZE);
    
    printf("The entered String is: %s", str);

    reverse_str(str, len - 2, 0);

    printf("The reverse is : %s", str);

    return 0;
}