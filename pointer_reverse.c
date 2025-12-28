#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

void get_lines(char *str_arr, int limit) {
    int ch;

    while (limit > 0 && (ch = getchar()) != EOF && ch != '\n') {
        *str_arr++ = ch;
        limit--;
    }

    *str_arr = '\0';
}

char *reverse_str(char *str_arr) {
    int size;
    char *ini_pos, *rev_str;

    size = 0;

    while (*str_arr != '\0') {
        str_arr++;
        size++;
    }

    ini_pos = rev_str = malloc(size);

    while (--size > -1) {
        *rev_str++ = *(--str_arr);
    }

    *rev_str = '\0';

    return ini_pos;
}

int main() {
    char *str_arr, *rev_str;

    str_arr = malloc(SIZE);

    printf("Enter the String: ");
    get_lines(str_arr, SIZE); 

    rev_str = reverse_str(str_arr);
    printf("The Reverse String: %s\n", rev_str);
    free(str_arr);
    free(rev_str);

    return 0;
}