#include <stdbool.h>

typedef struct BTreeNode {
  int *keys;
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
BTree* createTree(int k);
void destroyNode(BTreeNode* n);
void destroyTree(BTree* b);
BTreeNode* search(BTreeNode* root, int key);
