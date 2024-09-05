/*
 * Author: Qiyuan Zhu
 * Course: CS5008
 * Date: 1/19/2024
 */

#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>

void printArray(int* arr, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%d", arr[i]);
        if (i < length - 1) {
            printf(",");
        }
    }
    printf("\n");
    return;
}

//Write a function that replaces all numbers greater than ceiling in the arr with ceiling.
void crop_hi(int* arr, int len, int ceiling) {    
    int i;
    for(i=0; i<len; i++) {
        if(arr[i] > ceiling) {
            arr[i] = ceiling;
        }
    }
}

/**
 * Swap the last int in the arr with the middle element in the arr.
 *
 * Precondition(s):
 * - len > 0 (i.e. arrays MUST have at least one element)
 */
void swap_mid_back(int* arr, int len){
    if (len > 1) {
 	int midIndex = (len - 1) / 2;
        int temp = arr[midIndex];
        arr[midIndex] = arr[len - 1];
        arr[len - 1] = temp;
    }
}


/**
 * Replaces all digits in a string with a '*'. 
 */
void redact(char* str){
    while (*str) {
        if (isdigit(*str)) {
            *str = '*';
        }
        str++;
    }
}


/**
 * Compares two integer arrays and tests for equality
 */
bool equalArrays(int* arr1, int size1, int* arr2, int size2) {
    if(size1 != size2) return 0;

    bool res = true;

    int i;
    for(i=0; i <size1; i++) {
        res = res && arr1[i] == arr2[i];
    }

    return res;
}

void testEqualArrays() {
    int arr1[] = {1,2,3,4};
    int arr2[] = {1,2,3,4};
    int arr3[] = {4,3,2,1};
    printf("test1: %d\n", equalArrays(arr1, 4, arr2, 4));
    printf("test2: %d\n", equalArrays(arr1, 3, arr2, 4));
    printf("test3: %d\n", equalArrays(arr1, 4, arr3, 4));
}

int main() {
     // Test cases for crop_hi
     int arr1[] = {1, 2, 3, 4};
     int len1 = sizeof(arr1) / sizeof(arr1[0]);
     crop_hi(arr1, len1, 2);
     printArray(arr1, 4);

     int arr2[] = {-3, 17, 7, -12, 10};
     int len2 = sizeof(arr2) / sizeof(arr2[0]);
     crop_hi(arr2, len2, 8);
     printArray(arr2, 5);

     // Test cases for swap_mid_back
     int arr3[] = {1, 2, 3};
     int len3 = sizeof(arr3) / sizeof(arr3[0]);
     swap_mid_back(arr3, len3);
     printArray(arr3, len3);

     int arr4[] = {-4, 3, 0, 1};
     int len4 = sizeof(arr4) / sizeof(arr4[0]);
     swap_mid_back(arr4, len4);
     printArray(arr4, 4);

    // Test cases for redact
    char str1[] = "The part failed 58% of the time";
    redact(str1);
    printf("Modified: %s\n", str1);    
    char str2[] = "There were 13 As in the class";
    printf("Modified: %s\n", str2);

    testEqualArrays();


    int num = 10; //"10\0"
    char buf[50];
    printf("buf is %s\n", buf);
    const char* flag = "%d";
    sprintf(buf, flag, num);
    printf("buf is %s\n", buf);
    char src[] = "foo";

    char* result = strcat(buf, src);
    printf("the result is %s\n", result);
    return 0;
}
