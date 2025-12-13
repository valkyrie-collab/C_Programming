#include <stdio.h>
#define SIZE 1000

/*int isalpha(int c) {
   c = c - 'a' + 'A';

   if (c >= 'A' && c <= 'Z') {
        return 1;
   }

   return 0;
}*/

int user_strlen(char *s, int limit) {
    int count;

    for (count = 0; count < limit - 1 && *s != '\0'; s++) {
        count++;
    }

    return count;
}

int main() {
    int len;

    len = user_strlen("hello world", SIZE);
    printf("The size of the String is..%d\n", len);

    return 0;
}