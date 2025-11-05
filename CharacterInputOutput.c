#include <stdio.h>

void main() {
    int ch = getchar();//getchar() store the user input as ascii value
    // int ch;

    //EOF = End Of File
    if (ch != EOF) {
        putchar(ch);//putchar() except only one argument
        printf("\n%d\n", ch);
    } else {
        printf("It is end of file %d\n", EOF);
    }

    return ;
}