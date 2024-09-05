/*
 * Author: Qiyuan Zhu
 * Date: 03/10/2024
 * Version: 2.0
 *
 */

#include <stdio.h>
#include "LinkedList_easy.h"
#include <stdlib.h>

// Implements insertion sort on the linked list
void SortInsertion(LinkedList* list) {
    if (list == NULL || (*list) == NULL || (*list)->head == NULL) {
        return; // Exit if list is null or empty
    }

    LinkedListNode* sorted = NULL;  // Starts with an empty sorted list
    LinkedListNode* current = (*list)->head; // Current node to insert

    while (current != NULL) {
        LinkedListNode* next = current->next; // Store next node for later
        // If sorted list is empty or current node value is less than sorted's first node
        if (sorted == NULL || *(sorted->payload) >= *(current->payload)) {
            current->next = sorted; // Place current at the beginning of sorted list
            if (sorted != NULL) {
                sorted->prev = current;
            }
            sorted = current;
            sorted->prev = NULL;
        } else {
            // Find the correct position and insert
            LinkedListNode* temp = sorted;
            while (temp->next != NULL && *(temp->next->payload) < *(current->payload)) {
                temp = temp->next;
            }
            current->next = temp->next; // Link the next of current to the next of temp
            if (temp->next != NULL) {
                temp->next->prev = current; // Set previous of temp's next
            }
            temp->next = current;
            current->prev = temp;
        }
        current = next; // Move to the next node
    }

    // Set the new head and tail of the list
    (*list)->head = sorted;
    // Traverse to find the new tail
    LinkedListNode* tail = sorted;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    (*list)->tail = tail;
}

// Swaps two payloads in the linked list
void swapPayloads(uint64_t *x, uint64_t *y) {
    uint64_t temp = *x;
    *x = *y;
    *y = temp;
}

// Implements selection sort on the linked list
void SortSelection(LinkedList* list) {
    LinkedList l = *list;
    if (l == NULL || l->head == NULL || l->head->next == NULL) {
        return; // Exit if list is null, empty, or has a single element
    }
    LinkedListNode* current = l->head;

    while (current != NULL) {
        // Find minimum element in unsorted section
        LinkedListNode* min = current;
        LinkedListNode* j = current->next;
        while (j != NULL) {
            if (*(j->payload) < *(min->payload)) {
                min = j;
            }
            j = j->next;
        }
        // Swap payloads of current node with min
        swapPayloads(current->payload, min->payload);
        current = current->next;
    }
    // No need to update tail as selection sort doesn't change node positions
}

// Finds the middle node of the list for merge sort
LinkedListNode* FindMiddle(LinkedListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head; // Single node or empty list
    }
    LinkedListNode* slow = head;
    LinkedListNode* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // Middle node
}

// Merges two sorted lists into a single sorted list
LinkedListNode* merge(LinkedListNode* left, LinkedListNode* right) {
    LinkedListNode dummy; // Temporary starter node for merged list
    LinkedListNode* current = &dummy;
    while (left && right) {
        if (*(left->payload) <= *(right->payload)) {
            current->next = left;
            left->prev = current;
            left = left->next;
        } else {
            current->next = right;
            right->prev = current;
            right = right->next;
        }
        current = current->next;
    }
    // Attach the remainder of left or right list
    current->next = (left != NULL) ? left : right;
    if(current->next) current->next->prev = current;
    return dummy.next; // Head of merged list
}

// Recursively sorts a linked list using merge sort and returns new head node
LinkedListNode* SortMergeByNode(LinkedListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head; // Single node or empty list is already sorted
    }

    // Find the midpoint and split the list
    LinkedListNode* middle = FindMiddle(head);
    LinkedListNode* left = head;
    LinkedListNode* right = middle->next;
    middle->next = NULL; // Break the list into two halves

    // Recursively sort both halves
    left = SortMergeByNode(left);
    right = SortMergeByNode(right);

    // Merge the two sorted halves
    return merge(left, right);
}

// Sorts the entire linked list using merge sort
void SortMerge(LinkedList* list) {
    if (!list || !*list || !(*list)->head) {
        printf("Empty list.\n");
        return;
    }
    (*list)->head = SortMergeByNode((*list)->head);

    // Update tail pointer after sort
    LinkedListNode* newTail = (*list)->head;
    while (newTail && newTail->next != NULL) {
        newTail = newTail->next;
    }
    (*list)->tail = newTail;
}

// Displays the contents of the linked list
void PrintLinkedList(LinkedList list) {
    if (!list || !list->head) {
        printf("Linked list is empty.\n");
        return;
    }
    for (LinkedListNode* current = list->head; current != NULL; current = current->next) {
        printf("%lu ", *(current->payload));
    }
    printf("\n");
}

