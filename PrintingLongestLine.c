#include <stdio.h>
#include <limits.h>
#define MAX_LINES 1000

int getlines(char temp_c_arr[], int limit) {
    int count;
    int ch;

    for (count = 0; count < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; count++) {
        temp_c_arr[count] = ch;
    }

    if (ch == '\n') {
        temp_c_arr[count++] = '\n';
    }

    temp_c_arr[count] = '\0';

    return count;
}

void copy(char temp_c_arr[], char longest_c_arr[]) {
    int index;

    index = 0;

    while ((longest_c_arr[index] = temp_c_arr[index]) != 0) {
        index++;
    }

}

int main() {
    int len;
    int max;
    char temp_c_arr[MAX_LINES];
    char longest_c_arr[MAX_LINES];

    len = max = INT_MIN;

    while ((len = getlines(temp_c_arr, MAX_LINES)) > 0) {

        if (len > max) {
            max = len;
            copy(temp_c_arr, longest_c_arr);
        }

    }

    printf("%s", longest_c_arr);

    return 0;
}