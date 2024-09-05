#ifndef COMPLEXINT_H
#define COMPLEXINT_H

// Declare the ComplexInt struct
typedef struct {
    int* data;
} ComplexInt;

// Declare the createComplexInt function
ComplexInt* createComplexInt(int value);

#endif

