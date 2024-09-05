/*
 * Author: Qiyuan Zhu
 * Course: CS5008
 * Date: 1/20/2024
 */

#include <stdio.h>
#include <stddef.h>  // Include this for size_t
#include <stdlib.h>  // Include this for other standard types and functions

// This function prints out a rectangle of the given width and height.
// It has two more arguments: draw character, and whether the rectangle should be filled in or not.
void PrintFancyRectangle(int width, int height, char symbol, int fill) {
    // Print top line
    for (int i = 0; i < width; i++) {
        printf("%c", symbol);
    }
    printf("\n");

    // Print middle lines
    for (int i = 0; i < height - 2; i++) {
        printf("%c", symbol);
        for (int j = 0; j < width - 2; j++) {
            if (fill) {
                printf("%c", symbol);
            } else {
                printf(" ");
            }
        }
        printf("%c\n", symbol);
    }

    // Print bottom line
    if (height > 1) {
        for (int i = 0; i < width; i++) {
            printf("%c", symbol);
        }
        printf("\n");
    }
}

//For test usage
int main() {
    PrintFancyRectangle(5, 4, '+', 0);
    printf("\n");
    PrintFancyRectangle(5, 4, '*', 1);

    return 0;
}
