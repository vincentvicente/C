/*
 * Author: Qiyuan Zhu
 * Course: CS5008
 * Date: 1/26/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "a2.h"
#include <string.h>

// Print the string <first> <middle> <last>
void Big(Name *name) {
   if (name == NULL) {
        printf("Invalid name pointer\n");
        return;
    }

    // Check if the middle name is NULL
    if (name->middle == NULL) {
        // If middle name is NULL, print first and last name
        printf("%s %s\n", name->first, name->last);
    } else {
        // If middle name is not NULL, print first, middle, and last name
        printf("%s %s %s\n", name->first, name->middle, name->last);
    }
}

// Print the string <last>, <first>
void Last(Name *name) {
	if (name == NULL) {
        	printf("Invalid name pointer\n");
       		return;
    }
}

// Print the string <first> <last>
void Reg(Name *name) {
    if (name == NULL) {
        printf("Invalid name pointer\n");
        return;
    }
    // Print first and last name
    printf("%s %s\n", name->first, name->last);
}
	
// Print the string <first> <middle-initial>. <last>
void Mid(Name *name) {
    if (name == NULL) {
        // Handle the case where the name pointer is NULL
        printf("Invalid name pointer\n");
        return;
    }

    if (name->middle == NULL) {
        // If middle name is NULL, print first and last name
        printf("%s %s\n", name->first, name->last);
    } else {
        // If middle name is not NULL, print first, middle initial, and last name
        printf("%s %c. %s\n", name->first, name->middle[0], name->last);
    }
}

// Print the first name only.
void Small(Name *name) {
    if (name == NULL) {
        // Handle the case where the name pointer is NULL
        printf("Invalid name pointer\n");
        return;
    }

    // Print the first name only
    printf("%s\n", name->first);
}

// Given a format char, print the given name in the format specified by char.
void FormatName(Name *name, char format) {
    if (name == NULL) {
        printf("Invalid name pointer\n");
        return;
    }

    switch (format) {
        case 'B':
            Big(name);
            break;
        case 'L':
            Last(name);
            break;
        case 'R':
            Reg(name);
            break;
        case 'M':
            Mid(name);
            break;
        case 'S':
            Small(name);
            break;
        default:
            printf("Invalid format character\n");
    }
}

// Given a name, a format and a destination array, put the properly formatted name in the destination array, not printing anything on the screen.
void FillName(Name *name, char format, char *dest) {
    if (name == NULL || dest == NULL) {
        return;
    }

    switch (format) {
        case 'B':  // Big format
            sprintf(dest, "%s %s %s", name->first, name->middle ? name->middle : "", name->last);
            break;
        case 'L':  // Last format
            sprintf(dest, "%s, %s", name->last, name->first);
            break;
        case 'R':  // Regular format
            sprintf(dest, "%s %s", name->first, name->last);
            break;
        case 'M':  // Middle format
            if (name->middle && name->middle[0] != '\0') {
                sprintf(dest, "%s %c. %s", name->first, name->middle[0], name->last);
            } else {
                sprintf(dest, "%s %s", name->first, name->last);
            }
            break;
        case 'S':  // Small format
            sprintf(dest, "%s", name->first);
            break;
        default:
            // Handle invalid format character
            strcpy(dest, ""); // Clear dest to indicate error
    }
}

