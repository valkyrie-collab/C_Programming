/*Write a function setbits(x, p, n, y) that return x with the n bits that begin at position p set to the 
rightmost n bits of y leaving the other bits unchanged*/

#include <stdio.h>

int setbits(int num_one, int pos, int bits, int num_two) {
    int store_bit;
    int shift_bit;
    int mask;
    
    mask = ~(~0 << bits); 
    shift_bit = num_one & ~(mask << (pos + 1 - bits)); 
    store_bit = (num_two & mask) << (pos + 1 - bits); 

    return shift_bit | store_bit;
}

int main() {
    int value;
    value = setbits(33, 4, 3, 5);

    printf("The value of the setbits function: %d\n", value);

    return 0;
}