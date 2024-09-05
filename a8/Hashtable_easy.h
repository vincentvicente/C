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
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList_easy.h"
#include <stdint.h>


typedef struct ll_head *LinkedList;

struct hashtableInfo {
  int num_buckets;
  int num_elements;
  LinkedList* buckets;
};

typedef struct hashtableInfo* Hashtable;

// Use JenkinsHash to hash a word
uint32_t JenkinsHash(char *key);

// Function to turn the hash key to the bucket index 
int HashKeyToBucketNum(Hashtable ht, char* key);

// Function to compare char in sortWord function
int cmpfunc (const void* a, const void* b);

// Function to sort the characters of the word (using quicksort)
// Returns the sorted string copy
char* sortWord(const char* word);

// Allocates and returns a new Hashtable.
//
// INPUT:
//   numBuckets: The number of buckets this hashtable will start with.
//
// Returns NULL if the hashtable was unable to be malloc'd, or
// the hashtable.
Hashtable CreateHashtable(int num_buckets);

// Destroys and Frees the hashtable.
//
// Input:
//   ht: the table to be free'd. It is unsafe to use the
//    hashtable after this is called.
void DestroyHashtable(Hashtable ht);

// Puts the given key value pair int the hashtable.
//
// INPUT:
//   ht: the hashtable to insert into
//   kvp: the key-value pair to put into the hashtable.
//   old_kvp: if there is a collision,
//   sets the old_kvp to point at the previous value.
//
// Returns 0 if put is successful.
// Returns 1 on failure (e.g., no more memory)
// Returns 2 if the key is already in the hashtable
int PutInHashtable(Hashtable ht, char * str);

// Looks up the given key in the hashtable.
// Returns the Key-Value pair in the provided result pointer.
//
// INPUT:
//   ht: the hashtable to lookup in
//   key: the key to lookup
//   result: If the key is in the hashtable, this is used
//      to return a pointer to a HTKeyValue to the caller.
//      Note, this HTKeyValue is still in the hashtable, so can't
//      be used to free the value.
//
// Returns 0 if the lookup was successful (and the result is valid).
// Returns -1 if the key was not found.
int LookupInHashtable(Hashtable ht, char *key, LinkedList *result);

// Gets the number of elements in the hashtable.
//
// INPUT:
//   ht: the Hashtable
//
// Returns the number of elements in the hashtable.
int NumElemsInHashtable(Hashtable ht);

// Removes the HTKeyValue with the given key from the
//  hashtable.
//
// INPUT:
//   ht: the hashtable
//   key: the key to remove
//   junkKVP: a pointer to the removed HTKeyValue, to
//     allow the value to be freed by the caller.
//
// Returns 0 if the key was found successfully (and junkKVP is valid)
// Returns -1 if the key was not found in the hashtable.
int RemoveFromHashtable(Hashtable ht, char *key);

// Function to print all groups of anagrams in the word.txt
void PrintResults(Hashtable ht);


#endif  // HASHTABLE_H

