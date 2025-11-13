/*Write a program detab to replace tabs in the input with proper number of blanks to space to the next tab stop.
Assume a fixed set of tabs stops say every n columns. Should n be a variable or a symbolic parameter?*/

#include <stdio.h>
#define MAX_LENGTH 1000

int remove_tabs(char char_arr[], int count) {
    int i;
    int times;
    int tab_size;
    int remain_size;

    times = count / 4;
    // printf("Count: %d\n", times);
    tab_size = 4;

    while (times > 0) {
        tab_size = tab_size + 4;
        times--;
    }

    remain_size = tab_size - count;
    // printf("Remaining Size: %d\n", remain_size);

    for (i = count; i < count + remain_size; i++) {
        char_arr[i] = '_';
    }

    // char_arr[i + 1] = '\0';
    // printf("value of i: %d\n", i);
    // printf("The value of char_arr: %s\n", char_arr);

    return i;
}

int getlines(char char_arr[], int limit) {
    int ch;
    int count;
    int got_tab;
    int temp_count;

    got_tab = 0;

    for (count = 0; count < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; count++) {

        if (ch == '\t') {
            got_tab = 1;
            // printf("value of count: %d\n", count);
            temp_count = remove_tabs(char_arr, count);
            // printf("value of temp count: %d\n", temp_count);
        }

        if (got_tab && ch != '\t') {
            char_arr[temp_count++] = ch;
        } else if (ch != '\t') {
            char_arr[count] = ch;
        }

    }

    count = got_tab? temp_count : count;

    if (ch == '\n') {
        char_arr[count++] = ch;
    }

    char_arr[count] = '\0';

    return count;
}

int main() {
    int len;
    char char_arr[MAX_LENGTH] = {'\0'};

    while ((len = getlines(char_arr, MAX_LENGTH)) > 0) {
        printf("\n%s\n", char_arr);

        for (int i = 0; i < MAX_LENGTH; i++) {
            char_arr[i] = '\0';
        }

    }

    return 0;
}
