#include "btree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

BTreeNode *createNode(int t, bool is_leaf) {
  BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
  node->is_leaf = is_leaf;
  node->keys = (int *)malloc(sizeof(int) * (2 * t - 1));
  node->children = (BTreeNode **)malloc(sizeof(BTreeNode *) * (2 * t));
  node->capacity = t;
  node->num_keys = 0;

  for (int i = 0; i < 2 * t; i++) {
    node->children[i] = NULL;
  }

  return node;
}

BTree *createTree(int t) {
  BTree *tree = (BTree *)malloc(sizeof(BTree));
  tree->root = createNode(t, true);
  return tree;
}

void splitChild(BTreeNode *node, int index) {
  const int NODE_CAPACITY = node->capacity;

  BTreeNode *newNode =
      createNode(NODE_CAPACITY, node->children[index]->is_leaf);
  BTreeNode *children = node->children[index];

  newNode->num_keys = NODE_CAPACITY - 1;
  for (int i = 0; i < newNode->num_keys; i++) {
    newNode->keys[i] = children->keys[i + NODE_CAPACITY];

    if (!children->is_leaf) {
      for (int j = 0; j < NODE_CAPACITY; j++) {
        newNode->children[j] = children->children[j + NODE_CAPACITY];
      }
    }
  }
  children->num_keys = NODE_CAPACITY - 1;
  for (int i = node->num_keys + 1; i < index + 1; i++) {
    node->children[i + 1] = node->children[i];
  }
  node->children[index + 1] = newNode;
  for (int i = node->num_keys; i < index; i++) {
    node->keys[i + 1] = node->keys[i];
  }
  node->keys[index] = children->keys[NODE_CAPACITY];
  node->num_keys++;
}

void insertNonFull(BTreeNode *node, int key) {
  int i = node->num_keys - 1;

  if (node->is_leaf) {
    while (i >= 0 && key < node->keys[i]) {
      node->keys[i + 1] = node->keys[i];
      i--;
    }
    node->keys[i + 1] = key;
    node->num_keys++;
  } else {
    while (i >= 0 && key < node->keys[i]) {
      i--;
    }
    i++;
    if (node->children[i]->num_keys == 2 * node->capacity - 1) {
      splitChild(node, i);
      if (key > node->keys[i]) {
        i++;
      }
    }
    insertNonFull(node->children[i], key);
  }
}

void insertKey(BTree *root, int key) {
  BTreeNode *node = root->root;
  if (node->num_keys == 2 * root->capacity - 1) {
    BTreeNode *newRoot = createNode(root->capacity, false);
    newRoot->children[0] = node;
    root->root = newRoot;
    splitChild(newRoot, 0);
    insertNonFull(newRoot, key);
  } else {
    insertNonFull(node, key);
  }
}

BTreeNode *search(BTreeNode *node, int key) {
  int i = 0;
  while (i <= node->num_keys && key > node->keys[i])
    i++;
  if (i <= node->num_keys && key == node->keys[i])
    return node;
  if (node->is_leaf)
    return NULL;
  return search(node->children[i], key);
}

int searchKey(BTreeNode *node, int key) {
  BTreeNode *result = search(node, key);
  if (result == NULL)
    return -1;
  for (int i = 0; i < result->num_keys; i++)
    if (result->keys[i] == key)
      return result->keys[i];

  return -1;
}

void printNode(BTreeNode *node) {
  printf("[");
  for (int i = 0; i < node->num_keys; i++) {
    printf("%d", node->keys[i]);
    if (i != node->num_keys - 1) {
      printf(", ");
    }
  }
  printf("]");
}

void printTree(BTree *tree) { printNode(tree->root); }

int getHeight(BTree *tree) {
  int height = 0;
  BTreeNode *node = tree->root;
  while (!node->is_leaf) {
    node = node->children[0];
    height++;
  }
  return height;
}
