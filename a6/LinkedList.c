#include "LinkedList_easy.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedListNode* CreateLinkedListNode(uint64_t* data) {
    LinkedListNode* node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (node != NULL) {
        node->payload = data;
        node->next = NULL;
        node->prev = NULL;
    }
    return node;
}

int DestroyLinkedListNode(LinkedListNode* node) {
    if (node == NULL)
        return 1;
    free(node);
    return 0; 
}

int RemoveLLElem(LinkedList list, LinkedListNodePtr ptr) {
    if (list == NULL || ptr == NULL || list->head == NULL)
        return 1;
    if (ptr == list->head) {
        list->head = ptr->next;
        if (list->head != NULL)
            list->head->prev = NULL;
        else
            list->tail = NULL;
    } else if (ptr == list->tail) {
        list->tail = ptr->prev;
        if (list->tail != NULL)
            list->tail->next = NULL;
    } else {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
    DestroyLinkedListNode(ptr);
    list->num_elements--;
    return 0;
}

LinkedList CreateLinkedList() {
    LinkedList list = (LinkedList)malloc(sizeof(LinkedListHead));
    if (list != NULL) {
        list->num_elements = 0;
        list->head = NULL;
        list->tail = NULL;
    }
    return list;
}

int DestroyLinkedList(LinkedList list) {
    if (list == NULL)
        return 1;
    while (list->head != NULL) {
        LinkedListNode* nodeToRemove = list->head;
        list->head = nodeToRemove->next;
        DestroyLinkedListNode(nodeToRemove);
    }
    free(list);
    return 0;
}

unsigned int NumElementsInLinkedList(LinkedList list) {
    if (list != NULL)
        return list->num_elements;
    return 0;
}

int InsertLinkedList(LinkedList list, uint64_t* data) {
    if (list == NULL || data == NULL)
        return 1;
    LinkedListNode* node = CreateLinkedListNode(data);
    if (node == NULL)
        return 1;

    if (list->head != NULL) {
        list->head->prev = node;
        node->next = list->head;
    } else {
        list->tail = node;
    }

    list->head = node;
    list->num_elements++;
    return 0;
}

int PopLinkedList(LinkedList list, uint64_t** dataPtr) {
    if (list == NULL || list->head == NULL || dataPtr == NULL)
        return 1;
    *dataPtr = list->head->payload;
    if (*dataPtr == NULL)
        return 1;
    RemoveLLElem(list, list->head);
    return 0;
}

void swap(uint64_t *arr[], int i, int j) {
    uint64_t* temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

int partitionInAsc(uint64_t* arr[], int low, int high) {
    uint64_t* pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (*arr[j] < *pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return (i + 1);
}

int partitionInDesc(uint64_t * arr[], int low, int high) {
    uint64_t * pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (*arr[j] > *pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return (i + 1);
}

void quickSort(uint64_t **arr, int low, int high, int ascending) {
    if (low < high) {
        int pivot;
        if (ascending)
            pivot = partitionInAsc(arr, low, high);
        else
            pivot = partitionInDesc(arr, low, high);
        quickSort(arr, low, pivot - 1, ascending);
        quickSort(arr, pivot + 1, high, ascending);
    }
}

void SortLinkedList(LinkedList list, unsigned int ascending) {
    if (list == NULL || list->head == NULL || list->head->next == NULL)
        return;
    int n = list->num_elements;
    uint64_t **arr = (uint64_t **)malloc(n * sizeof(uint64_t *));
    LinkedListNode* curr = list->head;
    for (int i = 0; i < n; i++) {
        arr[i] = curr->payload;
        curr = curr->next;
    }
    quickSort(arr, 0, n - 1, ascending);

    curr = list->head;
    for (int i = 0; i < n; i++) {
        curr->payload = arr[i];
        curr = curr->next;
    }
    free(arr);
}

LLIter CreateLLIter(LinkedList list) {
    if (list == NULL)
        return NULL;
    LLIter iterator = (LLIter)malloc(sizeof(LLIterSt));
    if (iterator != NULL) {
        iterator->list = list;
        iterator->cur_node = list->head;
    }
    return iterator;
}

int LLIterHasNext(LLIter iter) {
    if (iter->cur_node == NULL || iter->cur_node->next == NULL)
        return 0;
    return 1;
}

int LLIterHasPrev(LLIter iter) {
    if (iter->cur_node == NULL || iter->cur_node->prev == NULL)
        return 0;
    return 1;
}

int LLIterNext(LLIter iter) {
    if (iter != NULL && LLIterHasNext(iter)) {
        if (iter->cur_node->next != NULL) {
            iter->cur_node = iter->cur_node->next;
            return 0;
        } else {
            iter->cur_node = NULL;
            return 1;
        }
    }
    return 1;
}

int LLIterPrev(LLIter iter) {
    if (iter != NULL && LLIterHasPrev(iter)) {
        if (iter->cur_node->prev != NULL) {
            iter->cur_node = iter->cur_node->prev;
            return 0;  
        } else {
            iter->cur_node = NULL;
            return 1;
        }
    }
    return 1;
}


int LLIterGetPayload(LLIter iter, uint64_t** payload) {
    if (iter != NULL && iter->cur_node != NULL) {
        *payload = iter->cur_node->payload;
        return 0;
    }
    return 1;
}

int LLIterDelete(LLIter iter) {
    if (iter == NULL || iter->list == NULL || iter->cur_node == NULL) return 1;
    LinkedList list = iter->list;
    LinkedListNodePtr nodeToRemove = iter->cur_node;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
        DestroyLLIter(iter);
        return 1;  
    }

    if (nodeToRemove == list->head) {
        list->head = nodeToRemove->next;
        if (list->head != NULL) list->head->prev = NULL;
    } else if (nodeToRemove == list->tail) { 
        list->tail = nodeToRemove->prev;
        if (list->tail != NULL) list->tail->next = NULL;
    } else {  
        LinkedListNodePtr prev = nodeToRemove->prev;
        LinkedListNodePtr next = nodeToRemove->next;
        prev->next = next;
        next->prev = prev;
    }
    iter->cur_node = nodeToRemove->next; 
    DestroyLinkedListNode(nodeToRemove); 
    list->num_elements--;

    if (list->head == NULL) {
        free(list);
    }
    return 0;
}


int LLIterInsertBefore(LLIter iter, uint64_t* payload) {
    if (!iter || !iter->list || !iter->cur_node || !payload) return 1;
    LinkedList list = iter->list;
    LinkedListNodePtr curr = iter->cur_node;

    LinkedListNodePtr newNode = CreateLinkedListNode(payload);
    if (!newNode) return 1; 

    newNode->next = curr;
    newNode->prev = curr->prev;
    curr->prev = newNode;

    if (newNode->prev != NULL) {
        newNode->prev->next = newNode;
    } else {
        list->head = newNode; 
    }
    list->num_elements++;
    return 0;
}


int DestroyLLIter(LLIter iter) {
    if (iter == NULL) return 1; 
    if (iter->list != NULL) DestroyLinkedList(iter->list);
    free(iter);
    return 0;
}
