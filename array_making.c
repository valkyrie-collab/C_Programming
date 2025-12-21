#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

int get_array(int *p_pos, int limit) {
    int count, ch;

    for (count = 0; count < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; count++) {

        if (ch >= '0' && ch <= '9') {
            *p_pos++ = ch - '0';
        }

    }

    /*if (ch == '\n') {
        *p_pos++ = '\n';
        count++;
    }*/

    *p_pos = '\0';

    return count;
}

char *display_array(int arr[], int len) {
    int o_len = len;
    len = len * 3 + 4;
    char *show_arr = malloc(len), *ps = &show_arr[0];
    int i;

    *show_arr++ = '[';

    for (i = 0; i < o_len - 1; i++) {
        *show_arr++ = arr[i] + '0';
        *show_arr++ = ',';
        *show_arr++ = ' ';
    }

 
    *show_arr++ = arr[i] + '0';
    *show_arr++ = ']';
    *show_arr++ = '\n';
    *show_arr++ = '\0';

    return ps;

}

int main() {
    int len, arr[SIZE];
    char *result;

    len = get_array(arr, SIZE);
    result = display_array(arr, len);

    printf("The array is: %s", result);

    free(result);

    return 0;
}