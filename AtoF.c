/*Convert exponential to float*/

#include <stdio.h>
#include <math.h>
#define MAX_LENGTH 100

int get_eqn(char expo_arr[], int limit) {
    char ch;
    int count;

    for (count = 0; count < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; count++) {
        expo_arr[count] = ch;
    }

    if (ch == '\n') {
        expo_arr[count++] = '\n';
    }

    expo_arr[count] = '\0';

    return count;
}

double custom_atof(char expo_arr[], int len) {
    double sum;
    int expo;

    sum = 0.0;
    expo = 0;

    for (int i = 0; i < len; i++) {

        if (expo_arr[i] >= '0' && expo_arr[i] <= '9' || expo_arr[i] == '.') {

            if (expo_arr[i] == '.') {
                expo = i + 1;
            } else {
                sum = sum * 10.0 + (expo_arr[i] - '0');
            }

        } else if (expo_arr[i] == 'e' || expo_arr[i] == 'E') {
            sum = sum * pow(10, (-1) * (i - expo));
            expo = expo_arr[++i] >= '0' && expo_arr[i] <= '9'? expo_arr[i] - '0' : (-1) * (expo_arr[++i] - '0');
            sum = sum * pow(10, expo);
        }

    }

    return sum;
}

int main() {
    int len;
    double number;
    char arr[MAX_LENGTH];

    printf("Enter the equation: ");
    len = get_eqn(arr, MAX_LENGTH);
    printf("The equation is: %s", arr);

    number = custom_atof(arr, len - 1);
    printf("The number is: %0.9f\n", number);

    return 0;
}