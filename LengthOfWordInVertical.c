// write a program to print histogram of the lengths of word in ints input it is easy to draw 
// the histogram with bars horizontal a verical orientaion is more challenging

#include <stdio.h>
#define MAX_LENGTH 20
#define IN 1
#define OUT 0
#define MIN_WORD_LENGTH 0

int main() {
    int ch; int state = OUT;
    int arr[MAX_LENGTH] = {0};
    int cc = 0, wc = 0; //character count, word count
    
    while ((ch = getchar()) != EOF) {
        arr[cc] = ch;
        cc++;

        if (ch == ' ' || ch == '\n' || ch == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            wc++;
        }

    }

    // printf("Number of words: %d\n", wc);

    int nArr[wc];

    for (int i = 0; i < wc; i++) {
        nArr[i] = 0;
    }

    int pc = 0, index = 0, max = MIN_WORD_LENGTH;//per count

    for (int i = 0; i < cc; i++) {

        if (arr[i] != ' ' && arr[i] != '\t' && arr[i] != '\n') {
            ++pc;
        } else {
            nArr[index++] = pc;
            max = pc > max? pc : max;
            pc = 0;
        }

    }

    nArr[index] = pc;
    max = pc > max? pc : max;

    // printf("Max of words: %d value of PC: %d value of index: %d\n", max, pc, index);

    // for (int i = 0; i < wc; i++) {
    //     printf("%d ", nArr[i]);
    // }

    // printf("\n");

    int mArr[max][wc];

    for (int i = 0; i < max; i++) {
        
        for (int j = 0; j < wc; j++) {
            mArr[i][j] = 0;
        }

    }

    for (int col = 0; col < wc; col++) {
        int row = nArr[col];

        while(row > 0) {
            mArr[max - row--][col] = 1;
        }

    }

    for (int row = 0; row < max; row++) {
        printf("\n");

        for (int col = 0; col < wc; col++) {
            printf("%c\t", mArr[row][col] == 1? '*' : ' ');
        }

    }

    printf("\n");

    for (int i = 0; i < cc; i++) {

        if (arr[i] == ' ' || arr[i] == '\n' || arr[i] == '\t') {
            printf("\t");
        } else {
            printf("%c", arr[i]);
        }
    }

    printf("\n");

    return 0;

}