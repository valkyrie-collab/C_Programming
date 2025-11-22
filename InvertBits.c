/*write a function invert(x, p, n) that returns x with n bits that begin at position p inverted at postion p
leaving other unchanged*/

#include <stdio.h>

int invert(int num, int pos, int bits) {
    int mask;
    int invert_bits;

    mask = ~(~0 << bits);
    invert_bits = ~((num >> (pos + 1 - bits)) & mask) & mask;
    num = num & ~(mask << (pos + 1 - bits));
    invert_bits = invert_bits << (pos + 1 - bits);

    return num | invert_bits;
}

int main() {
    int value;

    value = invert(23, 4, 3);
    printf("The value of the function invert is: %d\n", value);

    return 0;
}