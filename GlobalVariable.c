#include <stdio.h>
#define MAX_LENGTH 1000

int max;
int limit = MAX_LENGTH;
char temp_c_arr[MAX_LENGTH];
char longest_c_arr[MAX_LENGTH];

int getlines() {
    extern char temp_c_arr[];
    int count;
    int ch;

    for (count = 0; count < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; count++) {
        temp_c_arr[count] = ch;
    }

    if (ch == '\n') {
        temp_c_arr[count++] = ch;
    }

    temp_c_arr[count] = '\0';

    return count;
}

void copy() {
    int index;
    extern char temp_c_arr[];
    extern char longest_c_arr[];
    index = 0;

    while ((longest_c_arr[index] = temp_c_arr[index]) != '\0') {
        index++;
    }
    
}

int main() {
    int len;

    len = max = 0;

    while ((len = getlines()) > 0) {

        if (len > max) {
            max = len;
            copy();
        }

    }

    printf("\nThe longest String is: %s\n", longest_c_arr);

    return 0;
}