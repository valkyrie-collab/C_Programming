#include <stdio.h>
#define START 0

void main() {
    int tabs = START, space = START, newline = START, ch;

    //when writing something (rajarshi biswas) in the get char it will take 
    // or run the while loop untile all the letters have been read 
    //before stoping to get another we use ctrl+d to top the loop by giving its
    //end EOF value so when the loop run checking the values when it meets the EOF
    //value at the end of rajarshi biswas it stop immediatly 
    while ((ch = getchar()) != EOF) {
        putchar(ch);
        printf("\nvalue of ch: %c\n", ch);
        //when running printf the values inside the printf is
        //evaluted first before it actually start printing 
        //then we give thing putchar this will usually print the first then other
        //printf("value of ch: %c\n", putchar(ch));

        if (ch == '\t') {
            tabs++;
        } else if (ch == ' ') {
            space++;
        } else if (ch == '\n') {
            newline++;
        }

    }

    int totalValue = tabs + space + newline;
    printf("Number of tabs: %d\n Number of space: %d\n Number of Newlines: %d\n Total Numbers: %d\n", tabs, space, newline, totalValue);

}