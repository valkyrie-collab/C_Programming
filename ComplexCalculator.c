//A calculator program that follows BODMAS Rule

#include <stdio.h>
#define MAX_LENGTH 1000

int get_equation(char eqn_arr[], int limit) {
    int count;
    int ch;
    eqn_arr[0] = '(';

    for (count = 1; count < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; count++) {
        // printf("The value of ch: %c\n", ch);

        if ((ch != '(' && ch != ')') && (ch != '*' && ch != '-' && ch != '/' && ch != '+') && (ch < '0' || ch > '9')) {
            return 0;
        }

        if (ch == '(' && eqn_arr[count - 1] >= '0' && eqn_arr[count - 1] <= '9') {
            eqn_arr[count++] = '*';
            eqn_arr[count] = '(';
        } else if (ch == ')') {
            eqn_arr[count++] = ch;
            eqn_arr[count] = '*';
        } else if (ch != '*' && eqn_arr[count - 1] == '*' && eqn_arr[count - 2] == ')') {
            
            if (ch >= '0' && ch <= '9') {
                eqn_arr[count] = ch;
            } else {
                eqn_arr[--count] = ch;
            }
        } else {
            eqn_arr[count] = ch;
        }

    }

    eqn_arr[count++] = ')';
    eqn_arr[count] = '\0';

    return count;
}

int calculate(char symbol, int num_one, int num_two) {
    int value;
    value = 0;

    switch (symbol) {

        case '*': {
            value = num_one * num_two;
            break;
        }

        case '/': {
            value = num_one / num_two;
            break;
        }

        case '+': {
            value = num_one + num_two;
            break;
        }

        case '-': {
            value = num_one - num_two;
            break;
        }

        default: {
            value = -1;
            break;
        }

    }

    return value;
}

int final_solve(char char_stack[], int num_stack[], int char_top, int num_top) {
    int sum;

    sum = 0;

    for (int i = char_top; i > -1; i--) {
        sum = calculate(char_stack[i], num_stack[num_top - 1], num_stack[num_top]);
        // printf("sum value: %d\n", sum);
        num_stack[num_top--] = 0;
        num_stack[num_top] = sum;
        char_stack[i] = '\0'; 
    }

    return sum;
}

int solve_equation(char eqn_arr[], int limit) {
    int num_stack[limit];
    int num_arr[limit];
    char char_stack[limit];
    char char_arr[limit];
    int prio_form[6] = {3, 2, 0, 1, 0, 4};
    int num_top;
    int char_top;
    int index;
    int sum;
    int point;

    sum = index = 0;

    for (int i = 0; i < limit; i++) {

        if (eqn_arr[i] >= '0' && eqn_arr[i] <= '9') {
            sum = sum * 10 + (eqn_arr[i] - '0');
        } else if (eqn_arr[i] != '(' && eqn_arr[i] != ')') {
            num_arr[index] = sum;
            char_arr[index++] = eqn_arr[i];
            sum = 0;
        }

    }

    for (int i = 0; i < index; i++) {
        printf("%c, ", char_arr[i]);
    }

    printf("\n");
    num_arr[index] = sum;

    for (int i = 0; i < index + 1; i++) {
        printf("%d, ", num_arr[i]);
    }

    printf("\n");

    num_top = char_top = sum = 0;
    num_stack[0] = num_arr[0];
    num_stack[1] = num_arr[1];
    char_stack[0] = char_arr[0];
    char_top = 0;
    num_top = 1;
    point = 1;

    while (point < index) {
        // printf("value of point: %d and the symbol it has: %c And the priority: %d\n", point, char_arr[point], prio_form[char_arr[point] - '*']);
        // if (char_top >= 0) {
        //     // printf("value of char_top: %d and the symbol it has: %c And the priority: %d\n", char_top, char_stack[char_top], prio_form[char_stack[char_top] - '*']);
        // }
        if (char_top < 0) {
            char_top++;
            num_stack[++num_top] = num_arr[++point];
        }

        if (prio_form[char_stack[char_top] - '*'] > prio_form[char_arr[point] - '*']) {
            sum = calculate(char_stack[char_top], num_stack[num_top - 1], num_stack[num_top]);
            // printf("sum value: %d\n", sum);
            num_stack[num_top--] = 0;
            num_stack[num_top] = sum;
            char_stack[char_top--] = '\0';
        } else {
            char_top++;
            char_stack[char_top] = char_arr[point];
            num_top++;
            num_stack[num_top] = num_arr[point + 1];
            point++;
        }

    }

    // printf("value of char_top: %d and num_top: %d\n", char_top, num_top);
    // printf("value of char_top: %c and num_top: %d\n", char_stack[char_top], num_stack[num_top]);

    // printf("value of sum: %d\n", sum);
    
    return final_solve(char_stack, num_stack, char_top, num_top);
}

int main() {
    int len;
    char eqn_arr[MAX_LENGTH];

    len = get_equation(eqn_arr, MAX_LENGTH);
    // solve_equation(eqn_arr, len);

    if (!len) {
        printf("The equation is not correct plz check the equation...\n");
    } else {
        printf("The equation string is: %s and the length: %d\n", eqn_arr, len);
    }

    printf("The Solved value is: %d\n",solve_equation(eqn_arr, len));

    return 0;
}