#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define BUFF_SIZE 100

double buff_arr[BUFF_SIZE] = {0};
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

int get_float(double *pn) {
    int sign, c;

    while (isspace(c = getchs())) {
        continue;
    }

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {

        if (buff_arr[buff_top + 1] != c) {
            ungetchs(c);
        }

        return 0.0;
    }

    sign = (c == '-')? -1 : 1;

    if (c == '+' || c == '-') {

        if (!isdigit(c = getchs())) {
            ungetchs(sign == -1? '-' : '+');
            ungetchs(c);

            return 0.0;
        }
    
    }

    while (isdigit(c) && c != EOF) {
        *pn = 10.0 * *pn + (double)(c - '0');
        c = getchs();
    }

    if (c == '.') {
        int point;
        point = 0;

        while (isdigit(c = getchs()) && c != EOF) {
            *pn = 10.0 * *pn + (double)(c - '0');
            point++;
        }

        *pn = sign * (*pn / pow(10, point));

        return c;
    }

    if (c != EOF) {
        ungetchs(c);
    }

    return c;
}

int main() {
    int val;
    double arr[10] = {0.0};

    printf("Enter integers separated by spaces or newlines (Ctrl+D to end):\n");

    for (val = 0; val < 10 && get_float(&arr[val]) != EOF; val++) {
        printf("Read number is: %g\n", arr[val]);
    }

    printf("The total integer read: %d\n", val);

    return 0;
}