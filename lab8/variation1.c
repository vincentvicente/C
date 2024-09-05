/**
 *  CS 5008: Spr 2024
 *  Northeastern University, Seattle
 *  lab8
 *
 *  Author: Qiyuan Zhu(04/02/2024)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <stdbool.h>

// Global variables to keep track of function calls and comparisons
int num_partition_calls = 0;
int num_quicksort_calls = 0;
int num_comparisons = 0;

// Function to swap two elements in an array
void Swap(int* array, int ind1, int ind2) {
    int tmp = array[ind1];
    array[ind1] = array[ind2];
    array[ind2] = tmp;
}

// Function to shuffle the elements of an array
void shuffle_func(int* arrayPtr, int low, int high) {
    srand(time(NULL)); // Initialize random seed
    for (int i = low; i <= high; i++) {
        int j = rand() % (i + 1);  // Generate a random index
        Swap(arrayPtr, i, j); // Swap elements at indices i and j
    }
}

// Function to partition the array around a pivot
int Partition(int* data, int low, int high) {
    num_partition_calls++;
    int pivot = data[low]; // Choosing the first element as pivot
    int leftwall = low;

    for (int i = low + 1; i <= high; i++) {
        num_comparisons++;
        if (data[i] < pivot) {
            leftwall++;
            Swap(data, i, leftwall);
        }
    }
    Swap(data, low, leftwall);
    return leftwall;
}

// The Quicksort function
void Quicksort(int* data, int low, int high) {
    static bool firstShuffle = true; // Flag to check if it's the first shuffle

    if (firstShuffle) {
        shuffle_func(data, low, high); // Shuffle the data only once before sorting
        firstShuffle = false; // Reset flag after first shuffle
    }
    num_quicksort_calls++;
    if (low < high) {
        int pivot_location = Partition(data, low, high);
        Quicksort(data, low, pivot_location);
        Quicksort(data, pivot_location + 1, high);
    }
}

// Function to print the array elements
void PrintArray(int* array, int num_elems) {
    printf("[");
    for (int i = 0; i < num_elems; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

// Function to check if the array is sorted
int CheckArray(int* array, int num_elems) {
    for (int i = 1; i < num_elems; i++) {
        if (array[i] < array[i - 1]) {
            printf("NOT SORTED!!!\n");
            return 0;
        }
    }
    return 1;
}

// Function to measure and print sorting time and statistics for various array sizes
void getSortTime(int* sizes, int length) {
    struct timeval begin, end;

    printf("%-8s | %-12s | %-20s | %-20s | %-20s | %-20s\n",
           "Size", "Time (s)", "Time (micros)", "Partition Calls", "Quicksort Calls", "Comparisons");
    printf("------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < length; i++) {
        int num_elems = sizes[i];
        int* integers = (int*)malloc(sizeof(int) * num_elems);

        srand(42); // Set seed for reproducibility
        for (int i = 0; i < num_elems; i++) {
            integers[i] = (rand() % 90) + 10; // Populate array with random values
        }

        // Reset counters for each array size
        num_partition_calls = 0;
        num_quicksort_calls = 0;
        num_comparisons = 0;

        gettimeofday(&begin, NULL); // Start timer
        Quicksort(integers, 0, num_elems - 1); // Perform quicksort
        gettimeofday(&end, NULL); // End timer

        long seconds = (end.tv_sec - begin.tv_sec);
        long micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);

        // Check if the array is sorted and free memory
        CheckArray(integers, num_elems);
        free(integers);

        // Print sorting time and statistics
        printf("%-8d | %-12ld | %-20ld | %-20d | %-20d | %-20d\n",
               num_elems, seconds, micros, num_partition_calls, num_quicksort_calls, num_comparisons);
    }
}

int main() {
    int dataSize[] = {16, 64, 128, 512, 1024, 2048}; // Array sizes to test
    int length = sizeof(dataSize) / sizeof(dataSize[0]); // Calculate the number of test cases
    getSortTime(dataSize, length); // Measure and print sorting time and statistics
}

