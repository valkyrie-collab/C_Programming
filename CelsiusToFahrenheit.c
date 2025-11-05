#include <stdio.h>

//Celsius to Fahrenheit

void main() {
    float cel = 0.0;
    float fah = 0.0;
    int upper = 300;
    int steps = 20;
    printf("Celsius\tFahrenheit\n");

    while(cel <= upper) {
        fah = (cel * (9.0/5.0)) + 32.0;
        printf("%3.0f\t%7.2f\n", cel, fah);
        cel = cel + steps;
    }

    return ;
}