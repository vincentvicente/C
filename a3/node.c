#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// Implementation of the createNode function
L_Node* createNode(int value) {
    L_Node* node = (L_Node*)malloc(sizeof(L_Node)); // Dynamically allocate memory for a new node
    if (node == NULL) { // Check if memory allocation was successful
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    node->value = value; // Set the node's value
    node->next = NULL; // Initially, the node does not point to any next node
    node->prev = NULL; // Initially, the node does not point to any previous node
    return node; // Return the newly created node
}

