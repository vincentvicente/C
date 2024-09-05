//A Binary Search Tree is a tree where given a node `N`, `N.left` is less than N
//and N.right is greater than N.
//    3
//   / \
//  1   5
//    /   \
//   4     6
// the above is a valid bst.
// the below is not.
//    3
//   / \
//  1   2
//    /   \
//   4     6

//You're given a simple implementation of a BinaryTree. Write code that does the following:

//Q1. Implement the function `isBST(tree) => boolean`. `isBst` takes as argument a tree
//and returns true if it is a BST, false otherwise.
//Q2. Implement the function `findNumsBelow(bst, num) => int[]`. FindNum traverses a BST and returns
//all values less than num in an array.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

typedef struct Node {
  int value;
  struct Node* left;
  struct Node* right;
}Node;

typedef struct Tree {
  Node* root;
  int size;
}Tree;

bool isBstUtil(Node* node, int min, int max) {
  if (node == NULL) {
    return true;
  }
  if (node->value < min || node->value > max) {
    return false;
  }
  return isBstUtil(node->left, min, node->value - 1) && isBstUtil(node->right, node->value + 1, max);
}

bool isBst(Tree* t) {
  return isBstUtil(t->root, INT_MIN, INT_MAX);
}

void findNumsBelowUtil(Node* node, int num, int* result, int* count) {
  if (node == NULL) {
    return;
  }
  findNumsBelowUtil(node->left, num, result, count);
  if (node->value < num) {
    result[(*count)++] = node->value;
  }
  findNumsBelowUtil(node->right, num, result, count);
}

int* findNumsBelow(Tree* t, int num) {
  static int result[100]; // Use a static array for simplicity
  int count = 0;
  if (!isBst(t)) {
    printf("error: tree given is not a bst\n");
    return NULL;
  }
  findNumsBelowUtil(t->root, num, result, &count);
  result[count] = -1; // Mark the end of the result array
  return result;
}

void printNodeRecursive(Node* n) {
  if(n == NULL) return;
  printf("%d\n", n->value);
  printNodeRecursive(n->left);
  printNodeRecursive(n->right);
}

void printTree(Tree* t) {
  printNodeRecursive(t->root);
}

Node* createNode(int value) {
  Node* n1 = (Node*)malloc(sizeof(Node));
  n1->value = value;
  n1->left = NULL;
  n1->right = NULL;
  return n1;
}

Tree* createTree(Node* root) {
  Tree* t = (Tree*)malloc(sizeof(Tree));
  t->root = root;
  t->size = 1;
}

Tree* getTestBst() {
  Node* n1 = createNode(10);
  Node* n2 = createNode(6);
  Node* n3 = createNode(13);
  Node* n4 = createNode(7);
  Node* n5 = createNode(5);

  n1->left = n2;
  n1->right = n3;
  n2->right = n4;
  n2->left = n5;

  Tree* t = createTree(n1);
  return t;
}

int main() {
  Tree* testBst = getTestBst();
  printTree(testBst);

  // Checking if the tree is a BST
  if(isBst(testBst)) {
    printf("The tree is a BST.\n");
  } else {
    printf("The tree is not a BST.\n");
}

  // Finding numbers below a given value in the BST
  int num = 8;
  int* numsBelow = findNumsBelow(testBst, num);
  printf("Numbers below %d: ", num);
  for (int i = 0; numsBelow[i] != -1; i++) {
    printf("%d ", numsBelow[i]);
  }
  printf("\n");

  return 0;
}














//Here to make sure everything compiles.  Feel free to ignore.
  Node* n1 = createNode(10);
  n1->left = createNode(1);
  n1->right = createNode(11);
  Tree* t = createTree(n1);
  printTree(t);

  return 0;
}
