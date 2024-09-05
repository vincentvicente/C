#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h" // Assuming this header defines the structure for a doubly linked list node (L_Node) and the createNode function.

typedef struct Deque {
    L_Node* head; // Dummy head node for easier operations.
    int size;     // Tracks the number of elements in the deque.
} Deque;

// Function prototypes for operations on the deque.
void addLeft(Deque* deque, int value);
void addRight(Deque* deque, int value);
void addEmpty(Deque* deque, int value); // Helper function to handle adding to an empty deque.
void removeLeft(Deque* deque);
void removeRight(Deque* deque);
void insertAt(Deque* deque, int index, int value);
void removeAt(Deque* deque, int index);
bool isEmpty(Deque* deque);
int getValueAt(Deque* deque, int index);
void printList(Deque* deque);
void freeAllMemory(Deque* deque);
int peekLeft(Deque* deque);
int peekRight(Deque* deque);
int popLeft(Deque* deque);
int popRight(Deque* deque);
bool hasValue(Deque* deque, int value);
void pushRight(Deque* list, int value);
void pushLeft(Deque* list, int value);

Deque* createList(int i) {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    if (deque == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    deque->head = createNode(i); // Dummy node initialization
    deque->size = 0;
    return deque;
}

void addLeft(Deque* deque, int value) {
    if (isEmpty(deque)) {
        addEmpty(deque, value);
    } else {
        L_Node* newNode = createNode(value);
        L_Node* oldLeft = deque->head->next;
        deque->head->next = newNode;
        newNode->next = oldLeft;
        newNode->prev = deque->head;
        if (oldLeft != NULL) { // Check if the deque was not empty
            oldLeft->prev = newNode;
        }
        deque->size++;
    }
}

void addRight(Deque* deque, int value) {
    if (isEmpty(deque)) {
        addEmpty(deque, value);
    } else {
        L_Node* newNode = createNode(value);
        L_Node* oldRight = deque->head->prev;
        deque->head->prev = newNode;
        newNode->prev = oldRight;
        newNode->next = deque->head;
        if (oldRight != NULL) { // Check if the deque was not empty
            oldRight->next = newNode;
        }
        deque->size++;
    }
}

void addEmpty(Deque* deque, int value) {
    L_Node* newNode = createNode(value);
    deque->head->next = newNode;
    deque->head->prev = newNode;
    newNode->next = deque->head;
    newNode->prev = deque->head;
    deque->size = 1;
}

bool isEmpty(Deque* deque) {
    return deque->size == 0;
}

void removeLeft(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }
    L_Node* toRemove = deque->head->next;
    if (toRemove->next != deque->head) { // If there's more than one node
        deque->head->next = toRemove->next;
        toRemove->next->prev = deque->head;
    } else { // Only one node was in the deque
        deque->head->next = NULL;
        deque->head->prev = NULL;
    }
    free(toRemove);
    deque->size--;
}

void removeRight(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }
    L_Node* toRemove = deque->head->prev;
    if (toRemove->prev != deque->head) { // If there's more than one node
        deque->head->prev = toRemove->prev;
        toRemove->prev->next = deque->head;
    } else { // Only one node was in the deque
        deque->head->next = NULL;
        deque->head->prev = NULL;
    }
    free(toRemove);
    deque->size--;
}

int peekLeft(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        exit(EXIT_FAILURE); // Exiting program as there is no value to return
    }
    return deque->head->next->value;
}

int peekRight(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        exit(EXIT_FAILURE); // Exiting program as there is no value to return
    }
    return deque->head->prev->value;
}

int popLeft(Deque* deque) {
    int value = peekLeft(deque); // Fetch the value before removing
    removeLeft(deque); // Remove the node
    return value; // Return the fetched value
}

int popRight(Deque* deque) {
    int value = peekRight(deque); // Fetch the value before removing
    removeRight(deque); // Remove the node
    return value; // Return the fetched value
}

// Adds a value to the left end of the deque.
void pushLeft(Deque* list, int value) {
    addLeft(list, value);
}

// Adds a value to the right end of the deque.
void pushRight(Deque* list, int value) {
    addRight(list, value);
}   


bool hasValue(Deque* deque, int value) {
    L_Node* current = deque->head->next;
    while (current != deque->head) { // Traverse until dummy node is reached again
        if (current->value == value) {
            return true; // Value found
        }
        current = current->next;
    }
    return false; // Value not found
}

void printList(Deque* deque) {
    L_Node* current = deque->head->next;
    printf("Deque: ");
    while (current != deque->head) { // Traverse until dummy node is reached again
        if (current != NULL) {
            printf("%d ", current->value);
            current = current->next;
        } else {
            printf("Error: current is NULL\n");
            break;
        }
    }
    printf("\n");
}

void freeAllMemory(Deque* deque) {
    L_Node* current = deque->head->next;
    while (current != deque->head) { // Traverse and free nodes until dummy node is reached again
        L_Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(deque->head); // Free the dummy node
    free(deque); // Free the deque structure itself
}

int main() {
    Deque* myDeque = createList(0);

    printf("Initial Deque (empty):\n");
    printList(myDeque);

    pushLeft(myDeque, 1);
    pushRight(myDeque, 2);
    printf("After pushing 1 left and 2 right:\n");
    printList(myDeque);

    pushLeft(myDeque, 3);
    pushRight(myDeque, 4);
    printf("After pushing 3 left and 4 right:\n");
    printList(myDeque);

    printf("Peek Left: %d\n", peekLeft(myDeque));
    printf("Peek Right: %d\n", peekRight(myDeque));

    printf("Pop Left: %d\n", popLeft(myDeque));
    printf("After popping from left:\n");
    printList(myDeque);

    printf("Pop Right: %d\n", popRight(myDeque));
    printf("After popping from right:\n");
    printList(myDeque);

    if (hasValue(myDeque, 2)) {
        printf("Deque has value 2.\n");
    } else {
        printf("Deque does not have value 2.\n");
    }

    freeAllMemory(myDeque);

    return 0;
}

