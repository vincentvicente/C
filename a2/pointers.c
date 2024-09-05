#include <stdio.h>

int main() {
    int a = 10;  // Define an integer variable 'a'
    int b = 20;  // Define an integer variable 'b'
    int *ptr_a = &a;  // Define a pointer to 'a'
    int *ptr_b = &b;  // Define a pointer to 'b'

    // Accessing the values of the variables through pointers
    printf("Value of a = %d\n", *ptr_a);
    printf("Value of b = %d\n", *ptr_b);

    // Comparing the values pointed to by the pointers
    if (*ptr_a > *ptr_b) {
        printf("a is greater than b\n");
    } else if (*ptr_a < *ptr_b) {
        printf("a is less than b\n");
    } else {
        printf("a is equal to b\n");
    }

    return 0;
}

