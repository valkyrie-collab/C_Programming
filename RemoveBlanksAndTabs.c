/*write a program to remove trailing blanks and tabs from each line of input and to delete entirely blank lines*/

#include <stdio.h>
#define MAX_LENGTH 1000

int count(char temp_c_arr[], int limit) {
    int index;
    int ch;

    index = 0;

    while ((ch = getchar()) != EOF && ch != '\n' && index < limit - 1) {
        temp_c_arr[index++] = ch;
    }

    temp_c_arr[index] = '\0';
    printf("\n|%s|\n", temp_c_arr);

    return index;
}

void clean(char temp_c_arr[], int max_index) {
    int temp;

    while (max_index > 0) {
        temp = temp_c_arr[--max_index];
        
        if (temp == '\t' || temp == ' ') {
            temp_c_arr[max_index] = '\0';
        } else {
            temp_c_arr[++max_index] = '\n';
            temp_c_arr[++max_index] = '\0';
            break;
        }

    }

}

int main() {
    int len;
    char temp_c_arr[MAX_LENGTH];

    while ((len = count(temp_c_arr, MAX_LENGTH)) > 0) {
        clean(temp_c_arr, len);
        printf("\nThe Refreshed Sentence: |%s|\n", temp_c_arr);
    }

    return 0;
}