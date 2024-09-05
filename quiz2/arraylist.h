#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct Node {
    char* value;
}Node;

typedef struct ArrayList {
    Node** nodes;
    int size;
    int capacity;
}ArrayList;

char* get(ArrayList* list, int index);

void removeAt(ArrayList* list, int index);

ArrayList* create(int size);

ArrayList* add(ArrayList* list, int value);

void destroyList(ArrayList* list);

void destroyNode(Node* node);

#endif  // ARRAYLIST_H
