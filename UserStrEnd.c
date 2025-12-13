/*Checking if the substring is present at the end or not*/

#include <stdio.h>
#define SIZE 1000

int getlines(char *p_arr, int limit) {
    int count, c;

    for (count = 0; count < limit - 1 && (c = getchar()) != EOF && c != '\n'; count++) {
        *p_arr++ = c;
    }

    if (c == '\n') {
        *p_arr++ = '\n';
        count++;
    }

    *p_arr = '\0';

    return count;
}

int check_str_end(char *p_main_arr, char *p_sub_arr) {

    while (*p_main_arr++ == *p_sub_arr++) {

        if (*p_main_arr == '\0' || *p_sub_arr == '\0') {
            return 1;
        }

    }

    return 0;
}

int main() {
    int len_one, len_two, result;
    char arr_one[SIZE], arr_two[SIZE];

    len_one = getlines(arr_one, SIZE);
    len_two = getlines(arr_two, SIZE);

    printf("The main Array is: %s and its size %d\n", arr_one, len_one);
    printf("The sub Array is: %s its size is %d\n", arr_two, len_two);

    if (len_two > len_one) {
        printf("The main array cannot be smaller than sub array..\n");
        return 0;
    }

    result = check_str_end(&arr_one[len_one - len_two], arr_two);

    printf("The String is has %d\n", result);
    
    return 0;
}