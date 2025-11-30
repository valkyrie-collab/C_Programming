#include <stdio.h>
#define MAX_LENGTH 1000

int getlines(char char_arr[], int limit) {
    int count;
    char ch;

    for (count = 0; count < limit -1 && (ch = getchar()) != EOF && ch != '\n'; count++) {
        char_arr[count] = ch;
    }

    if (ch == '\n') {
        char_arr[count++] = '\n';
    }

    char_arr[count] = '\0';

    return count;
}

int strrindex(char input_string[], char search_string[]) {
    int input_index, search_index, start_index;

    input_index = search_index = 0;
    start_index = -1;

    while (input_string[input_index] != '\0') {

        if (input_string[input_index] == search_string[search_index]) {

            if (search_string[search_index + 2] == '\0') {
                start_index = input_index - search_index;
            }

            if (search_index == 0 && input_string[input_index + 1] == search_string[search_index]) {
                input_index++;
                continue;
            }

            search_index++;

        } else {
            search_index = 0;
        }

        input_index++;
    }

    return start_index;
}

int main() {
    int value;
    char input_string[MAX_LENGTH];
    char search_string[MAX_LENGTH];

    printf("Enter the Search String: ");
    getlines(search_string, MAX_LENGTH);
    
    while ((getlines(input_string, MAX_LENGTH)) > 0) {
        value = strrindex(input_string, search_string);
        printf("The Index of the Input String: %d\nThe Input String is: %sThe Search String is: %s", value, input_string, search_string);
    }

    return 0;
}