/*
 *  This is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  It is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  See <http://www.gnu.org/licenses/>.
 */
#include "gtest/gtest.h"

extern "C" {
    #include "LinkedList_easy.h"
    #include "Sort.h"
}

uint64_t first = 15;
uint64_t second = 23;
uint64_t third = 42;
uint64_t fourth = 5;
uint64_t value1 = 18;
uint64_t value2 = 31;
uint64_t value3 = 7;
uint64_t value4 = 9;
uint64_t value5 = 27;

#define MAX_VALUE_LEN 75

TEST(InsertionSort, givenNoInputWhenCreatingListThenMergeSort) {
    LinkedList list = CreateLinkedList();

    // Inserting in reverse order to insert at the head
    InsertLinkedList(list, &fourth);
    InsertLinkedList(list, &third);
    InsertLinkedList(list, &second);
    InsertLinkedList(list, &first);

    // print before sorting
    printf("Before sorting:\n");
    PrintLinkedList(list);

    // selection sort
    SortInsertion(&list);

    // print after sorting
    printf("After sorting:\n");
    PrintLinkedList(list);

    // Expected sorted list
    uint64_t expected[] = {5, 15, 23, 42};

    // Verify the sorted list
    LinkedListNode* curr = list->head;
    size_t i = 0;
    while (curr != NULL) {
        EXPECT_EQ(expected[i], *(uint64_t*)(curr->payload));
        curr = curr->next;
        i++;
    }
    EXPECT_EQ(5, (int)*(uint64_t*)(list->head->payload));
    EXPECT_EQ(15, (int)*(uint64_t*)(list->head->next->payload));
    EXPECT_EQ(42, (int)(*(uint64_t*)(list->tail->payload)));
    EXPECT_EQ(23, (int)(*(uint64_t*)(list->tail->prev->payload)));
    // Destroy the list after testing
    DestroyLinkedList(list);
}

TEST(SelectionSort, givenNoInputWhenCreatingListThenMergeSort) {
    LinkedList list = CreateLinkedList();
    // insert customized value
    InsertLinkedList(list, &value1);
    InsertLinkedList(list, &value2);
    InsertLinkedList(list, &value3);
    InsertLinkedList(list, &value4);
    InsertLinkedList(list, &value5);

    // print before sorting
    printf("Before sorting:\n");
    PrintLinkedList(list);

    // selection sort
    SortSelection(&list);

    // print after sorting
    printf("After sorting:\n");
    PrintLinkedList(list);

    // Expected sorted list
    uint64_t expected[] = {7, 9, 18, 27, 31};

    // Verify the sorted list
    LinkedListNode* curr = list->head;
    size_t i = 0;
    while (curr != NULL) {
        EXPECT_EQ(expected[i], *(uint64_t*)(curr->payload));
        curr = curr->next;
        i++;
    }

    EXPECT_EQ(7, (int)*(uint64_t*)(list->head->payload));
    EXPECT_EQ(9, (int)*(uint64_t*)(list->head->next->payload));
    EXPECT_EQ(31, (int)(*(uint64_t*)(list->tail->payload)));
    EXPECT_EQ(27, (int)(*(uint64_t*)(list->tail->prev->payload)));
    // Destroy the list after testing
    DestroyLinkedList(list);
}

TEST(MergeSort, givenNoInputWhenCreatingListThenMergeSort) {
    LinkedList list3 = CreateLinkedList();
    InsertLinkedList(list3, &first);
    InsertLinkedList(list3, &second);
    InsertLinkedList(list3, &third);
    InsertLinkedList(list3, &fourth);

     // print before sorting
    printf("Before sorting:\n");
    PrintLinkedList(list3);

    EXPECT_EQ(*list3->head->payload, first);
    EXPECT_EQ(*list3->head->next->payload, second);
    SortMerge(&list3);

    // print after sorting
    printf("After sorting:\n");
    PrintLinkedList(list3);

    // Expected sorted list
    uint64_t expected[] = {5, 15, 23, 42};

    // Verify the sorted list
    LinkedListNode* curr = list3->head;
    size_t i = 0;
    while (curr != NULL) {
        EXPECT_EQ(expected[i], *(uint64_t*)(curr->payload));
        curr = curr->next;
        i++;
    }
    EXPECT_EQ(5, (int)*(uint64_t*)(list3->head->payload));
    EXPECT_EQ(15, (int)*(uint64_t*)(list3->head->next->payload));
    EXPECT_EQ(42, (int)(*(uint64_t*)(list3->tail->payload)));
    EXPECT_EQ(23, (int)(*(uint64_t*)(list3->tail->prev->payload)));
    DestroyLinkedList(list3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

