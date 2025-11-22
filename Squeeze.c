/*write an alternate version of squeeze(s1, s2) that deletes each characters in s1 that matches any character in 
string s2*/

#include <stdio.h>
#define MAX_LENGTH 46
#define MAX_WORDS 25

int len_one;
int len_two;

char upper(char letter) {

    if (letter >= 'a' && letter <= 'z') {
        letter = letter - 'a' + 'A';
    }

    return letter;
}

void squeeze(char first_word[], char second_word[]) {
    char char_arr[MAX_LENGTH];
    int freq_char[26] = {0};
    extern int len_one;
    extern int len_two;
    int i;
    int j;
    int k;

    i = j = k = 0;

    while (i < len_one && j < len_two) {
        freq_char[upper(first_word[i++]) - 'A']++;
        freq_char[upper(second_word[j++]) - 'A']++;
    }

    for (i = 0; i < len_one; i++) {

        if (freq_char[upper(first_word[i]) - 'A'] < 2) {
            char_arr[k++] = first_word[i];
        }

    }

    char_arr[k] = '\0';

    printf("The first word is becomes is: %s\n", char_arr);
}

int word(char char_arr[], int limit) {
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
    len_one = word(first_word, MAX_LENGTH);

    printf("Enter the second word: ");
    len_two = word(second_word, MAX_LENGTH);

    printf("The length of the first word: %d and the string is: %s\n", len_one, first_word);
    printf("The length of the second word: %d and the string is: %s\n", len_two, second_word);

    squeeze(first_word, second_word);

    return 0;
}
