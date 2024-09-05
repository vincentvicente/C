#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// Define the structure of a linked list node
typedef struct L_List {
    L_Node* head;
    int size;
} L_List;

// Create a new linked list
L_List* createList() {
    L_List* newList = (L_List*)malloc(sizeof(L_List));
    if (newList == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

// Add a node to the linked list
void addNode(L_List* list, int value) {
    L_Node* newNode = createNode(value);
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

// Remove a node at the specified index
void removeNodeAt(L_List* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of the range of the list!\n");
        return;
    }

    L_Node* current = list->head;
    if (index == 0) {
        list->head = current->next;
        free(current);
        list->size--;
        return;
    }

    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    L_Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    list->size--;
}

// Remove all nodes with a specified value
void removeAllNodesWithValue(L_List* list, int value) {
    L_Node* current = list->head;
    L_Node* prev = NULL;

    while (current != NULL) {
        if (current->value == value) {
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            list->size--;
        } else {
            prev = current;
        }
        current = current->next;
    }
}

// Free all memory used by the linked list
void freeAllMemory(L_List* list) {
    L_Node* current = list->head;
    L_Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    free(list);
}

// Print the elements of the linked list
void printList(L_List* list) {
    L_Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    L_Node* n1 = createNode(1);
    printf("The first value is %d\n", n1->value);

    L_List* myList = createList();

    // Add nodes to the linked list
    addNode(myList, 5);
    addNode(myList, 10);
    addNode(myList, 15);

    // Print the size of the linked list
    printf("Size of the linked list: %d\n", myList->size);

    // Remove a node at index 1
    removeNodeAt(myList, 1);
    printf("Linked list after removing node at index 1: Size=%d\n", myList->size);

    // Remove all nodes with value 5
    removeAllNodesWithValue(myList, 5);
    printf("Linked list after removing all nodes with value 5: Size=%d\n", myList->size);

    // Print the elements of the linked list
    printf("Linked list elements: ");
    printList(myList);

    // Free the memory used by the linked list
    freeAllMemory(myList);

    return 0;
}

