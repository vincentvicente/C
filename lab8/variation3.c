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

// Global counters for function calls and comparisons
int numPartitionCalls = 0;
int numQuicksortCalls = 0;
int numComparisons = 0;

// Function to swap two elements in an array
void Swap(int* array, int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

// Insertion Sort implementation
void InsertionSort(int* array, int length) {
    for (int i = 1; i < length; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
            numComparisons++; // Count each comparison
        }
        array[j + 1] = key;
    }
}

// Function to partition the array for Quicksort
int Partition(int* array, int low, int high) {
    numPartitionCalls++;
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

// Quicksort implementation with a switch to Insertion Sort for small arrays
void Quicksort(int* array, int low, int high, int threshold) {
    numQuicksortCalls++;
    if (high - low < threshold) { // Switch to Insertion Sort for small segments
        InsertionSort(array + low, high - low + 1);
    } else if (low < high) {
        int pivotLocation = Partition(array, low, high);
        Quicksort(array, low, pivotLocation, threshold);
        Quicksort(array, pivotLocation + 1, high, threshold);
    }
}

// Function to measure and print sorting time and statistics
void MeasureSortingTime(int* sizes, int length, int threshold) {
    struct timeval begin, end;

    printf("Size     | Time (s)     | Time (micros)     | Partition Calls | Quicksort Calls | Comparisons\n");
    printf("---------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < length; i++) {
        int numElements = sizes[i];
        int* elements = (int*)malloc(sizeof(int) * numElements);

        srand(42); // Seed for reproducible results
        for (int j = 0; j < numElements; j++) {
            elements[j] = (rand() % 90) + 10; // Populate the array with random values
        }

        // Reset statistics for each array size
        numPartitionCalls = 0;
        numQuicksortCalls = 0;
        numComparisons = 0;

        gettimeofday(&begin, NULL);
        Quicksort(elements, 0, numElements - 1, threshold);
        gettimeofday(&end, NULL);

        long seconds = (end.tv_sec - begin.tv_sec);
        long micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);

        printf("%-8d | %-12ld | %-20ld | %-15d | %-15d | %-10d\n",
               numElements, seconds, micros, numPartitionCalls, numQuicksortCalls, numComparisons);

        free(elements);
    }
}

int main() {
    int dataSize[] = {16, 64, 128, 512, 1024, 2048};  // Different sizes of data for testing
    int length = sizeof(dataSize) / sizeof(dataSize[0]);
    int threshold = 128; // Threshold for switching to Insertion Sort
    MeasureSortingTime(dataSize, length, threshold);
}

