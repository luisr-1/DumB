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
  tree->root = createNode(t, true);
  return tree;
}

void insertKey(BTree *root, int key) {

}

void splitChild(BTreeNode *node, int index) {
  const int NODE_CAPACITY = node->capacity;

  BTreeNode* newNode = createNode(NODE_CAPACITY, node->children[index]->is_leaf);
  BTreeNode* children = node->children[index];

  newNode->num_keys = NODE_CAPACITY - 1;
  for(int i = 0; i <= newNode->num_keys; i++) {
    newNode->keys[i] = children->keys[i + NODE_CAPACITY];

    if(!children->is_leaf) {
      for(int j = 0; j < NODE_CAPACITY; j++) {
        newNode->children[j] = children->children[j + NODE_CAPACITY];
      }
    }
  }

}

void insertNonFull(BTreeNode *node, int key) {

}

int main(void) {
  BTree* tree = createTree(3);
  printf("%d\n", tree->root->capacity);
  return 0;
}
