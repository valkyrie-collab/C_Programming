/*Write a Program to reverse the string s. also reverse one at a time*/

#include <stdio.h>
#define MAX_LENGTH 1000

int getlines(char line_arr[], int limit) {
    int count;
    int ch;

    for (count = 0; count < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; count++) {
        line_arr[count] = ch;
    }

    if (ch == '\n') {
        line_arr[count++] = ch;
    }

    line_arr[count] = '\0';

    return count - 1;
}

void reverse(char line_arr[], int len) {
    int index;

    index = 0;

    while (index < len) {
        len--;
        int temp = line_arr[index];
        line_arr[index] = line_arr[len];
        line_arr[len] = temp;
        index++;
    }

}

int main() {
    int len;
    char line_arr[MAX_LENGTH];

    while ((len = getlines(line_arr, MAX_LENGTH)) > 0) {
        reverse(line_arr, len);
        printf("\nThe reverse String is: %s", line_arr);
    }

    return 0;
}