//Check the longest line with the newline *Need to try again using my perspective

#include <stdio.h>
#define MAXLINE 1000

int getlines(char c_arr[], int limit) {
    int c;
    int i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        c_arr[i] = c;
    }

    if (c == '\n') {
        c_arr[i] = c;
        i++;
    }

    c_arr[i] = '\0'; // it is the null value;

    return i;

}

void copy(char c_to[], char c_from[]) {
    int i;
    i = 0;

    while((c_to[i] = c_from[i]) != '\0') {
        i++;
    }

}

int main() {

    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;

    while ((len = getlines(line, MAXLINE)) > 0) {
        
        if (len > max) {
            max = len;
            copy(longest, line);
        }

    }

    if (max > 0) {
        printf("%s", longest);
    }

    return 0;
}