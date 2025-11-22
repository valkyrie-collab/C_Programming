/*Write the function any(s1, s2) which returns the first location in the string s1 where any character from the string s2
occurs or -1 if s1 contains no characters from s2 (the stander library function strpbrk does the same job but 
returns a pointer to the location)*/

#include <stdio.h>
#define MAX_LENGTH 46
#define MAX_WORDS 26

int len_one;
int len_two;

char upper(char letter) {

    if (letter >= 'a' && letter <= 'z') {
        letter = letter - 'a' + 'A';
    }

    return letter;
}

void any(char first_word[], char second_word[]) {
    int freq_arr[26] = {0};
    extern int len_one;
    extern int len_two;
    int i;
    int j;

    i = j = 0;

    while (i < len_one && j < len_two) {
        freq_arr[upper(first_word[i++]) - 'A']++;
        freq_arr[upper(second_word[j++]) - 'A']++;
    }

    for (i = 0; i < len_one; i++) {

        if (freq_arr[upper(first_word[i]) - 'A'] >= 2) {
            printf("%c, ", first_word[i]);
        }

    }

    printf("\n");
}

int words(char char_arr[], int limit) {
    int count;
    char ch;

    for (count = 0; count < limit && (ch = getchar()) != EOF && ch != '\n'; count++) {
        char_arr[count] = ch;
    }

    char_arr[count] = '\0';

    return count;
}

int main() {
    extern int len_one;
    extern int len_two;
    char first_word[MAX_LENGTH];
    char second_word[MAX_LENGTH];

    printf("Enter the first word: ");
    len_one = words(first_word, MAX_LENGTH);
    printf("Enter the second word: ");
    len_two = words(second_word, MAX_LENGTH);

    printf("The value of len one: %d and the word is: %s\n", len_one, first_word);
    printf("The value of len two: %d and the word is: %s\n", len_two, second_word);

    any(first_word, second_word);

    return 0;
}