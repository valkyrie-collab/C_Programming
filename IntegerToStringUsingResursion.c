#include <stdio.h>
#define SIZE 1000

void int_to_str(int num, char str[], int len) {

    if (num <= 0) {
        return;
    }
    
    str[--len] = num % 10 + '0';

    int_to_str(num / 10, str, len);

}

int main() {
    int constrain, num, count;
    char str[SIZE];

    constrain = 1;
    count = 0;

    printf("Enter the number: ");
    scanf("%d", &num);

    while (num > constrain && constrain < SIZE) {
        constrain *= 10;
        count++;
    }

    int_to_str(num, str, count);

    str[count++] = '\n';
    str[count] = '\0';

    printf("The number is %s", str);

    return 0;
}