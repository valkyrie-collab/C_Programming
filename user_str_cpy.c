#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define SIZE 1000

int get_lines(char *ps, int limit) {
    int count, ch;

    for (count = 0; count < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; count) {
        *ps++ = ch;
    }

    if (ch == '\n') {
        *ps++ = ch;
        count++;
    }

    *ps++ = '\0';

    return count;
}

void str_cpy(char *ps, char *pt, int len) {
    
    while (--len > -1) {
        *ps++ = *pt++;
    }

    *ps = '\0';
}

char *dis_arr(char *arr) {
    char *show_arr, *ini_pos; 

    show_arr = malloc(SIZE);
    ini_pos = show_arr;
    *show_arr++ = '[';

    while (*arr != '\0') {

        if (*arr == '\n') {
            arr++;
            continue;
        }
        
        *show_arr++ = *arr++;
 
        if (*arr != '\n' && *arr != '\0') {
            *show_arr++ = ',';
            *show_arr++ = ' ';
        }
    }

    *show_arr++ = ']';
    *show_arr++ = '\n';
    *show_arr = '\0';

    return ini_pos;

}

int main() {
    int len, range;
    char ini_arr[SIZE], cpy_arr[SIZE], *arr_form;

    printf("Enter the elements of the array: ");
    len = get_lines(ini_arr, SIZE);

    printf("Enter the size of the range of the copy: ");
    scanf("%d", &range);

    str_cpy(cpy_arr, ini_arr, range);

    arr_form = dis_arr(ini_arr);
    printf("The main array is: %s", arr_form);
    free(arr_form);

    arr_form = dis_arr(cpy_arr);
    printf("The copy array is: %s", arr_form);
    free(arr_form);

    return 0;
}