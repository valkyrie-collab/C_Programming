#include <stdio.h>
#include "gfloat.h"

int buff_arr[BUFF_SIZE] = {0};
int buff_top = -1;

int getchs() {
    return (buff_top > -1)? buff_arr[buff_top--] : getchar();
}


void ungetchs(int c) {

    if (buff_top >= BUFF_SIZE) {
        printf("The buff size is full\n");
    } else {
        buff_arr[++buff_top] = c;
    }

}

int check_buffer(int c) {
    return (buff_arr[buff_top + 1] != c)? 1 : 0;
}