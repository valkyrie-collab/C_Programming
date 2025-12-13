#include <stdio.h>
#define SIZE 1000

int getlines(char *pstr_arr, int limit) {
    int count, c;

    for (count = 0; count < limit - 1 && (c = getchar()) != EOF && c != '\n'; count++) {
        *pstr_arr++ = c;
    }

    if (c == '\n') {
        *pstr_arr++ = '\n';
        count++;
    }

    *pstr_arr = '\0';

    return count;
}

void cp_str(char *gp, char *cp) {

    while ((*cp = *gp) != '\0') {
        gp++; 
        cp++;
    }

}

int main() {
    int len;
    char gp[SIZE];
    char cp[SIZE];

    printf("Enter the String below: ");
    len = getlines(gp, SIZE);
    printf("The given string is: %s", gp);
    
    cp_str(gp, cp);
    printf("The copy is %s", cp);

    return 0;
}