#include <stdio.h>
#include <ctype.h>

#define BUF_LEN 100

int buff_arr[BUF_LEN] = {0};
int buf_top = -1;

int getchs() {
    return (buf_top > -1)? buff_arr[buf_top--] : getchar();
}

void ungetchs(int c) {

    if (buf_top >= BUF_LEN) {
        printf("Buffer full..\n");
    } else {
        buff_arr[++buf_top] = c;
    }

}

int getints(int *pn) {
    int sign, c;

    while (isspace(c = getchs())) {
        continue;
    }

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {

        if (buff_arr[buf_top + 1] != c) {
            ungetchs(c);
        }

        return 0;
    }

    sign = (c == '-')? -1 : 1;

    if (c == '+' || c == '-') {
        
        if (!isdigit(c = getchs())) {
            ungetchs(sign == -1? '-' : '+');
            ungetchs(c);

            return 0;
        }

    }

    for (*pn = 0; isdigit(c); c = getchs()) {
        *pn = 10 * *pn + (c - '0');
    }

    *pn *= sign;

    if (c != EOF) {
        ungetchs(c);
    }

    return c;
}

int main() {
    int val, arr[10];

    printf("Enter integers separated by spaces or newlines (Ctrl+D to end):\n");

    for (val = 0; val < 10 && getints(&arr[val]) != EOF; val++) {
        printf("Read number is: %d\n", arr[val]);
    }

    printf("The total integer read: %d\n", val);

    return 0;
}