#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

char *dis_str(int num) {
	int temp;
	char *str_arr;

	temp = num;
	str_arr = malloc(SIZE);

	while ( temp > 0 ) {
		str_arr++;
		temp = temp / 10;
	}

	*str_arr = '\0';

	while (num > 0) {
		*(--str_arr) = '0' + (num % 10);
		num /= 10;
	}

	return str_arr;
}


int main() {
	int num;
	char *str;

	printf("Enter the number: ");
	scanf("%d", &num);
	printf("The number is: %d\n", num);

	str = dis_str(num);
	printf("The String is %s\n", str);
	free(str);

	return 0;
}
