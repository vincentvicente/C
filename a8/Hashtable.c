/*
 *  Contains implmentation of FNV Hash function. 
 *
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

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "Hashtable_easy.h"

#define FNV_PRIME 0x01000193 // 16777619
#define FNV_OFFSET_BASIS 0x811C9DC5 // 2166136261

// Function to compute FNV hash for a string
uint32_t FNVHash(char *key) {
  uint32_t hash = FNV_OFFSET_BASIS;
  while (*key) {
    hash ^= (uint32_t)(*key++);
    hash *= FNV_PRIME;
  }
  return hash;
}

// Function to map a key to a bucket in the hashtable
int HashKeyToBucketNum(Hashtable ht, char *key) {
  return FNVHash(key) % ht->num_buckets;
}

int cmpfunc(const void* a, const void* b) {
  return (*(char*)a - *(char*)b);
}

// Function to sort the characters of a word (using quicksort)
char* sortWord(const char* word) {
    size_t len = strlen(word);
    char* sorted_word = malloc(len + 1);
    if (sorted_word == NULL) {
        return NULL;
    }

    snprintf(sorted_word, len + 1, "%s", word);
    qsort(sorted_word, len, sizeof(char), cmpfunc);

    return sorted_word;
}

// Function to create a new hashtable
Hashtable CreateHashtable(int num_buckets) {
  Hashtable ht = (Hashtable)malloc(sizeof(struct hashtableInfo));
  if (ht == NULL) {
    perror("Memory allocation failed");
    return NULL;
  }

  ht->buckets = (LinkedList*)malloc(num_buckets * sizeof(LinkedList));
  if (ht->buckets == NULL) {
      free(ht);
      perror("Memory allocation failed");
      return NULL;
  }

  for (int i = 0; i < num_buckets; i++) {
      ht->buckets[i] = CreateLinkedList();
      if (ht->buckets[i] == NULL) {
          for (int j = 0; j < i; j++) {
              DestroyLinkedList(ht->buckets[j]);
          }
          free(ht->buckets);
          free(ht);
          perror("Memory allocation failed");
          return NULL;
      }
  }

  ht->num_buckets = num_buckets;
  ht->num_elements = 0;

  return ht;
}

void DestroyHashtable(Hashtable ht) {
    if (ht == NULL) return;

    for (int i = 0; i < ht->num_buckets; i++) {
        DestroyLinkedList(ht->buckets[i]);
    }

    free(ht->buckets);
    free(ht);
}

int PutInHashtable(Hashtable ht, char* str) {
    if (ht == NULL) {
        perror("Hash table doesn't exist");
        return 1;
    }

    char *sorted_key = sortWord(str);
    int bucket_idx = HashKeyToBucketNum(ht, sorted_key);
    LinkedList bucket = ht->buckets[bucket_idx];

    LinkedListNode *curr = bucket->head;
    while (curr != NULL) {
        if (strcmp(curr->payload->value, str) == 0) {
            free(sorted_key);
            return 2; // Key already exists
        }
        curr = curr->next;
    }

    HTKeyValue *kvp = (HTKeyValue *)malloc(sizeof(HTKeyValue));
    if (!kvp) {
        free(sorted_key);
        perror("Memory allocation failed");
        return -1;
    }
    kvp->key = sorted_key;
    kvp->value = str;
    InsertLinkedList(bucket, kvp);
    ht->num_elements++;

    return 0;
}

void PrintResults(Hashtable ht) {
    printf("============== Anagrams Hash Table ==============\n");
    for (int i = 0; i < ht->num_buckets; i++) {
        LinkedList bucket = ht->buckets[i];
        if (bucket->num_elements == 0) continue;
        LinkedListNodePtr current = bucket->head;
        printf("Anagram Group: %-20s | Words: ", current->payload->key);
        while (current != NULL) {
            printf("%s ", current->payload->value);
            current = current->next;
        }
        printf("\n");
    }
    printf("=================================================\n");
}

