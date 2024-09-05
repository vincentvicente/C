#include<stdio.h>
#include"arraylist.h"

int main() {
    printf("hello world\n");
    ArrayList* list = create(10);
    printf("the size of the list is %d\n", list->size);

    destroyList(list);
}
