#include <stdio.h>

void main() {
    int arr[4] = {100, 200, 150, 300};
    int avg = 0, count = 0;

    for (int i = 1; i < 4; i++) {
        avg = avg + arr[i - 1];

        if (arr[i] > (avg / i)) {
            count++;
        }

        printf("%d ", avg/i);

    }

    printf("\ncount =: %d\n", count);
}