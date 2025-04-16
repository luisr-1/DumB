#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

BTreeNode* createNode(int t, bool is_leaf) {
  BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
  node->is_leaf = is_leaf;
  node->keys = (int*)malloc(sizeof(int) * (2 * t - 1));
  node->children = (BTreeNode**)malloc(sizeof(BTreeNode*) * (2 * t));
  node->capacity = t;
  node->num_keys = 0;

  for(int i = 0; i < 2 * t; i++) {
    node->children[i] = NULL; 
  }
  
  return node;
}

BTree* createTree(int t) {
  BTree* tree = (BTree*)malloc(sizeof(BTree));
  return tree;
}

int main(void) {
  return 0;
}
