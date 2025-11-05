#include <stdio.h>

void main() {
    //Normal
    printf("Hello world\n");
    //For double quotes
    printf("\"Hello world\"\n");
    //For backspace "\b"
    printf("back\b Hello world\n");
    //For tab "\t"
    printf("\tHello world\n");
    //using "\n" as escape character
    printf("Hello, ");
    printf("world");
    printf("\n");
    //printing escape characters using "\\"
    printf("Hello \\n world\n");
    printf("\\b Hello world\\b\n");
    //printing to check if any other ex. "\c" escape character like working or not
    // we are getting the following error
    // EscapeCharacters.c: In function ‘main’:
    // EscapeCharacters.c:20:29: warning: unknown escape sequence: '\c'
    // 20 |     printf("\cHello world\c");
    //     |                             ^
    // EscapeCharacters.c:20:29: warning: unknown escape sequence: '\c'
    // printf("\cHello world\c");
    return ;
}