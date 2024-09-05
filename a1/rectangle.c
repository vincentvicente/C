/*
 * Author: Qiyuan Zhu
 * Course: CS5008
 * Date: 1/20/2024
 */

#include <stdio.h>
#include <stddef.h>  // Include this for size_t
#include <stdlib.h>  // Include this for other standard types and functions

// This function prints an empty rectangle of the specified width and height.
void PrintRectangle(int width, int height) {
    // Print top line
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");

    // Print middle lines
    for (int i = 0; i < height - 2; i++) {
        printf("-");
        for (int j = 0; j < width - 2; j++) {
            printf(" ");
        }
        printf("-\n");
    }

    // Print bottom line
    if (height > 1) {
        for (int i = 0; i < width; i++) {
            printf("-");
        }
        printf("\n");
    }
}

//Test usage
int main() {
    PrintRectangle(5, 4);

    return 0;
}
