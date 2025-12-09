#include <stdio.h>
#include "cal.h"

double stack[MAX_STK_SIZE];
int top = -1;

void push(double val) {
    
    if (top > MAX_STK_SIZE) {
        printf("The stack is full\n");
    } else {
        stack[++top] = val;
    }

}

double pop() {

    if (top < 0) {
        printf("The stack is underflow\n");
        return 0.0;
    } else {
        return stack[top--];
    }

}