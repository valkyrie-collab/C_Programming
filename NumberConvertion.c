/*Write a function htoi(s) which convert a strin gos hexa decimal to digits (including an optional 0x or 0X)
into its equivalent integer value. The allowable digits are 0 through 9, a through f and A through F*/

#include <stdio.h>
#include <math.h>
#define MAX_LENGTH 1000

char upper(char c) {
    return c - 'a' + 'A';
}

int getdeci(int limit) {
    int num;
    char ch;

    num = 0;

    printf("Enter the value in decimal: ");

    for (int i =0; i < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; i++) {

        if (ch < '0' || ch > '9') {
            return -1;
        }

        num = num * 10 + ch - '0';
    }

    return num;
}

int gethex(char hex_arr[], int limit) {
    int i;
    char ch;

    i = 0;

    printf("Enter the value in hexadecimal: ");

    for (i = 0; i < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; i++) {

        if ((ch < '0' ||  ch > '9') && (ch < 'a' || ch > 'g') && (ch < 'A' || ch > 'G')) {
            return -1;
        }

        if (ch >= 'a' && ch <= 'g') {
            ch = upper(ch);
        }

        hex_arr[i] = ch;
    }

    hex_arr[i] = '\0';

    return i;
}

int htoi(char hex_arr[], int len) {
    int i;
    int sum;
    int num;
    int power;
    int hex_values[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    i = sum = 0;
    power = len - 1;

    while (i < len) {

        if (hex_arr[i] >= '0' && hex_arr[i] <= '9') {
            num = hex_arr[i] - '0';
        } else {
            num = hex_arr[i] - 'A' + 10;
        }

        sum = sum + (num * (int) pow(16.0, (double) power--));
        i++;

    }

    return sum;
}

int itoh(char hex_arr[], int deci) {
    int i;
    int j;
    int k;
    int rem;
    char deci_arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    i = 0;

    while (deci > 0) {
        rem = deci % 16;
        hex_arr[i] = deci_arr[rem];
        deci = deci / 16;
        i++;
    }

    j = 0;
    k = i - 1;

    while (j < k) {

        if (hex_arr[j] != hex_arr[k]) {
            hex_arr[j] = hex_arr[j] ^ hex_arr[k];
            hex_arr[k] = hex_arr[j] ^ hex_arr[k];
            hex_arr[j] = hex_arr[j] ^ hex_arr[k];
            j++;
            k--;
        }

    }

    hex_arr[i] = '\0';

    return i;
}

int main() {
    int len;
    int sum;
    char hex_arr[MAX_LENGTH];

    len = gethex(hex_arr, MAX_LENGTH);
    sum = htoi(hex_arr, len);
    printf("The hex size: %d and the hexadecimal number is: %s\n", len, hex_arr);
    printf("The hexadecimal value is: %s and the decimal value is: %d\n", hex_arr, sum);

    sum = getdeci(MAX_LENGTH);
    len = itoh(hex_arr, sum);

    if (len == -1 || sum == -1) {
        printf("Enter a valid hexadecimal... / decimal....");
    }

    printf("Second The hex size: %d and the hexadecimal number is: %s\n", len, hex_arr);
    printf("Second The hexadecimal value is: %s and the decimal value is: %d\n", hex_arr, sum);

    return 0;
}