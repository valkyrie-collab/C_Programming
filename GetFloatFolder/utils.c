#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "gfloat.h"

int get_float(double *pn) {
    int sign, c;

    while (isspace(c = getchs())) {
        continue;
    }

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {

        if (check_buffer(c)) {
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