#include <stdio.h>
#include "ComplexInt.h"

int main() {
    ComplexInt* test = createComplexInt(8);
    printf("The pointer is %p\n", test->data);
    return 0;
}

