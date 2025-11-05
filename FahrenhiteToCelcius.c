#include <stdio.h>

//Celsius to Fahrenhite

void main() {
    float fahrenhite = 0.0;
    float celsius = 0.0;
    int upper = 300;
    int steps = 20;
    printf("Fahrenhite\tCelcius\n");

    while (fahrenhite <= upper) {
        celsius = (5.0/9.0) * (fahrenhite - 32.0);
        printf("  %3.0f\t%6.2f\n", fahrenhite, celsius);
        fahrenhite = fahrenhite + steps;
    }

    return ;
}