/*Our binary search makes two tests inside the loop when one world suffice. write a version with only one test inside
the loop and measure the difference in run time*/

#include <stdio.h>
#include <time.h>
#define MAX_LENGTH 1000

double cpu_time;

int binarysearch_single_condition(int num_arr[], int len, int find) {
    int mid;
    int left;
    int right;
    int check;
    int start;
    int end;
    extern double cpu_time;

    mid = left = 0;
    right = len - 1;
    check = 0;
    start = clock();

    while (left <= right && !check) {
        mid = left + ((right - left) / 2);

        if (num_arr[mid] > find) {
            right = mid - 1;
        } else {
            check = num_arr[mid] / find;
            left = mid + 1;
        }

    }

    end = clock();
    cpu_time = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000000;

    return check;
}

int binarysearch(int num_arr[], int len, int find) {
    int mid;
    int left;
    int right;
    int start;
    int end;
    extern double cpu_time;

    mid = left = 0;
    right = len - 1;
    start = clock();

    while (left <= right) {
        mid = left + ((right - left) / 2);

        if (num_arr[mid] == find) {
            return 1;
        } else if (num_arr[mid] > find) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }

    }

    end = clock();
    cpu_time = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000000;

    return 0;
}

int initialize(int num_arr[], int limit) {
    int num;
    int index;
    int len;

    printf("Enter the size of the array: ");
    scanf("%d", &len);

    if (len > limit) {
        return -1;
    }

    printf("Enter the elements of array below one by one: \n");

    index = 0;

    while (index < len) {
        scanf("%d", &num);
        num_arr[index++] = num;
    }

    return len;
}

int main() {
    int len;
    int num_arr[MAX_LENGTH] = {0};
    int find;
    int present;

    len = initialize(num_arr, MAX_LENGTH);

    if (len == -1) {
        printf("Not possible length is greater than size alloted\n");
        return 0;
    }

    printf("Enter the number we need to find: ");
    scanf("%d", &find);

    present = binarysearch(num_arr, len, find);

    if (present) {
        printf("The number %d has been found successfully...\n", find);
    } else {
        printf("The number of %d has not been found or not present..\n", find);
    }

    printf("Time used %f\n", cpu_time);

    present = binarysearch_single_condition(num_arr, len, find);

    if (present) {
        printf("The number %d has been found successfully...\n", find);
    } else {
        printf("The number of %d has not been found or not present..\n", find);
    }

    printf("Time used %f\n", cpu_time);

    return 0;
}