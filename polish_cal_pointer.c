#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 1000
#define NUM 1

int buff_arr[10];
int buff_top = -1;
double stack[SIZE];
int top = -1;

void push(int c) {

    if (top >= SIZE) {
        printf("The Stack is full..\n");
    } else {
        stack[++top] = c;
    }

}

double pop() {

    if (top <= -1) {
        return 0;
    } else {
        return stack[top--];
    }

}

int getch() {
    return buff_top > -1? buff_arr[buff_top--] : getchar();
}

void setch(int c) {

    if (buff_top >= 10) {
        printf("The buffer is full..\n");
    } else {
        buff_arr[++buff_top] = c;
    }

}

int getop(char *s) {
    int c;
    
    while ((*s = c = getch()) == ' ' || c == '\t') {continue;}
    
    if (!isdigit(c) && c != '.') {
        return c;
    }
    
    if (isdigit(c)) {

        while (isdigit(c = getch())) {
            *(++s) = c;
        }
        
        *(++s) = c;
    }
    
    if (c == '.') {

        while (isdigit(c = getch())) {
            *(++s) = c;
        }

    }

    *(++s) = '\0';

    if (c != EOF) {
        setch(c);
    }
    
    return NUM;
}


int main() {
    char *s;
    int val, op;

    s = malloc(SIZE);
    
    while ((val = getop(s)) != EOF) {

        switch (val) {
            case NUM: {
                push(atof(s));
                break;
            }
            case '+': {
                push(pop() + pop());
                break;
            }
            case '-': {
                op = pop();
                push(pop() - op);
                break;
            }
            case '/': {
                op = pop();

                if (op == 0) {
                    free(s);
                    return 0;
                } else {
                    push(pop() / op);
                }

                break;
            }
            case '*': {
                push(pop() * pop());
                break;
            }
            case '\n': {
                printf("\t%.8g\n", pop());
                break;
            }
            default: {
                printf("Unknown Input...\n");
                free(s);
                return 0;
            }
        }

    }

    free(s);
    return 0;
}