define max_size 1000
define show_size 81

function getlines(int temp_c_arr[], int limit) {
    int count;
    int ch;

    for loop (count = 0; count < limit - 1 && (ch = getchar()) != '\0' && ch != '\n'; count++) {
        temp_c_arr[count] = ch;
    }

    if (ch == '\n') {
        temp_c_arr[count++] = '\n';
    }

    temp_c_arr[count] = '\0';

    return count;
}

main function {
    int len;
    int max;
    char temp_c_arr[max_size];
    char longest_c_arr[max_size];
    char second_longest_c_arr[max_size];

    len = max = 0;

    while ((len = getlines(temp_c_arr, max_size)) > 0) {

        if (len > max) {
            max = len;
            copy(temp_c_arr, longest_c_arr);
        }

        if (len > show_size) {
            copy(temp_c_arr, second_longest_c_arr);
            printf("\n%s\n", second_longest_c_arr)
        }

        for loop {
            temp_c_arr[i] = '\0';
        }

    }

}