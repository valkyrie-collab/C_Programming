#include <stdio.h>
#define MAX_CHAR 10

int getlines(char temp_c_arr[], int limit) {
    int len;
    int ch;
    int count;

    count = 0;

    for (len = 0; (ch = getchar()) != EOF && ch != '\n'; len++) {

        if (len < limit - 2) {
            temp_c_arr[count++] = ch;
        }

    }

    if (ch == '\n') {
        temp_c_arr[count++] = ch;
    }

    temp_c_arr[count] = '\0';

    return len;

}

void copy(char temp_c_arr[], char longest_c_arr[]) {
    int index;

    index = 0;

    while ((longest_c_arr[index] = temp_c_arr[index]) != '\0') {
        index++;
    }

}

int main() {
    int len;
    int max;
    char tem_c_arr[MAX_CHAR];
    char longest_c_arr[MAX_CHAR];

    len = max = 0;

    while ((len = getlines(tem_c_arr, MAX_CHAR)) > 0) {

        if (len > max) {
            max = len;
            copy(tem_c_arr, longest_c_arr);
        }

    }

    printf("\nThe max size is %2d\n", max);
    printf("The String is \"%s\"\n", longest_c_arr);

    return 0;
}