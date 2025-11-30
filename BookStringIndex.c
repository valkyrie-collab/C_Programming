/*Write a program to give the String index of the given String*/

#include <stdio.h>
#define MAX_LENGTH 1000

char pattern[] = "ould";

int getlines(char char_arr[], int limit) {
    int count;
    char ch;

    for (count = 0; count < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; count++) {
        char_arr[count] = ch;
    }

    if (ch == '\n') {
        char_arr[count++] = '\n';
    }

    char_arr[count] = '\0';

    return count;
}

int strindex(char input_string[], char search_string[]) {
    int i, j, k;

    for (i = 0; input_string[i] != '\0'; i++) {

        /*Checks the character inside the loop for each value of i*/
        for (j = i, k = 0; search_string[k] != '\0' && input_string[j] == search_string[k]; j++, k++) 
        ;
    
        if (k > 0 && search_string[k] == '\0') {
            return i;
        }

    }

    return -1;
}

int main() {
    int len, found;
    char input_string[MAX_LENGTH];
    extern char pattern[];

    found = 0;

    while ((len = getlines(input_string, MAX_LENGTH)) > 0) {

        if (strindex(input_string, pattern) >= 0) {
            printf("%s", input_string);
            found++;
        }

    }

    printf("value found: %d\n", found);

    return 0;
}