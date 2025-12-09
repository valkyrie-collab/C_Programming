#include <stdio.h>
#include <stdlib.h>
#include "cal.h"

int main() {
    int type;
    double temp;
    char s[MAX_LEN];

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
                    printf("Error in division\n");
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
                printf("Invalid input stoping program\n");
                return 0;
            }
        }

    }

    return 0;
}