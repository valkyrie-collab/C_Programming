/*Write a function expand(s1, s2) that expand shorthand notation like a-z in the string s1 into equivalence complete
list abc..xyz in s2 allow for letters of either case and digits and be prepared to handle cases like a-b-c and a-z0-9
and -a-z Arrange that a leading or trailing - is taken literally*/

#include <stdio.h>
#define MAX_LENGTH 1000

int len;

void resolve_shorthand_notation(char shorthand_arr[], char equivalence_arr[]) {
    extern int len;
    char temp_char;
    int break_point;
    int index;
    int srt_index;
    int count;

    printf("value of len: %d\n", len);
    
    index = srt_index = count = break_point = 0;
    temp_char = '\0';

    if (shorthand_arr[srt_index] == '-') {
        equivalence_arr[index++] = shorthand_arr[srt_index++];
    }

    if (shorthand_arr[len - 1] == '-') {
        len--;
    }

    while (srt_index < len) {

        /*Here I have filtered any unknow combo basically if the order is not correct it will stop the code*/
        if (srt_index != 0 && shorthand_arr[srt_index - 1] != '-' 
            && shorthand_arr[srt_index + 1] != '-' && shorthand_arr[srt_index] != '-') {
            return;
        } else if (srt_index == 0 && shorthand_arr[srt_index + 1] != '-') {
            return;
        } else if (srt_index == len - 1 && shorthand_arr[srt_index - 1] != '-') {
            return;
        }

        /*checking if the next char is - or alphabet or digit if - then srt_index will increase by 2
        if not then 1 and it will only happen if the break point is valid means the end of the particular
        char has been reached for a-z z if the end point so break_point will become valid only after it
        reached z*/
        if (shorthand_arr[srt_index + 1] == '-' && !break_point) {
            temp_char = shorthand_arr[srt_index];
            srt_index += 2;
        } else if (!break_point) {
            temp_char = shorthand_arr[srt_index];
            srt_index++;
        }

        if (temp_char >= 'a' && temp_char <= 'z') {
            equivalence_arr[index] = (char) ((int) temp_char + count++);
            break_point = 1;
        } else if (temp_char >= 'A' && temp_char <= 'Z') {
            equivalence_arr[index] = (char) ((int) temp_char + count++);
            break_point = 1;
        } else if (temp_char >= '0' && temp_char <= '9') {
            equivalence_arr[index] = (char) ((int) temp_char + count++);
            break_point = 1;
        }

        /*This part is checking that particular thing and formating each to their required*/
        if (equivalence_arr[index] == shorthand_arr[srt_index]) {
            break_point = 0;
            count = 0;
            srt_index = shorthand_arr[++srt_index] == '-'? ++srt_index : srt_index;
        }

        index++;

    }

    if (shorthand_arr[len] == '-') {
        equivalence_arr[index++] = '-';
    }

    equivalence_arr[index] = '\0';

    printf("The give range is: %s\nThe Expanded string become: %s\n", shorthand_arr, equivalence_arr);
}

int get_shorthand_notation(char char_arr[], int limit) {
    int count;
    char ch;

    for (count = 0; count < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; count++) {
        char_arr[count] = ch;
    }

    char_arr[count] = '\0';

    return count;
}

int main() {
    extern int len;
    char shorthand_arr[MAX_LENGTH];
    char equivalence_arr[MAX_LENGTH];
    
    len = get_shorthand_notation(shorthand_arr, MAX_LENGTH);

    if (len <= 0) {
        printf("Invalid Input..\n");
        return 0;
    }

    resolve_shorthand_notation(shorthand_arr, equivalence_arr);

    return 0;
}