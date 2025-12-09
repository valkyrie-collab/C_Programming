#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define MATH '1'
#define BUFFSIZE 100
#define MAXVAL 100
#define VARIABLE '2'

int sp = 0;
double val[MAXVAL];
int bufp = 0;
int buf[BUFFSIZE];
int push_one_char = -1;

int getch() {

    /*if (push_one_char == -1) {
        return getchar();
    } else {
        int temp;
        temp = push_one_char;
        push_one_char = -1;

        return temp;
    }*/
    
    return (bufp > 0)? buf[--bufp] : getchar();
}

void ungetch(int c) {
    
    if (bufp >= BUFFSIZE) {
        // printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
        // printf("6. buf[%d] %c and c %d\n", bufp - 1, buf[bufp - 1], c);
    }

    // push_one_char = c;

}

int gettop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        continue;
    }
    //printf("1.The value of s[0]: %c and c: %d\n", s[0], c);

    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-' && !(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z')) {
        // printf("1.1 The value of c: %d\n", c);
        return c;
    }
    
    i = 0;

    if (isupper(c)) {
        return VARIABLE;
    }

    if (islower(c)) {
        while (islower(s[++i] = c = getch())) {
            continue;
        }

        s[i] = '\0';

        if (c != EOF) {
            ungetch(c);
        }

        return MATH;

    }

    if (c == '-') {

        if (isdigit(c = getch())) {
            s[++i] = c;
        } else {

            if (c != EOF) {
                ungetch(c);
            }

            return '-';
        }

    }

    if (isdigit(c)) {
        
        while (isdigit(s[++i] = c = getch())){
            continue;
        }

        // printf("2.The value of s[%d] %c and c %d is: \n", i, s[i], c);
    }

    if (c == '.') {

        while (isdigit(s[++i] = c = getch())){
            continue;
        }

        // printf("3.The value of s[%d] %c and c %d is: \n", i, s[i], c);
    }

    s[i] = '\0';

    if (c != EOF) {
        // printf("4. The value of c is %d\n", c);
        ungetch(c);
    }

    // printf("5. The value of number: %c\n", NUMBER);

    return NUMBER;
}

void push(double f) {
    
    if (sp < MAXVAL) {
        val[sp++] = f;
        // printf("7. The value of val[%d] is %f and f is %f\n", sp - 1, val[sp - 1], f);
    } else {
        // printf("error: stack full, cant push %g\n", f);
    }

}

double pop () {

    if (sp > 0) {
        // printf("8.The value of sp: %d", sp - 1);
        return val[--sp];
    } else {
        // printf("error: stack empty\n");
        return 0.0;
    }

}

void ungets(char s[]) {

    for (int i = strlen(s) - 1; i > -1; i++) {
        ungetch(s[i]);
    }

}

int main() {
    int type;
    double top;
    double op2;
    char s[MAXOP];
    char var;
    double var_arr[26] = {-1};

    while ((type = gettop(s)) != EOF) {

        switch (type) {
            case NUMBER: {
                // printf("9. push for NUMBER\n");
                push(atof(s));
                break;
            }
            case MATH: {

                if (strcmp(s, "sin") == 0) {
                    push(sin(pop()));
                } else if (strcmp(s, "cos") == 0) {
                    push(cos(pop()));
                } else if (strcmp(s, "exp") == 0) {
                    push(exp(pop()));
                } else if (strcmp(s, "pow") == 0) {
                    op2 = pop();
                    push(pow(pop(), op2));
                } else {
                    printf("Error not a proper mathfunction\n");
                }

                break;
            }
            case VARIABLE: {
                var = s[0];
                push(var_arr[var - 'A']);
                break;
            }
            case '=': {
                op2 = pop();
                var_arr[var - 'A'] = pop();

                break;
            }
            case '+': {
                // printf("10. push form +\n");
                push(pop() + pop());
                break;
            }
            case '*': {
                // printf("11. push form *\n");
                push(pop() * pop());
                break;
            }
            case '-': {
                // printf("12. push form *\n");
                op2 = pop();
                push(pop() - op2);
                break;
            }
            case '/': {
                op2 = pop();
                
                if (op2 != 0.0) {
                    // printf("13. push form /\n");
                    push(pop() / op2);
                } else {
                    printf("error: zero divisor\n");
                }

                break;
            }
            case '%' : {
                op2 = pop();

                if (op2 != 0.0) {
                    // printf("19. push form mod\n");
                    push(fmod(pop(), op2));
                } else {
                    printf("error: zero divisor\n");
                }

                break;
            }
            case '?': {

                if (sp > 0) {
                    top = val[sp - 1];
                } else {
                    printf("The stack is empty...\n");
                }

                break;
            }
            case '|': {

                if (sp > 0) {
                    push(val[sp - 1]);
                    top = 0;
                    printf("Pushed top element...\n");
                } else {
                    printf("The stack is empty...\n");
                }

                break;
            }
            case '_': {

                if (sp > 1) {
                    op2 = val[sp - 1];
                    val[sp - 1] = val[sp - 2];
                    val[sp - 2] = op2;
                    top = 0;
                } else {
                    printf("The stack size is less than 2\n");
                }

                break;
            }
            case '&': {
                sp = 0;
                break;
            }
            case '\n': {
                printf("\t%.8g\t%.8g\n", pop(), top);
                break;
            }
            default: {
                printf("error unknown command %s\n", s);
                break;
            }
        }

    }

    return 0;
}