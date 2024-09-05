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
#include <stdio.h>
extern "C" {
    #include "Hashtable_easy.h"
    #include "LinkedList_easy.h"
    #include <string.h>  // For strdup
}

TEST(Hashtable, Create) {
  Hashtable anagramsTable = CreateHashtable(10);
  EXPECT_FALSE(anagramsTable == NULL);
  EXPECT_FALSE(anagramsTable->buckets == NULL);
  EXPECT_EQ(NumElemsInHashtable(anagramsTable), 0);
  DestroyHashtable(anagramsTable);
}

TEST(Hashtable, AddOneRemoveOne) {
    Hashtable anagramsTable = CreateHashtable(10);
    EXPECT_EQ(NumElemsInHashtable(anagramsTable), 0);

    char *word = strdup("apple");
    PutInHashtable(anagramsTable, word);
    EXPECT_EQ(NumElemsInHashtable(anagramsTable), 1);

    char *key = strdup("papel");
    RemoveFromHashtable(anagramsTable, key);
    EXPECT_EQ(NumElemsInHashtable(anagramsTable), 0);

    DestroyHashtable(anagramsTable);
    free(key);
}

TEST(Hashtable, AddOneElemDestroy) {
    Hashtable anagramsTable = CreateHashtable(10);
    EXPECT_EQ(NumElemsInHashtable(anagramsTable), 0);

    char *word = strdup("banana");
    PutInHashtable(anagramsTable, word);
    EXPECT_EQ(NumElemsInHashtable(anagramsTable), 1);

    DestroyHashtable(anagramsTable);
}

TEST(Hashtable, AddOneElemTwoTimes) {
    Hashtable anagramsTable = CreateHashtable(10);
    EXPECT_EQ(NumElemsInHashtable(anagramsTable), 0);

    char *word1 = strdup("char");
    char *word2 = strdup("char");
    char *word3 = strdup("arch");
    int result;

    result = PutInHashtable(anagramsTable, word1);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(NumElemsInHashtable(anagramsTable), 1);

    result = PutInHashtable(anagramsTable, word2);
    EXPECT_EQ(result, 2);
    EXPECT_EQ(NumElemsInHashtable(anagramsTable), 1);

    free(word2);

    result = PutInHashtable(anagramsTable, word3);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(NumElemsInHashtable(anagramsTable), 2);

    DestroyHashtable(anagramsTable);
}

TEST(Hashtable, AddOneRemoveTwice) {
    Hashtable anagramsTable = CreateHashtable(10);
    EXPECT_EQ(NumElemsInHashtable(anagramsTable), 0);

    char *word = strdup("dealer");
    int result = PutInHashtable(anagramsTable, word);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(NumElemsInHashtable(anagramsTable), 1);

    char *key = strdup("leader");
    result = RemoveFromHashtable(anagramsTable, key);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(NumElemsInHashtable(anagramsTable), 0);

    result = RemoveFromHashtable(anagramsTable, key);
    EXPECT_EQ(result, -1);
    EXPECT_EQ(NumElemsInHashtable(anagramsTable), 0);

    DestroyHashtable(anagramsTable);
    free(key);
}

TEST(Hashtable, AddMultipleItems) {
    Hashtable anagramsTable = CreateHashtable(50);
    EXPECT_EQ(NumElemsInHashtable(anagramsTable), 0);

    char *word1 = strdup("listen");
    char *word2 = strdup("silent");
    char *word3 = strdup("enlist");
    PutInHashtable(anagramsTable, word1);
    ASSERT_EQ(NumElemsInHashtable(anagramsTable), 1);

    PutInHashtable(anagramsTable, word2);
    ASSERT_EQ(NumElemsInHashtable(anagramsTable), 2);

    PutInHashtable(anagramsTable, word3);
    ASSERT_EQ(NumElemsInHashtable(anagramsTable), 3);

    DestroyHashtable(anagramsTable);
}

TEST(Hashtable, LookupInHashtable) {
    Hashtable anagramsTable = CreateHashtable(100);
    EXPECT_EQ(NumElemsInHashtable(anagramsTable), 0);

    char *word1 = strdup("stop");
    char *word2 = strdup("tops");
    PutInHashtable(anagramsTable, word1);
    ASSERT_EQ(NumElemsInHashtable(anagramsTable), 1);

    PutInHashtable(anagramsTable, word2);
    ASSERT_EQ(NumElemsInHashtable(anagramsTable), 2);

    LinkedList lookup;
    char *key = strdup("tops");
    int result = LookupInHashtable(anagramsTable, key, &lookup);
    EXPECT_EQ(lookup->num_elements, 2);
    EXPECT_EQ(strcmp(lookup->head->payload->value, "tops"), 0);
    EXPECT_EQ(strcmp(lookup->head->next->payload->value, "stop"), 0);

    EXPECT_EQ(result, 0);
    EXPECT_EQ(NumElemsInHashtable(anagramsTable), 2);

    free(key);
    DestroyHashtable(anagramsTable);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

