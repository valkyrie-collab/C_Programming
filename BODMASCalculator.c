#include <stdio.h>
#define MAX_LENGTH 100

int get_eqn(char arr[], int limit) {
    int count;
    char ch;

    for (int i = 0; i < limit - 1 && (ch != getchar()) && ch != '\n'; count++) {
        arr[count] = ch;
    }

    if (ch == '\n') {
        arr[count++] = '\n';
    }

    arr[count] = '\0';

    return count;
}

void display(char arr[], int len) {
    printf("[");

    for (int i = 0; i < len; i++) {
        printf("%c, ", arr[i]);
    }

    printf("\b\b]\n");
}

void display(int arr[], int len) {
    printf("[");

    for (int i = 0; i < len; i++) {
        printf("%d, ", arr[i]);
    }

    printf("\b\b]\n");
}

int eqn_cal(int num_one, int num_two, char sign) {
    int sum;

    switch (sign) {
        case '*': {
            sum = num_one * num_two;
            break;
        }
        case '+': {
            sum = num_one + num_two;
            break;
        }
        case '-': {
            sum = num_one - num_two;
            break;
        }
        case '/': {
            sum = num_one / num_two;
            break;
        }
        default: {
            sum = -1;
            break;
        }
    } 

    return sum;
}

int is_sym(char ch) {
    char sym_arr[6] = {'(', ')', '+', '-', '/', '*', ' '};

    for (int i = 0; i < 6; i++) {
        
        if (sym_arr[i] == ch) {
            return 1;
        }

    }

    return 0;
}

int solve(int num_st_arr[], int num_arr[], int n_top, int n_len, 
    char ch_st_arr[], char ch_arr[], int c_top, int c_len) {
        int prio_arr[6] = {3, 0, 1, 0, 1, 2}; 
        int num_one;
        int num_two;
        int ni;
        int ci;
        int bi;

        ni = 2;
        ci = 1;

        while (ni < n_len && ci < c_len) {

            if (ch_arr[ci] == '(') {
                ch_st_arr[++c_top] = '(';
                num_st_arr[++n_top] = num_arr[ni++];
                num_st_arr[++n_top] = num_arr[ni];
            }else if (ch_st_arr[c_top] == '(' && 
                (ch_arr[ci] == '*' || ch_arr[ci] == '+' || ch_arr[ci] == '-' || ch_arr[ci] == '/')) {
                    ch_st_arr[++c_top] = ch_arr[ci];
            } else if (ch_arr[ci] == ')') {

                for (int i = ci; i > -1 && ch_st_arr[c_top] != '('; i--) {
                    num_one = num_st_arr[n_top];
                    num_two = num_st_arr[--n_top];

                    num_st_arr[n_top] = eqn_cal(num_one, num_two, ch_st_arr[c_top]);

                    --c_top;
                }

            } else if (prio_arr[ch_st_arr[c_top] - '*'] >= prio_arr[ch_arr[ci] - '*']) {
                num_st_arr[++n_top] = num_arr[ni];
                num_one = num_st_arr[n_top];
                num_two = num_st_arr[--n_top];

                num_st_arr[n_top] = eqn_cal(num_one, num_two, ch_st_arr[c_top]);

                ch_st_arr[c_top] = ch_arr[ci];
            } else if (prio_arr[ch_st_arr[c_top] - '*'] < prio_arr[ch_arr[ci] - '*']) {
                num_st_arr[++n_top] = num_arr[ni];
                ch_st_arr[++c_top] = ch_arr[ci];
            }

            ni++;
            ci++;
        }        

    return num_st_arr[n_top];
}

void itop(char arr[], int len) {
    int ch_st_arr[len];
    int num_st_arr[len];
    int num_arr[len];
    char ch_arr[len];
    int num;
    int ch_point;
    int ni;
    int ci;

    ch_point = num = ci = ni = 0;

    for (int i = 0; i < len; i++) {

        if (is_sym(arr[i])) {
            ch_point = 1;

            if (arr[i] != ' ') {
                ch_arr[ci++] = arr[i];
            }

        } else if (!ch_point) {
            num = num * 10 + (arr[i] - '0');
        } else if (ch_point) {
            num_arr[ni++] = num;
        }

    }

    printf("The num array: ");
    display(num_arr, ni);

    printf("The char array: ");
    display(ch_arr, ci);

    ch_st_arr[0] = ch_arr[0];
    num_st_arr[0] = num_arr[0];
    num_st_arr[1] = num_arr[1];

    solve(num_st_arr, num_arr, 1, ni, ch_st_arr, ch_arr, 0, ci);

}

int main() {
    return 0;
}