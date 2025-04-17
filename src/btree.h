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

BTreeNode* createNode(int capacity, bool is_leaf);
BTree* createTree(int capacity);
void destroyNode(BTreeNode* node);
void destroyTree(BTree* tree);
BTreeNode* search(BTreeNode* root, int key);
void insertKey(BTree* root, int key);
void splitChild(BTreeNode* node, int index);
void insertNonFull(BTreeNode* node, int key);
