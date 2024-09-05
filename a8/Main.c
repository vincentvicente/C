#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include "Hashtable_easy.h"

#define MAX_LINE_LENGTH 512

int main() {
    FILE *wordsFile;
    char buffer[MAX_LINE_LENGTH];
    wordsFile = fopen("words.txt", "r");
    if (wordsFile == NULL) {
        perror("Error opening file");
        return 1;
    }
    Hashtable anagramsTable = CreateHashtable(500);
    while (fgets(buffer, MAX_LINE_LENGTH, wordsFile) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;
        char *word = strdup(buffer);
        if (!word) {
            perror("Memory allocation failed for word");
            continue;
        }
        int result = PutInHashtable(anagramsTable, word);
        if (result == 1) {
            fprintf(stderr, "Failed to insert '%s' into the hash table.\n", word);
            free(word);
        }
    }
    fclose(wordsFile);

    PrintResults(anagramsTable);
    DestroyHashtable(anagramsTable);
    return 0;
}

