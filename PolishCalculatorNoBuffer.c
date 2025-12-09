#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_STACK 50
#define NUMBER '0'

int top = -1;
double stack[MAX_STACK];

void push(double val) {

    if (top < MAX_STACK) {
        stack[++top] = val;
    } else {
        printf("Stack overflow\n");
    }

}

double pop() {

    if (top > -1) {
        return stack[top--];
    } else {
        printf("stack underflow\n");
    }

}

int getlines() {
    return getchar();
}

int gettop(char s[]) {
    int i, c;
    
    while ((s[0] = c = getlines()) == ' ' || c == '\t') {
        continue;
    }

    s[1] = '\0';
    i = 0;

    if (!isdigit(c) && c != '.') {
        return c;
    }

    if (isdigit(c)) {

        while (isdigit(s[++i] = c = getchar())) {
            continue;
        }

        s[i] = '\0';

        if (!isdigit(c) && c != '.' && c != ' ' && c != '\t') {
            push(atof(s));
            return c;
        }

    }

    if (c == '.') {

        while (isdigit(s[++i] = c = getchar())) {
            continue;
        }

        s[i] = '\0';

        if (!isdigit(c) && c != '.' && c != ' ' && c != '\t') {
            push(atof(s));
            return c;
        }

    }

    return NUMBER;
}

int main() {
    int type;
    double temp;
    char s[MAX_LENGTH];

    while ((type = gettop(s)) != EOF) {

        switch(type) {
            case NUMBER: {
                push(atof(s));
                break;
            }
            case '+': {
                push(pop() + pop());
                break;
            }
            case '*': {
                push(pop() * pop()); 
                break;
            }
            case '-': {
                temp = pop();
                push(pop() - temp);
                break;
            }
            case '/': {
                temp = pop();

                if (temp == 0) {
                    printf("Error in division");
                } else {
                    push(pop() / temp);
                }

                break;
            }
            case '\n': {
                printf("\t%0.8g\n", pop());
                break;
            }
            default: {
                printf("Unknow input");
                break;
            }
        }

    }

    return 0;
}