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
    #include "../arraylist.h"
    #include <string.h>
    #include <stdbool.h>
    #include <stdlib.h>
}
const char* first = "first";
const char* second="second";
const char* third = "third";
const char* fourth = "fourth";

#define MAX_VALUE_LEN 75

//using givenWhenThen

Node* createNode(char* data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->value = data;
    return n;
}

TEST(test,test) {
    EXPECT_TRUE(true);
}

TEST(get, testGetHappyPath) {
    ArrayList* list = create(10);
    EXPECT_EQ(list->size, 0);
    //EXPECT_EQ(list->num_elements, 10);

    Node* n1 = createNode("test1");
    list->nodes[0] = n1;
    list->size = 1;
    char* res = get(list, 0);
    EXPECT_EQ(strcmp(n1->value, res), 0);
//    destroyList(list);
}

TEST(get, testGetNullPath) {
    ArrayList* list = create(10);
    Node* n1 = createNode("test1");
    list->nodes[0] = n1;
    list->size = 1;
    //list->num_elements = 10;
    char* res = get(list, 1);
    EXPECT_EQ(res, nullptr);
//    destroyList(list);
}

TEST(removeAt, testRemoveAtHappyPath) {
    ArrayList* list = create(10);
    Node* n1 = createNode("test1");
    list->nodes[0] = n1;
    list->size = 1;
    removeAt(list, 0);
    char* res = get(list, 0);
    EXPECT_EQ(res, nullptr);
    EXPECT_EQ(0, list->size);
//    destroyList(list);
    //free(n1);
}

TEST(add, testAddHappyPath) {
    ArrayList* list = create(10);
    add(list, 1);
    char* res = get(list, 0);
    EXPECT_EQ(strcmp("test1", res), 0);
    EXPECT_EQ(1, list->size);
//    destroyList(list);
}

TEST(add, testAddResizePath) {
    ArrayList* list;
    ArrayList* created = create(2);
    list = created;
    list = add(list, 1);
    list = add(list, 2);
    EXPECT_TRUE(list == created); //test reference equality
    EXPECT_EQ(list->size, 2);
    //EXPECT_EQ(list->num_elements, 2);

    int count = list->size;
    int i;
    for(i=0; i<100; i++) {
        char buf[33];
        snprintf(buf, sizeof(buf), "test%d", i);
        list = add(list, i);
        count++;
    }
    char* res = get(list, 1);
    EXPECT_EQ(strcmp("test2", res), 0);
    EXPECT_EQ(count, list->size);
//    destroyList(list);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
