/*Write a program to determine the ranges of char short int and long variables both signed and 
unsigned by printing appropite values from standerd headeres and by direct computation. Harder i you 
compute them determine the various floating point types*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("The value of the data types are: Mentioned bellow\n\n");

    printf("The value of Signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("The value of unsigned char: %d to %d\n\n", 0, UCHAR_MAX);

    printf("The value of signed Short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("The value of unsigned short: %d to %d\n\n", 0, USHRT_MAX);

    printf("The value of signed integer value: %d to %d\n", INT_MIN, INT_MAX);
    printf("The value of the Unsinged integer value: %u to %u\n\n", 0, UINT_MAX);

    printf("The value of signed Long is: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("The value of unsigned long is: %lu to %lu\n\n", 0UL, ULONG_MAX);

    printf("The value of signed float: %f to %f\n", FLT_MIN, FLT_MAX);
    printf("The value of sigend double: %f to %f\n\n", DBL_MIN, DBL_MAX);
    return 0;
}