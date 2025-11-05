#include <stdio.h>

void main() {
    int n1 = 0, ch;

    //ctrl+d is End Of File
    //each time while is running the ch variable taking character as input
    //and if the input in "\n" next line then the n1 is increasing by one
    while ((ch = getchar()) != EOF) {

        if (ch == '\n') {
            ++n1;
        }

    }

    printf("%1d\n",n1);

}