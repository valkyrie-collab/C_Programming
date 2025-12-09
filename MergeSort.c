#include <stdio.h>
#define MAX_LENGTH 1000

int len;

void merge(int arr[], int low, int high, int mid) {
    int len_one;
    int len_two;
    int i, j, k;
    extern int len;

    len_one = mid - low + 1; 
    len_two = high - mid; 

    int arr_one[len_one];
    int arr_two[len_two];

    for (i = 0; i < len_one; i++) {
        arr_one[i] = arr[low + i];
    }

    for (i = 0; i < len_two; i++) {
        arr_two[i] = arr[mid + i + 1];
    }

    i = j = 0;
    k = low;

    while (i < len_one && j < len_two) {
        
        if (arr_one[i] <= arr_two[j]) {
            arr[k] = arr_one[i++];
        } else {
            arr[k] = arr_two[j++];
        }

        k++;
    }

    while (i < len_one) {
        arr[k++] = arr_one[i++];
    }

    while (j < len_two) {
        arr[k++] = arr_two[j++];
    }

}

void sort(int arr[], int low, int high) {
    int mid;
    
    if (low >= high) {
        return;
    }

    mid = low + ((high - low) / 2);
    sort(arr, low, mid);
    sort(arr, mid + 1, high);
    merge(arr, low, high, mid);
}

void initialization(int arr[]) {
    int i;
    extern int len;

    i = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &len);

    printf("Enter the values of array below: \n");

    while (i < len) {
        scanf("%d", &arr[i++]);
    }
    
}

void display(int arr[]) {
    extern int len;
    printf("[");

    for (int i = 0; i < len; i++) {
        printf("%d, ", arr[i]);
    }

    printf("\b\b]\n");
}

int main() {
    extern int len;
    int arr[MAX_LENGTH];

    initialization(arr);
    printf("Before Sorting the array is: ");
    display(arr);
    
    sort(arr, 0, len - 1);
    printf("After Sorting the array is: ");
    display(arr);

    return 0;
}