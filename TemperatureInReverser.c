#include <stdio.h>

//In Celsius to Fahrenheit

void main() {
    float cel = 300.0f;
    float fah = (cel * (9.0/5.0) + 32);
    int lower = 0;
    int steps = 30;
    printf("Celsius\tFahrenheit\n");

    for (; fah >= 0; fah = (cel * (9.0/5.0) + 32)) {
        printf("%3.0f\t%6.2f\n", cel, fah);
        cel = cel - steps;
    }

    fah = 300.0f;
    cel = (5.0/9.0) * (fah - 32);
    printf("\nCelsius\tFahrenheit\n");

    for (; cel >= 0; cel = (5.0/9.0) * (fah - 32)) {
        printf("%3.0f\t%6.2f\n", cel, fah);
        fah = fah - steps;
    }

    return;
}