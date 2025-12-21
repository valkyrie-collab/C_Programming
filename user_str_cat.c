#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

int get_lines(char *arr, int limit) {
    int count, ch; 

    for (count = 0; count < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; count++) {
        *arr++ = ch;
    }

    if (ch == '\n') {
        *arr++ = ch;
        count++;
    }

    *arr = '\0';

    return count;
}

char *dis_arr(char *arr) {
    char *dis_arr, *ini_pos;
    int count;

    ini_pos = dis_arr = malloc(SIZE);
    *dis_arr++ = '[';
    count = 1;

    while (*arr != '\0' && count < SIZE - 2) {
        *dis_arr++ = *arr++;

        if (*arr == '\n') {
            arr++;
            count--;
        } else {
            *dis_arr++ = ',';
            *dis_arr++ = ' ';
            count += 2;
        }

        count++;
    }

    *dis_arr++ = ']';
    *dis_arr = '\0';

    return ini_pos;
}

char *str_cat(char *arr_one, char *arr_two) {
    char *join_arr, *ini_pos;

    ini_pos = join_arr = malloc(SIZE);

    while (*arr_one != '\0' && *arr_one != '\n') {
        *join_arr++ = *arr_one++;
    }

    while (*arr_two != '\0' && *arr_two != '\n') {
        *join_arr++ = *arr_two++;
    }

    *join_arr++ = '\n';
    *join_arr = '\0';

    return ini_pos;
}

int main() {
    int len_one, len_two;
    char arr_one[SIZE], arr_two[SIZE], *p_arr;

    printf("Enter the value of array one: ");
    len_one = get_lines(arr_one, SIZE);
    p_arr = dis_arr(arr_one);
    printf("The Array one is: %s\n", p_arr);
    free(p_arr);

    printf("Enter the value of the array two: ");
    len_two = get_lines(arr_two, SIZE);
    p_arr = dis_arr(arr_two);
    printf("The Array two is: %s\n", p_arr);
    free(p_arr);

    p_arr = dis_arr(str_cat(arr_one, arr_two));
    printf("After the concat the both array is: %s\n", p_arr);
    free(p_arr);

    return 0;
}