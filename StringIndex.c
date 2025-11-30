/*Write a program to give the String index of the given String*/

#include <stdio.h>
#define MAX_LENGTH 1000

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

int strindex(char inp_str[], char srh_str[]) {
    int inp_index;
    int srh_index;
    int start_index;

    inp_index = srh_index = 0;
    start_index = -1;

    while (inp_str[inp_index] != '\0' && srh_str[srh_index] != '\0') {

        if (inp_str[inp_index] == srh_str[srh_index]) {

            if (srh_str[srh_index + 2] == '\0') {
                start_index = inp_index - srh_index;
                return start_index;
            }

            if (srh_index == 0 && inp_str[inp_index + 1] == srh_str[srh_index]) {
                inp_index++;
                continue;
            }

            srh_index++;

        } else {
            srh_index = 0;
        }

        inp_index++;
    }

    return start_index;
}

int main() {
    int len;
    int index;
    char inp_str[MAX_LENGTH];
    char srh_str[MAX_LENGTH];

    printf("Enter the String you want to search: ");
    getlines(srh_str, MAX_LENGTH);
    printf("\n");
    printf("Enter the other String line after line: ");

    while ((len = getlines(inp_str, MAX_LENGTH)) > 0) {
        index = strindex(inp_str, srh_str);
        printf("The index of the String %s in String %s is %d\n", srh_str, inp_str, index);
    }

    return 0;
}