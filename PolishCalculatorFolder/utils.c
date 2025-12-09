#include <stdio.h>
#include <ctype.h>
#include "cal.h"

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

        while (isdigit(s[++i] = c = getlines())) {
            continue;
        }

    }

    if (c == '.') {

        while (isdigit(s[++i] = c = getlines())) {
            continue;
        }

        if (s[i - 1] == '.') {
            return '?';
        }

    }

    s[i] = '\0';

    if (c != EOF) {
        ungetchar(c);
    }

    return NUMBER;
}