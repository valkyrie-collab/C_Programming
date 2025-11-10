#include <stdio.h>
#define STEPS 20
#define FINAL_RANGE 300
#define INITIAL_RANGE 0

double fah_to_cel(double cel, double fah) {

    while (fah < FINAL_RANGE) {
        cel = 0.555 * (fah - 32.0);
        printf("fah: %3.0f -> cel: %7.2f \n", fah, cel);
        fah += STEPS;
    }

    return cel;

}

double cel_to_fah(double cel, double fah) {

    while (cel < FINAL_RANGE) {
        fah = (cel * 1.8) + 32.0;
        printf("cel: %3.0f -> fah: %7.2f \n", cel, fah);
        cel += STEPS;
    }

    return fah;
}

int main() {

    printf("The Temperature from Fahrenheit to Celsius are: \n");
    double final_fah = fah_to_cel(INITIAL_RANGE, INITIAL_RANGE);
    printf("\nThe Temperature from Celsius to Fahrenheit are: \n");
    double final_cel = cel_to_fah(INITIAL_RANGE, INITIAL_RANGE);

    printf("\nThe final Fahrenheit: %3.2f\n", final_fah);
    printf("The final Celsius: %3.2f\n", final_cel);

    return 0;
}