/*Write a program to print all input lines that ar longer than 80 characters*/

#include <stdio.h>
#define MAX_LENGTH 1000
#define FIXED_LENGTH 80

int getlines(char temp_c_arr[], int limit) {
    int count;
    int ch;

    for (count = 0; count < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; count++) {
        temp_c_arr[count] = ch;
    }

    if (ch == '\n') {
        temp_c_arr[count++] = ch;
    }

    temp_c_arr[count] = '\0';

    return count;

}

void copy(char from_arr[], char to_arr[]) {
    int index;

    index = 0;
    
    while ((to_arr[index] = from_arr[index]) != '\0') {
        from_arr[index] = '\0';
        index++;
    }

}

int main() {
    int len;
    int max;
    char temp_c_arr[MAX_LENGTH];
    char longest_c_arr[MAX_LENGTH];
    char long_c_arr[MAX_LENGTH];

    len = max = 0;

    while ((len = getlines(temp_c_arr, MAX_LENGTH)) > 0) {

        if (len > max) {
            max = len;
            copy(temp_c_arr, longest_c_arr);

            if (len >= FIXED_LENGTH) {
                printf("\nThe Sentence is greater than 80 Characters: %s\n", longest_c_arr);
            }

        } else if (len >= FIXED_LENGTH) {
            copy(temp_c_arr, long_c_arr);
            printf("\nThe Sentence is greater than 80 Characters: %s\n", long_c_arr);
        }

    }

    printf("\nThis is largest sentence in the whole input: %s\n", longest_c_arr);
    
    return 0;
}