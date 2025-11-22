/*Write a loop for this "for (int i = 0; i < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; i++)" without
using && or ||*/

#include <stdio.h>
#define MAX_LINES 1000

int  getlines(char char_arr[], int limit) {
    int i;
    char ch;

    i = 0;

    while (i < limit - 1) {

        if ((ch = getchar()) == EOF) {
            break;
        } else if (ch == '\n') {
            char_arr[i++] = '\n';
            break;
        } else {
            char_arr[i++] = ch;
        }

    }

    char_arr[i] = '\0';

    return i;
}

int main() {
    int len;
    char char_arr[MAX_LINES];

    len = getlines(char_arr, MAX_LINES);

    printf("The line is: %s\n", char_arr);
    printf("The value of Length: %d\n", len);

    return 0;
}