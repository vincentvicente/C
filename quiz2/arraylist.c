#include<stdio.h>
#include<stdlib.h>
#include"arraylist.h"

/**
 * Retrieves the value at the specified index in the ArrayList.
 *
 * @param list Pointer to the ArrayList
 * @param index Index of the element to retrieve
 * @return Value at the specified index, or NULL if index is out of bounds
 */
char* get(ArrayList* list, int index) {
    // Check if the index is within the bounds of the array
    if (index >= 0 && index < list->size) {
        // Return the element at the specified index
        return list->nodes[index]->value;
    }
    // If the index is out of bounds, return NULL
    return NULL;
}

/**
 * Removes the element at the specified index from the ArrayList.
 *
 * @param list Pointer to the ArrayList
 * @param index Index of the element to remove
 */
void removeAt(ArrayList* list, int index) {
    // Check if the index is valid
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        return;
    }
    // Free the element at the specified index
    free(list->nodes[index]);

    // Shift elements to the left to fill the gap
    for (int i = index; i < list->size - 1; i++) {
        list->nodes[i] = list->nodes[i + 1];
    }

    // Nullify the last element's pointer to maintain a clean state
    list->nodes[list->size - 1] = NULL;

    // Update the size of the ArrayList
    list->size--;
}


/**
 * Creates a new ArrayList with the specified initial size.
 *
 * @param size Initial size of the ArrayList
 * @return Pointer to the newly created ArrayList
 */
ArrayList* create(int size) {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    Node** nodes = (Node**)malloc(sizeof(Node*) * size);
    list->nodes = nodes;
    list->size = 0;
    return list;
}

/**
 * Adds a new element with the specified value to the end of the ArrayList.
 *
 * @param list Pointer to the ArrayList
 * @param value Value to add to the ArrayList
 * @return Pointer to the ArrayList after adding the element
 */
ArrayList* add(ArrayList* list, int value) {
    // First, check if the nodes array needs to be expanded
    if (list->size >= list->capacity) {
        int newCapacity = list->capacity == 0 ? 1 : list->capacity * 2; // Initialize to 1 if capacity is 0, otherwise double it
        Node** newNodes = (Node**)realloc(list->nodes, newCapacity * sizeof(Node*));
        if (newNodes == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        list->nodes = newNodes;
        list->capacity = newCapacity;
    }

    // Create a new Node and assign the value
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the string representation of value
    char* valueAsString = (char*)malloc(12 * sizeof(char)); // Assuming a 32-bit int, 11 characters + null terminator
    if (valueAsString == NULL) {
        fprintf(stderr, "Memory allocation for string representation failed\n");
        exit(EXIT_FAILURE);
    }

    sprintf(valueAsString, "%d", value); // Convert the integer to a string
    newNode->value = valueAsString; // Assign the string to the node

    // Add the new node to the end of the array
    list->nodes[list->size] = newNode;
    list->size++;

    return list;
}


/**
 * Destroys the ArrayList and frees up memory.
 *
 * @param list Pointer to the ArrayList to be destroyed
 */
void destroyList(ArrayList* list) {
    int i;
    for(i=0; i<list->size; i++) {
        destroyNode(list->nodes[i]);
    }
    free(list->nodes);
    free(list);
}

/**
 * Destroys a single node and frees up memory.
 *
 * @param node Pointer to the node to be destroyed
 */
void destroyNode(Node* node) {
    free(node);
    return;
}

/**
 * Returns the current size of the ArrayList.
 *
 * @param list Pointer to the ArrayList
 * @return Current size of the ArrayList
 */
int size(ArrayList* list) {
    return list->size;
}
