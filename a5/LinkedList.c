/**
 * @author Qiyuan Zhu
 * @date 2024-02-20
 * @version 2.0
 */

#include "LinkedList_easy.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Create a new linked list node with given data
LinkedListNode* CreateLinkedListNode(char *data){
    // Allocate memory for a new node
    LinkedListNode* new_node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (new_node != NULL) {
        size_t length = strlen(data); // Calculate the length of input data
        // Allocate memory for node payload
        new_node->payload = (char*)malloc((length + 1) * sizeof(char));
        if (new_node->payload != NULL) {
            strcpy(new_node->payload, data); // Copy data to payload
        } else {
            free(new_node); // Free node if payload allocation fails
            return NULL;
        }
        new_node->next = NULL; // Set next node to NULL
        new_node->prev = NULL; // Set previous node to NULL
    }
    return new_node;
}
	
// Destroy a linked list node
int DestroyLinkedListNode(LinkedListNode *node) {
    if (node != NULL) {
        free(node->payload); // Free the payload
        free(node); // Free the node itself
        return 0;
    }
    return 1;
}

// Remove a node from the linked list
int RemoveLLElem(LinkedList list, LinkedListNodePtr ptr) {
    if (list == NULL || ptr == NULL) return 1; // Check for valid input

    if (ptr->prev != NULL) ptr->prev->next = ptr->next; // Link previous node to next node
    else list->head = ptr->next; // Update head if necessary

    if (ptr->next != NULL) ptr->next->prev = ptr->prev; // Link next node to previous node
    else list->tail = ptr->prev; // Update tail if necessary

    DestroyLinkedListNode(ptr); // Free the node
    list->num_elements--; // Decrement size of list
    return 0;
}

// Create an empty linked list
LinkedList CreateLinkedList() {
    LinkedList list = (LinkedList)malloc(sizeof(LinkedListHead));
    if (list != NULL) {
        list->num_elements = 0; // Initialize list size
        list->head = NULL; // Initialize head
        list->tail = NULL; // Initialize tail
    }
    return list;
}

// Destroy the linked list and free memory
int DestroyLinkedList(LinkedList list) {
    if (list == NULL) return 1; // Check for valid input

    LinkedListNodePtr current = list->head, next;
    while (current != NULL) {
        next = current->next; // Store next node
        DestroyLinkedListNode(current); // Destroy current node
        current = next; // Move to next node
    }
    free(list); // Free the list structure
    return 0;
}

// Insert a new node at the beginning of the linked list
int InsertLinkedList(LinkedList list, char* data) {
    if (list == NULL) return 1; // Check for valid input

    LinkedListNodePtr new_node = CreateLinkedListNode(data);
    if (new_node == NULL) return 1; // Check if node creation was successful

    if (list->head == NULL) {
        list->head = new_node; // Set as head if list is empty
        list->tail = new_node; // Also set as tail
    } else {
        list->head->prev = new_node; // Link current head to new node
        new_node->next = list->head; // Link new node to current head
        list->head = new_node; // Update head to new node
    }
    list->num_elements++; // Increment list size
    return 0;
}

// Return the number of elements in the linked list
unsigned int NumElementsInLinkedList(LinkedList list) {
    return (list != NULL) ? list->num_elements : 0;
}

// Remove and return the first element of the linked list
int PopLinkedList(LinkedList list, char** dataPtr) {
    if (list == NULL || dataPtr == NULL || list->head == NULL)
        return 1; // Check for valid input

    // Duplicate payload
    *dataPtr = strdup(list->head->payload);
    if (*dataPtr == NULL) {
        // Memory allocation failed, clean up and return error
        return 1;
    }

    LinkedListNodePtr toRemove = list->head; // Node to be removed
    if (list->head->next != NULL)
        list->head->next->prev = NULL; // Update next node's prev
    else
        list->tail = NULL; // If no next node, update tail to NULL
    list->head = list->head->next; // Update the list's head

    // Destroy the removed node
    DestroyLinkedListNode(toRemove);

    // Decrement list size
    list->num_elements--;

    return 0;
}


// Swap the payload of two linked list nodes
void SwapPayload(LinkedListNodePtr node1, LinkedListNodePtr node2) {
    char* temp = node1->payload;
    node1->payload = node2->payload;
    node2->payload = temp;
}

// Sort the linked list in ascending or descending order
void SortLinkedList(LinkedList list, unsigned int ascending) {
    if (list == NULL || list->num_elements <= 1) return; // Ignore if not enough elements to sort

    int swapped;
    do {
        swapped = 0;
        LinkedListNodePtr cur = list->head;
        while (cur != NULL && cur->next != NULL) {
            int shouldSwap = (ascending) ? strcmp(cur->payload, cur->next->payload) > 0
                                         : strcmp(cur->payload, cur->next->payload) < 0;
            if (shouldSwap) {
                SwapPayload(cur, cur->next); // Swap payloads to sort
                swapped = 1;
            }
            cur = cur->next;
        }
    } while (swapped); // Repeat until no more swaps needed
}

// Create a linked list iterator for traversing the list
LLIter CreateLLIter(LinkedList list) {
    if (list == NULL) {
        return NULL; // Return NULL for invalid list
    }
    LLIter iter = (LLIter)malloc(sizeof(LLIterSt)); // Allocate memory for the iterator
    if (iter != NULL) {
        iter->list = list; // Set the iterator's list
        iter->cur_node = list->head; // Start the iterator at the head of the list
    }
    return iter;
}

// Check if there is a next node in the list to iterate to
int LLIterHasNext(LLIter iter) {
    return iter != NULL && iter->cur_node != NULL && iter->cur_node->next != NULL;
}

// Check if there is a previous node in the list to iterate to
int LLIterHasPrev(LLIter iter) {
    return iter != NULL && iter->cur_node != NULL && iter->cur_node->prev != NULL;
}

// Move the iterator to the next node in the list
int LLIterNext(LLIter iter) {
    if (iter == NULL || iter->cur_node == NULL) {
        return 1; // Invalid iterator or already at the end
    }
    iter->cur_node = iter->cur_node->next; // Move to the next node
    return 0;
}

// Move the iterator to the previous node in the list
int LLIterPrev(LLIter iter) {
    if (iter == NULL || iter->cur_node == NULL) {
        return 1; // Invalid iterator or already at the beginning
    }
    iter->cur_node = iter->cur_node->prev; // Move to the previous node
    return 0;
}

// Destroy the iterator and free its memory
int DestroyLLIter(LLIter iter) {
    free(iter); // Free the iterator's memory
    return 0;
}

// Get the payload of the current node pointed by the iterator
int LLIterGetPayload(LLIter iter, char** payload) {
    if (iter == NULL || iter->cur_node == NULL) {
        return 1; // Invalid iterator or no current node
    }
    *payload = iter->cur_node->payload; // Set the payload to the current node's payload
    return 0;
}

// Delete the current node from the list and update the iterator to point to a valid node
int LLIterDelete(LLIter iter) {
    if (iter == NULL || iter->cur_node == NULL) {
        return 1; // Invalid iterator or no current node
    }
    LinkedListNodePtr nodeToDelete = iter->cur_node;
    // Adjust the links for the surrounding nodes
    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = nodeToDelete->next;
    } else {
        iter->list->head = nodeToDelete->next; // Update head if necessary
    }
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    } else {
        iter->list->tail = nodeToDelete->prev; // Update tail if necessary
    }
    // Update the iterator to the next node, or prev if no next exists
    iter->cur_node = (nodeToDelete->next != NULL) ? nodeToDelete->next : nodeToDelete->prev;    
    // Free the node and its payload
    free(nodeToDelete->payload);
    free(nodeToDelete);
    iter->list->num_elements--; // Update the size of the list

    return (iter->list->num_elements == 0) ? 1 : 0; // Return 1 if the list is now empty
}

// Insert a new node before the current node pointed by the iterator
int LLIterInsertBefore(LLIter iter, char* payload) {
    if (iter == NULL || iter->list == NULL) {
        return 1; // Invalid iterator or list
    }

    LinkedListNodePtr new_node = CreateLinkedListNode(payload); // Create a new node
    if (new_node == NULL) {
        return 1; // Memory allocation failure
    }
    
    if (iter->cur_node != NULL) { // If there's a current node
        // Insert new node before the current node
        new_node->prev = iter->cur_node->prev;
        new_node->next = iter->cur_node;
        if (iter->cur_node->prev != NULL) {
            iter->cur_node->prev->next = new_node;
        } else {
            iter->list->head = new_node; // Update head if necessary
        }
        iter->cur_node->prev = new_node;
    } else { // If the iterator is at the end of the list
        // Append the new node to the end
        if (iter->list->tail != NULL) {
            iter->list->tail->next = new_node;
            new_node->prev = iter->list->tail;
            iter->list->tail = new_node;
        } else {
            // If the list is empty, make the new node the head and tail
            iter->list->head = new_node;
            iter->list->tail = new_node;
        }
    }
    iter->list->num_elements++; // Update the size of the list
    return 0;
}
