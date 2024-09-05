#include "LinkedList_easy.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

LinkedListNode* CreateLinkedListNode(HTKeyValue* data) {
    // Allocate memory for a node
    LinkedListNode* node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (node == NULL) {
        return NULL;
    }

    // Set the payload
    node->payload = data;

    node->next = NULL;
    node->prev = NULL;

    return node;
}

int DestroyLinkedListNode(LinkedListNode *node) {
    if (node == NULL) {
        return -1;  // Error: NULL ptr
    }

    free(node->payload->key);
    free(node->payload->value);
    free(node->payload);
    free(node);

    return 0;
}

int RemoveLLElem(LinkedList list, LinkedListNodePtr ptr) {
    if (list == NULL || ptr == NULL) {
        return -1;
    }

    if (list->num_elements == 1) {
        if (ptr == list->head) {
            if (DestroyLinkedListNode(ptr) == -1) {
                return 1;  // Error: Failed to destroy node
            }

            list->head = NULL;
            list->tail = NULL;
            list->num_elements = 0;

            return 0;
        } else {
            return 1;
        }
    }

    // If ptr is the head
    if (ptr == list->head) {
        list->head = ptr->next;

        if (DestroyLinkedListNode(ptr) == -1) {
                return 1;  // Error: Failed to destroy node
        }

        list->num_elements--;

        return 0;
    }

    // If ptr is the tail
    if (ptr == list->tail) {
        list->tail = ptr->prev;

        if (DestroyLinkedListNode(ptr) == -1) {
                return 1;  // Error: Failed to destroy node
        }

        list->num_elements--;

        return 0;
    }

    for (LinkedListNodePtr curr = list->head; curr != NULL; curr = curr->next) {
        if (curr == ptr) {
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;

            if (DestroyLinkedListNode(ptr) == -1) {
                return 1;  // Error: Failed to destroy node
            }

            list->num_elements--;

            return 0;
        }
    }

    return 1;
}

LinkedList CreateLinkedList() {
    LinkedList list = (LinkedList)malloc(sizeof(LinkedListHead));
    list->num_elements = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int DestroyLinkedList(LinkedList list) {
    LinkedListNodePtr curr = list->head;
    LinkedListNodePtr next;

    while (curr != NULL) {
        next = curr->next;
        if (DestroyLinkedListNode(curr) == -1) {
            return -1;
        }

        curr = next;
    }

    free(list);

    return 0;
}

unsigned int NumElementsInLinkedList(LinkedList list) {
    if (list == NULL) {
        return -1;  // Error: NULL list
    }

    return list->num_elements;
}

int InsertLinkedList(LinkedList list, HTKeyValue* data) {
    if (list == NULL) {
        return -1;
    }

    LinkedListNode* node = CreateLinkedListNode(data);
    if (node == NULL) {
        return -1;
    }

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }

    list->num_elements++;

    return 0;
}

LLIter CreateLLIter(LinkedList list) {
    if (list == NULL) {
        return NULL;
    }

    LLIter iter = (LLIter)malloc(sizeof(LLIter));

    iter->list = list;
    iter->cur_node = list->head;

    return iter;
}

int LLIterHasNext(LLIter iter) {
    if (iter == NULL) {
        return -1;
    }

    if (iter->cur_node == NULL) {
        return 0;
    }

    return 1;
}

int LLIterHasPrev(LLIter iter) {
    if (iter == NULL) {
        return -1;
    }

    if (iter->cur_node == NULL || iter->cur_node->prev == NULL) {
        return 0;
    }

    return 1;
}

int LLIterNext(LLIter iter) {
    if (iter == NULL || LLIterHasNext(iter) == 0) {
        return -1;
    }

    iter->cur_node = iter->cur_node->next;

    return 0;
}

int LLIterPrev(LLIter iter) {
    if (iter == NULL || LLIterHasPrev(iter) == 0) {
        return -1;
    }

    iter->cur_node = iter->cur_node->prev;

    return 0;
}

int DestroyLLIter(LLIter iter) {
    if (iter == NULL) {
        return 0;
    }

    free(iter);

    return 0;
}

int LLIterGetPayload(LLIter iter, HTKeyValue** payload) {
    if (iter == NULL || iter->cur_node == NULL) {
        return 1;
    }

    *payload = iter->cur_node->payload;

    return 0;
}

int LLIterDelete(LLIter iter) {
    if (iter == NULL || iter->cur_node == NULL) {
        return -1;
    }

    // Only one node left
    if (iter->list->num_elements == 1) {
        if (DestroyLinkedListNode(iter->cur_node) == -1) {
            return -1;
        }

        iter->list->num_elements--;
        iter->list->head = NULL;
        iter->list->tail = NULL;
        iter->cur_node = NULL;

        DestroyLLIter(iter);

        return 0;
    }

    // The iterator is pointing to the tail
    if (iter->cur_node == iter->list->tail) {
        LinkedListNode* prev_node = iter->cur_node->prev;
        if (DestroyLinkedListNode(iter->cur_node) == -1) {
            return -1;
        }

        iter->cur_node = prev_node;
        iter->cur_node->next = NULL;
        iter->list->tail = prev_node;

        return 0;
    }

    // Normal situation
    LinkedListNode *prev_node = iter->cur_node->prev;
    LinkedListNode *next_node = iter->cur_node->next;

    if (DestroyLinkedListNode(iter->cur_node) == -1) {
        return -1;
    }

    iter->cur_node = next_node;
    prev_node->next = next_node;
    next_node->prev = prev_node;

    return 0;
}
