/*Write a function rightrot(x, n) that returns the value of the integer rotated to the right by n bit position*/

#include <stdio.h>

int rightrot(int num, int bits) {
    int temp_num;
    int mask;
    int last_bits;
    int count;

    count = 0;
    temp_num = num;
    mask = ~(~0 << bits);
    last_bits = num & mask;

    while (temp_num > 0) {
        temp_num = temp_num / 2;
        count++;
    }

    count = count - bits;

    printf("The value of num: %d\n", num);
    printf("The value of count: %d\n", count);
    printf("The value of last_bits: %d\n", last_bits);

    last_bits = (last_bits << count);
    printf("second The value of last_bits: %d\n", last_bits);

    return (num >> bits) | last_bits;
}

int main() {
    int value;

    value = rightrot(13, 3);
    printf("The value of rightrot is: %d\n", value);

    return 0;
}