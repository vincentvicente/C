#include <stdio.h>
#include "Sort.h"
#include "LinkedList_easy.h"
#include <time.h>
#include <stdlib.h>
#include <inttypes.h>

#define NUM_RANDOM_NUMBERS 50

LinkedList GenerateRanList() {
    LinkedList list = CreateLinkedList();

    uint64_t upper_bound = 1000;
    uint64_t lower_bound = 100;
    unsigned int seed = (unsigned int)time(NULL);
    for (int i = 0; i < NUM_RANDOM_NUMBERS; i++) {
        uint64_t* value = (uint64_t*)malloc(sizeof(uint64_t));
        *value = (uint64_t)rand_r(&seed) % (upper_bound
            - lower_bound + 1) + lower_bound;

        InsertLinkedList(list, value);
    }
    return list;
}


void DestroyRanList(LinkedList list) {
    if (list == NULL)
        return;
    while (list->head != NULL) {
        LinkedListNode* nodeToRemove = list->head;
        list->head = nodeToRemove->next;
        free(nodeToRemove->payload);
        free(nodeToRemove);
    }
    free(list);
}

int main() {
    srand(time(NULL));

    LinkedList list1 = GenerateRanList();
    printf("List1 is presented as: ");
    PrintLinkedList(list1);
    SortInsertion(&list1);
    printf("\nAfter Selection Sorted list1 is modified as: ");
    PrintLinkedList(list1);
    printf("%lu\n", *(uint64_t*)(list1->tail->payload));
    printf("\n");
    DestroyRanList(list1);

    LinkedList list2 = GenerateRanList();
    printf("List2 is presented as: ");
    PrintLinkedList(list2);
    SortMerge(&list2);
    printf("\nAfter Selection Sorted list2 is modified as:  ");
    PrintLinkedList(list2);
    printf("%lu\n", *(uint64_t*)(list2->tail->payload));
    printf("\n");
    DestroyRanList(list2);

    LinkedList list3 = GenerateRanList();
    printf("List3 is presented as: ");
    PrintLinkedList(list3);
    SortMerge(&list3);
    printf("\nAfter merge sorted list3 is modified as:  ");
    PrintLinkedList(list3);
    printf("%lu\n", *(uint64_t*)(list3->tail->payload));
    DestroyRanList(list3);

    return 0;
}
