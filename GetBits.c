/*Write a function getbits(unsigned x, position p, number of bits n) to get most significate bits*/

#include <stdio.h>

int getbits(int num, int pos, int bits) {
    int shift_pos;
    int mask;

    shift_pos = num >> (pos + 1 - bits);
    mask = ~(~0 << bits);

    return shift_pos & mask;
}

int main() {
    int value;

    value = getbits(26, 3, 3);
    printf("The value is %d\n", value);

    return 0;
}