/**
 * @author Qiyuan Zhu
 * @date 2024-02-11
 * @version 1.0
 */

#include "LinkedList_easy.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creates a new linked list node with given data
LinkedListNode* CreateLinkedListNode(char *data) {
    LinkedListNode* new_node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (new_node) {
        new_node->payload = strdup(data);
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    return new_node;
}

// Frees the memory of a linked list node
int DestroyLinkedListNode(LinkedListNode* node) {
    if (node) {
        free(node->payload);
        free(node);
        return 0;
    }
    return 1;
}

// Removes a given node from the linked list
int RemoveLLElem(LinkedList list, LinkedListNode* ptr) {
    if (!list || !ptr) return 1;
    if (ptr->prev)
        ptr->prev->next = ptr->next;
    else
        list->head = ptr->next;
    if
        (ptr->next) ptr->next->prev = ptr->prev;
    else
        list->tail = ptr->prev;
    DestroyLinkedListNode(ptr);
    list->num_elements--;
    return 0;
}

// Initializes a new empty linked list
LinkedList CreateLinkedList() {
    LinkedList list = (LinkedList)malloc(sizeof(LinkedListHead));
    list->num_elements = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Destroys the linked list and frees all nodes
int DestroyLinkedList(LinkedList list) {
    if (list) {
        LinkedListNode* current = list->head;
        while (current) {
            LinkedListNode* next = current->next;
            DestroyLinkedListNode(current);
            current = next;
        }
        free(list);
        return 0;
    }
    return 1;
}

// Returns the number of elements in the linked list
unsigned int NumElementsInLinkedList(LinkedList list) {
    return list ? list->num_elements : 0;
}

// Inserts a new element at the beginning of the linked list
int InsertLinkedList(LinkedList list, char* data) {
    if (!list) return 1;
    LinkedListNode* new_node = CreateLinkedListNode(data);
    if (!new_node) return 1;
    if (list->head) {
        list->head->prev = new_node;
        new_node->next = list->head;
        list->head = new_node;
    } else {
        list->head = list->tail = new_node;
    }
    list->num_elements++;
    return 0;
}

// Pops the first element from the linked list and returns its data
int PopLinkedList(LinkedList list, char** dataPtr) {
    if (!list || !list->head || !dataPtr) return 1;
    *dataPtr = list->head->payload;
    LinkedListNode* to_pop = list->head;
    if (list->head->next) {
        list->head = list->head->next;
        list->head->prev = NULL;
    } else {
        list->head = list->tail = NULL;
    }
    free(to_pop);
    list->num_elements--;
    return 0;
}

// Sorts the linked list based on the 'ascending' parameter
// in ascending or descending order
void SortLinkedList(LinkedList list, unsigned int ascending) {
    if (!list || list->num_elements < 2) return;
    int swapped;
    do {
        swapped = 0;
        LinkedListNode* current = list->head;
        while (current->next != NULL) {
            if ((ascending &&
                strcmp(current->payload, current->next->payload) > 0) ||
               (!ascending &&
                strcmp(current->payload, current->next->payload) < 0)) {
                char* temp = current->payload;
                current->payload = current->next->payload;
                current->next->payload = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

// Creates and returns a new iterator for the linked list
LLIter CreateLLIter(LinkedList list) {
    LLIter iter = (LLIter)malloc(sizeof(LLIterSt));
    if (iter) {
        iter->list = list;
        iter->cur_node = list->head;
    }
    return iter;
}

// Returns 1 if the iterator has a next element, 0 otherwise
int LLIterHasNext(LLIter iter) {
    if (iter && iter->cur_node && iter->cur_node->next) return 1;
    return 0;
}

// Returns 1 if the iterator has a previous element, 0 otherwise
int LLIterHasPrev(LLIter iter) {
    if (iter && iter->cur_node && iter->cur_node->prev) return 1;
    return 0;
}

// Moves the iterator to the next element
// and returns 0 if successful, 1 otherwise
int LLIterNext(LLIter iter) {
    if (LLIterHasNext(iter)) {
        iter->cur_node = iter->cur_node->next;
        return 0;
    }
    return 1;
}

// Moves the iterator to the previous element
// and returns 0 if successful, 1 otherwise
int LLIterPrev(LLIter iter) {
    if (LLIterHasPrev(iter)) {
        iter->cur_node = iter->cur_node->prev;
        return 0;
    }
    return 1;
}

// Destroys the iterator and frees its resources
int DestroyLLIter(LLIter iter) {
    if (iter) {
        free(iter);
        return 0;
    }
    return 1;
}

// Gets the payload of the current node the iterator points to
int LLIterGetPayload(LLIter iter, char** payload) {
    if (iter && iter->cur_node && payload) {
        *payload = iter->cur_node->payload;
        return 0;
    }
    return 1;
}

// Deletes the current node from the list that the iterator points to
int LLIterDelete(LLIter iter) {
    if (!iter || !iter->cur_node) return 1;
    LinkedListNode* to_delete = iter->cur_node;
    if (to_delete->prev) to_delete->prev->next = to_delete->next;
    else
        iter->list->head = to_delete->next;
    if (to_delete->next) to_delete->next->prev = to_delete->prev;
    else
        iter->list->tail = to_delete->prev;
    if (to_delete->next) iter->cur_node = to_delete->next;
    else
        iter->cur_node = to_delete->prev;
    DestroyLinkedListNode(to_delete);
    iter->list->num_elements--;
    return 0;
}

// Inserts a new node with the given payload
// before the current node the iterator points to
int LLIterInsertBefore(LLIter iter, char* payload) {
    if (!iter || !iter->list) return 1;
    LinkedListNode* new_node = CreateLinkedListNode(payload);
    if (!new_node) return 1;
    if (!iter->cur_node) {  // If iterator is at the end or list is empty
        if (iter->list->head == NULL) {  // List is empty
            iter->list->head = iter->list->tail = new_node;
        } else {  // Iterator is at the end
            new_node->prev = iter->list->tail;
            iter->list->tail->next = new_node;
            iter->list->tail = new_node;
        }
    } else {
        new_node->next = iter->cur_node;
        new_node->prev = iter->cur_node->prev;
        if (iter->cur_node->prev) iter->cur_node->prev->next = new_node;
        else
            iter->list->head = new_node;
        iter->cur_node->prev = new_node;
    }
    iter->list->num_elements++;
    return 0;
}

