#include <stdbool.h>

typedef struct BTreeNode {
  int *keys; //vetor
  struct BTreeNode **children;
  int num_keys;
  bool is_leaf;
  int capacity;
} BTreeNode;

typedef struct BTree {
    BTreeNode *root;
    int capacity;
} BTree;

BTreeNode* createNode(int t, bool is_leaf);
