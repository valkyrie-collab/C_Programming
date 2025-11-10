/*Write a program to print a histogram of the frequencies fo different characters in its input*/

#include <stdio.h>
#define IN 1
#define OUT 0
#define MAX_ARR_LENGTH 96

int main() {
    int ch;
    int state = OUT;
    int arr[MAX_ARR_LENGTH] = {0};
    int index = 0;
    
    while ((ch = getchar()) != EOF && ch != '\n') {
        arr[ch - 32]++;
    }

    int row = 0, col = 0; 

    for (int i = 0; i < MAX_ARR_LENGTH; i++) {
        row = row < arr[i]? arr[i] : row;
        col = arr[i] > 0? ++col : col;
    }

    char alphaArr[col];
    int freArr[col];
    index = 0;

    for (int i = 0; i < MAX_ARR_LENGTH; i++) {
        
        if (arr[i] > 0) {
            freArr[index] = arr[i];
            alphaArr[index++] = (char) (i + 32);
        }

    }

    // printf("\nThe value of column: %d\n", col);
    // printf("The value of row: %d\n", row);

    // for (int c = 0; c < sizeof(alphaArr) / sizeof(alphaArr[0]); c++) {
    //     printf("%c ", alphaArr[c]);
    // }

    // printf("\n");

    // for (int c = 0; c < sizeof(freArr) / sizeof(freArr[0]); c++) {
    //     printf("%d ", freArr[c]);
    // }

    int mArr[row][col];

    for (int r = 0; r < row; r++) {

        for (int c = 0; c < col; c++) {
            mArr[r][c] = 0;
        }

    }

    for (int c = 0; c < col; c++) {
        int r = freArr[c];
        // int rIndex = row - r--;
        // printf("\n temp row: %d for value of c: %d\n", r, c);

        while (r > 0) {
            // printf("\n%d\n", r);
            mArr[row - r--][c] = 1;
            // rIndex = row - r--;
        }

    }

    printf("\n");

    for (int r = 0; r < row; r++) {

        printf("\n");
        for (int c = 0; c < col; c++) {
            printf(" %c ", mArr[r][c] == 1? '*' : ' ');
        }

    }

    printf("\n");

    for (int i = 0; i < col; i++) {
        printf(" %c ", alphaArr[i]);
    }

    printf("\n");

    return 0;

}