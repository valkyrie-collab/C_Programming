#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define TRUE 1
#define FALSE 0

void get_lines(char *p_str, int limit) {
    int count, ch;

    for (count = 0; count < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; count++) {
        *p_str++ = ch;
    }

    *p_str = '\0';
}

int usr_strindex(char *pn_main_str, char *pn_sub_str) {
    char *ini_pos, *sub_pos;

    while (TRUE) {
        ini_pos = pn_main_str++;
        sub_pos = pn_sub_str;

        if (*ini_pos == '\0') {
            break;
        }

        while (TRUE) {

            if (*sub_pos == '\0') {
                return TRUE;
            }

            if (*sub_pos != *ini_pos) {
                break;
            }         

            *ini_pos++;
            *sub_pos++;
        }

    }
    
    return FALSE;
}

int main() {
    char *str_one, *str_two;

    str_one = malloc(SIZE);
    str_two = malloc(SIZE);

    printf("Enter the main String: ");
    get_lines(str_one, SIZE);

    printf("Enter the sub String: ");
    get_lines(str_two, SIZE);

    if (usr_strindex(str_one, str_two)) {
        printf("The sub String is present in the main String\n");
    } else {
        printf("The sub String is not present in the main String\n");
    }

    return 0;
}