#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int get_lines(char *p_arr, int limit) {
    int count, ch;
    
    for (count = 0; count < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; count++) {
        *p_arr++ = ch;
    }

    if (ch == '\n') {
        *p_arr++ = ch;
        count++;
    }

    *p_arr = '\0';

    return count;
}

char *dis_arr(char *arr) {
    char *str_arr, *ini_pos;
    int count;

    ini_pos = str_arr = malloc(SIZE);
    *str_arr++ = '[';
    count = 1;
    
    while (*arr != '\0' && count < SIZE - 2) { 
        *str_arr++ = *arr++;

        if (*arr == '\n') {
            arr++;
            count--;
        } else {
            *str_arr++ = ',';
            *str_arr++ = ' ';
            count += 2;
        }

        count++;
    }

    *str_arr++ = ']';
    *str_arr = '\0';

    return ini_pos;
}

int exist_str(char *ps, char *pt) {

    while (*ps != '\0' && *ps != '\n') {

        if (*ps++ != *pt++) {
            return 0;
        }

    }

    return 1;
}

int main() {
    int len_one, len_two;
    char arr_main[SIZE], arr_sub[SIZE], *main_result, *sub_result;

    printf("Enter the main array: ");
    len_one = get_lines(arr_main, SIZE);
    main_result = dis_arr(arr_main);
    printf("The main array is: %s\n", main_result); 

    printf("Enter the sub array: ");
    len_two = get_lines(arr_sub, SIZE);
    sub_result = dis_arr(arr_sub);
    printf("The sub array is: %s\n", sub_result);
    
    if (len_one > len_two && exist_str(arr_sub, &arr_main[len_one - len_two])) {
        printf("The Given arr %s is present in the main arr %s\n", sub_result, main_result);
    } else {
        printf("The Given arr %s is not present in the main arr %s\n", sub_result, main_result);
    }

    free(sub_result);
    free(main_result);

    return 0;
}