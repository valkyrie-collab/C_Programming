/*In a two's complement number system x &= (x - 1) deletes the rightmost 1-bit in x Explain why. Use this
Observation to write a faster version of bitcount*/

#include <stdio.h>

int bitcount(int num) {
    int count;

    count = 0;
    
    while (num) {
        num &= num - 1;
        count++;
    }

    return count;
}

int main() {
    int value;

    value = bitcount(13);
    printf("The value of bitcount is: %d\n", value);

    return 0;
}