#include <stdio.h>
#define SIZE 1000 

int getlines(char *p_arr, int limit) {
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

char *str_cat(char *ps, char *pt) {
    char *count;

    count = ps;

    while (*ps++ != '\0') {
        continue;
    }

    ps -= 2;

    while ((*ps++ = *pt++) != '\0') {
        continue;
    }

    return count;
}

int main() {
    int len_one, len_two; 
    char *result;
    char arr_one[SIZE], arr_two[SIZE];
    
    len_one = getlines(arr_one, SIZE);
    len_two = getlines(arr_two, SIZE);
    
    printf("The First array is %s and the size is %d\n", arr_one, len_one);
    printf("The Second array is %s and the size is %d\n", arr_two, len_two);

    result = str_cat(arr_one, arr_two);
    printf("After the combining the both array we get %s\n", result);

    return 0;
}