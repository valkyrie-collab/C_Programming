#include <stdio.h>
#include "cal.h"

char buffer_arr[MAX_STK_SIZE];
int buf_top = -1;

int getlines() {
    return (buffer_arr[buf_top] > 0)? buffer_arr[buf_top--] : getchar();
}

void ungetchar(char c) {
    
    if (buf_top > MAX_STK_SIZE) {
        printf("Buffer is full\n");
    } else {
        buffer_arr[++buf_top] = c;
    }

}
