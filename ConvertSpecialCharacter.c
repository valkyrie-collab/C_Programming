/*Write a function escape(s, t) that convert character like newline and tab into visible escape sequence like \n
and \t as it copies string t and s. Use a switch write function for the other direction as well converting
escape sequence into the real character
*/

#include <stdio.h>
#define MAX_LENGTH 1000

void escapes(char char_arr[], char new_arr[]) {
    int index;
    int index_two;

    index = index_two = 0;

    while (char_arr[index] != '\0') {

        switch (char_arr[index]) {
            case '\n': {
                new_arr[index_two++] = '\\';
                new_arr[index_two] = 'n';
                break;
            }
            case '\t': {
                new_arr[index_two++] = '\\';
                new_arr[index_two] = 't';
                break;
            }
            default: {
                new_arr[index_two] = char_arr[index];
                break;
            }
        }

        index++;
        index_two++;
    }

    new_arr[index_two] = '\0';
}

int getlines(char char_arr[], int limit) {
   int count;
   char ch;

   for (count = 0; count < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; count++) {
       char_arr[count] = ch;
   }

   if (ch == '\n') {
       char_arr[count++] = ch;
   }

   char_arr[count] = '\0';

   return count;
}

int main() {
    int len;
    char char_arr[MAX_LENGTH] = {'\0'};
    char new_arr[MAX_LENGTH] = {'\0'};

    len = getlines(char_arr, MAX_LENGTH);
    escapes(char_arr, new_arr);

    printf("The size of the char arr is: %d\n and the original String is: %s\n and new modified arr: %s\n", len, char_arr, new_arr);
    
    return 0;
}