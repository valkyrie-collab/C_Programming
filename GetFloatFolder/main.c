#include <stdio.h>
#include "gfloat.h"

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