#ifndef header_file
#define header_file

// Define the structure for a node in a doubly linked list
typedef struct L_Node {
    struct L_Node* prev; // Pointer to the previous node in the list
    struct L_Node* next; // Pointer to the next node in the list
    int value; // The value stored in the node
}L_Node;

L_Node* createNode(int value); // Prototype for the function to create a new node with a given value

#endif

