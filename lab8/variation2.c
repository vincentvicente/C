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
#include <stdbool.h>
#include <sys/time.h>

// Global variables for tracking function calls and comparisons
int numPartitionCalls = 0;
int numQuicksortCalls = 0;
int numComparisons = 0;

// Function to swap two elements in an array
void Swap(int* array, int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

// Function to determine the median of three elements and position it as pivot
void DetermineMedianPivot(int* array, int low, int high) {
    int mid = low + (high - low) / 2;

    // Ordering the low, mid, high elements
    if (array[mid] < array[low])
        Swap(array, low, mid);
    if (array[high] < array[low])
        Swap(array, low, high);
    if (array[mid] < array[high])
        Swap(array, mid, high);

    // Placing the median as pivot to the first position
    Swap(array, low, high);
}

// Function to partition the array around the pivot
int Partition(int* array, int low, int high) {
    numPartitionCalls++;
    // Setting the median of low, mid, and high elements as the pivot
    DetermineMedianPivot(array, low, high);
    int pivot = array[low];
    int leftWall = low;

    for (int i = low + 1; i <= high; i++) {
        numComparisons++;
        if (array[i] < pivot) {
            leftWall++;
            Swap(array, i, leftWall);
        }
    }
    Swap(array, low, leftWall);
    return leftWall;
}

// Recursive Quicksort function
void Quicksort(int* array, int low, int high) {
    numQuicksortCalls++;
    if (low < high) {
        int pivotLocation = Partition(array, low, high);
        Quicksort(array, low, pivotLocation);
        Quicksort(array, pivotLocation + 1, high);
    }
}

// Function to print the array
void PrintArray(int* array, int numElements) {
    printf("[");
    for (int i = 0; i < numElements; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

// Function to verify if the array is sorted
int CheckArraySorted(int* array, int numElements) {
    for (int i = 1; i < numElements; i++) {
        if (array[i] < array[i - 1]) {
            printf("NOT SORTED!!!\n");
            return 0;
        }
    }
    return 1;
}

// Function to measure and print sorting time and statistics for different array sizes
void MeasureSortingTime(int* sizes, int length) {
    struct timeval begin, end;

    printf("%-8s | %-12s | %-20s | %-20s | %-20s | %-20s\n",
           "Size", "Time (s)", "Time (micros)", "Partition Calls", "Quicksort Calls", "Comparisons");
    printf("------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < length; i++) {
        int numElements = sizes[i];
        int* elements = (int*)malloc(sizeof(int) * numElements);

        srand(42);
        for (int j = 0; j < numElements; j++) {
            elements[j] = (rand() % 90) + 10; // Populate the array with random values
        }

        // Reset statistics for each array size
        numPartitionCalls = 0;
        numQuicksortCalls = 0;
        numComparisons = 0;

        gettimeofday(&begin, NULL);
        Quicksort(elements, 0, numElements - 1);
        gettimeofday(&end, NULL);

        CheckArraySorted(elements, numElements);
        free(elements);

        long seconds = (end.tv_sec - begin.tv_sec);
        long microseconds = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);

        printf("%-8d | %-12ld | %-20ld | %-20d | %-20d | %-20d\n",
               numElements, seconds, microseconds, numPartitionCalls, numQuicksortCalls, numComparisons);
    }
}

int main() {
    int arraySizes[] = {16, 64, 128, 512, 1024, 2048}; // Sizes of arrays to be tested
    int length = sizeof(arraySizes) / sizeof(arraySizes[0]);
    MeasureSortingTime(arraySizes, length);
}

