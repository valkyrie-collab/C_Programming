/*Write a program to remove all comments from a C programme Don't Forget to handle quoted strings and Characters
constants properly. C coments do not nest*/

#include <stdio.h>
#define MAX_LENGTH 1000

int getlines(char char_arr[], int limit) {
    int count;
    int ch;

    for (count = 0; count < limit - 1 && (ch = getchar()) != EOF; count++) {
        char_arr[count] = ch;
    }

    char_arr[count] = '\0';

    return count;
}

void rem_comments(char char_arr[], char clean_arr[], int limit) {
    int index;
    int track_quot;
    int track_comments;

    index = track_quot = track_comments = 0;

    for (int i = 0; i < limit; i++) {
        
        if (char_arr[i] == '"' && track_quot == 0) {
            track_quot = 1;
        } else if (char_arr[i] == '"' && track_quot == 1) {
            track_quot = 0;
        }

        if (track_quot) {
            clean_arr[index++] = char_arr[i];
        } else {

            if (char_arr[i] == '/' && char_arr[i + 1] == '*' && track_comments == 0) {
                track_comments = 1;
            } else if (char_arr[i] == '*' && char_arr[i + 1] == '/' && track_comments == 1) {
                track_comments = 0;
                i++;
            } else if (!track_comments) {
                // printf("char value: %c value of i: %d\n", char_arr[i], i);
                clean_arr[index++] = char_arr[i];
            }

        }
    }

    clean_arr[index] = '\0';
}

int main() {
    int len;
    char char_arr[MAX_LENGTH];
    char clean_char_arr[MAX_LENGTH];

    len = getlines(char_arr, MAX_LENGTH);
    rem_comments(char_arr, clean_char_arr, len);

    printf("The main String: %s\n with size: %d\n", char_arr, len);
    printf("The clean String is: %s\n", clean_char_arr);

}