#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"

// Doubly-Linked List structure
typedef struct DL_List {
    L_Node* head; // Pointer to the first node of the list
    L_Node* tail; // Pointer to the last node of the list
    int size; // Number of nodes in the list
} DL_List;

// Create a new Doubly-Linked List
DL_List* createList() {
    DL_List* newList = (DL_List*)malloc(sizeof(DL_List));
    if (newList == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newList->head = newList->tail = NULL; // Initialize head and tail as NULL
    newList->size = 0; // Initialize size of list as 0
    return newList;
}

// Add a node to the left end of the list
void addLeft(DL_List* list, int value) {
    L_Node* newNode = createNode(value);
    if (list->size == 0) {
        list->tail = newNode; // If list is empty, new node is both head and tail
    } else {
        list->head->prev = newNode; // Set new node as previous of current head
    }
    newNode->next = list->head; // New node's next is current head
    list->head = newNode; // Update head to new node
    list->size++; // Increment list size
}

// Add a node to the right end of the list
void addRight(DL_List* list, int value) {
    L_Node* newNode = createNode(value);
    if (list->head == NULL) {
        addLeft(list, value); // If list is empty, add node to the left
    } else {
        list->tail->next = newNode; // Set new node as next of current tail
        newNode->prev = list->tail; // Set current tail as previous of new node
        list->tail = newNode; // Update tail to new node
        list->size++; // Increment list size
    }
}

// Remove the leftmost node from the list
void removeLeft(DL_List* list) {
    if (list->head == NULL) {
        printf("You cannot remove from an empty list.\n");
        return;
    }
    L_Node* tmp = list->head; // Temporary pointer to current head
    list->head = list->head->next; // Update head to next node
    if (list->head == NULL) {
        list->tail = NULL; // If list becomes empty, update tail to NULL
    } else {
        list->head->prev = NULL; // Set new head's previous to NULL
    }
    free(tmp); // Free memory of removed node
    list->size--; // Decrement list size
}

// Remove the rightmost node from the list
void removeRight(DL_List* list) {
    if (list->head == NULL) {
        printf("You cannot remove from an empty list.\n");
        return;
    }
    L_Node* tmp = list->tail; // Temporary pointer to current tail
    list->tail = list->tail->prev; // Update tail to previous node
    if (list->tail == NULL) {
        list->head = NULL; // If list becomes empty, update head to NULL
    } else {
        list->tail->next = NULL; // Set new tail's next to NULL
    }
    free(tmp); // Free memory of removed node
    list->size--; // Decrement list size
}

// Function to insert a node at a specific index in the list
void insertAt(DL_List* list, int index, int value) {
    if (index < 0 || index > list->size) { // Check for valid index
        printf("Invalid index!\n");
        return;
    }

    if (index == 0) { // Special case: insert at the beginning
        addLeft(list, value);
        return;
    } else if (index == list->size) { // Special case: insert at the end
        addRight(list, value);
        return;
    }

    // Find the position where to insert the new node
    L_Node* current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    // Create the new node and link it into the list
    L_Node* newNode = createNode(value);
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    list->size++; // Increase the list size
}

// Function to remove a node at a specific index in the list
void removeAt(DL_List* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of the bound of this list!\n");
        return;
    }
    if (index == 0) {
        removeLeft(list);
        return;
    }
    if (index == list->size - 1) {
        removeRight(list);
        return;
    }
    L_Node* cur = list->head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    cur->prev->next = cur->next;
    if (cur->next != NULL) {
        cur->next->prev = cur->prev;
    }
    free(cur);
    list->size--;
}

// Function to check if a certain value is in the list
bool hasValue(DL_List* list, int value) {
    L_Node* cur = list->head;
    while (cur != NULL) {
        if (cur->value == value) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

// Function to free all allocated memory
void freeAllMemory(DL_List* list) {
    L_Node* cur = list->head;
    while (cur != NULL) {
        L_Node* next = cur->next;
        free(cur);
        cur = next;
    }
    free(list);
}

// Function to print the list
void printList(DL_List* list) {
    L_Node* cur = list->head;
    while (cur != NULL) {
        printf("%d -> ", cur->value);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a new doubly linked list
    DL_List* myList = createList();

    // Demonstrate adding nodes to the list
    addLeft(myList, 1);  // List: 1
    addRight(myList, 2); // List: 1 -> 2
    addRight(myList, 3); // List: 1 -> 2 -> 3
    addLeft(myList, 0);  // List: 0 -> 1 -> 2 -> 3
    printf("Initial List: ");
    printList(myList);

    // Inserting a node at a specific index
    insertAt(myList, 2, 99); // List: 0 -> 1 -> 99 -> 2 -> 3
    printf("After inserting 99 at index 2: ");
    printList(myList);

    // Removing a node from a specific index
    removeAt(myList, 3); // List: 0 -> 1 -> 99 -> 3
    printf("After removing node at index 3: ");
    printList(myList);

    // Checking if a value exists in the list
    if (hasValue(myList, 99)) {
        printf("List contains the value 99\n");
    } else {
        printf("List does not contain the value 99\n");
    }

    // Free all memory used by the list
    freeAllMemory(myList);

    return 0;
}

