#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

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

int user_atoi(char *str_arr) {
    int sign, val;

    if ((*str_arr < '0' || *str_arr > '9') && *str_arr != '+' && *str_arr != '-') {
        return 0;
    }

    val = 0;
    sign = 1;
    
    if (*str_arr == '-') {
        sign = -1;
        str_arr++;
    } else if (*str_arr == '+') {
        str_arr++;
    }

    printf("value of str_arr %c\n", *str_arr);
    
    while (*str_arr != '\0') {
        printf("value of str_arr %c\n", *str_arr);
        
        if (*str_arr >= '0' && *str_arr <= '9') {
            val = val * 10 + (*str_arr - '0');
        } else {
            return sign * val;
        }

        *str_arr++;
    }

    return sign * val;
}
int main() {
    int len;
    char *str;
    str = malloc(SIZE);

    printf("Enter the String");
    len = get_lines(str, SIZE);
    printf("The String is: %s, and its size is: %d\n", str, len);

    printf("The Integer value is: %d\n", user_atoi(str));
    free(str);

    return 0;
}