/*Write a program to "fold" long inputs lines into two or more shorter lines after the last non blank character
that occurs before the n-th column of input. Make sure your program does somethins intelligent with very long 
lines and if there are no blanks or tabs before the specified column*/

#include <stdio.h>
#define MAX_LENGTH 1000
#define BLANK_POS 5

void fold(char char_arr[], int limit, int blank_pos) {
    int i;
    int ch;
    int count;

    count = 0;
    
    for (i = 0; i < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; i++) {

        if (count == blank_pos && ch == ' ') {
            char_arr[i] = '\n';
            count = 0;
        } else if (count > blank_pos && ch == ' ') {
            char_arr[i] = '\n';
            count = 0;
        } else {
            char_arr[i] = ch;
            count++;
        }

    }

    if (ch == '\n') {
        char_arr[i++] = '\n';
    }

    char_arr[i] = '\0';
}

int main() {
    char char_arr[MAX_LENGTH] = {'\0'};

    fold(char_arr, MAX_LENGTH, BLANK_POS);
    printf("New Modified String is: \n%s\n", char_arr);
    
    return 0;
}