#include <stdio.h>
#include "btree.h"

int main(void) {
  BTree *tree = createTree(3);
  insertKey(tree, 10);
  insertKey(tree, 20);
  insertKey(tree, 30);
  insertKey(tree, 40);
  insertKey(tree, 50);
  insertKey(tree, 60);
  insertKey(tree, 70);
  insertKey(tree, 80);
  insertKey(tree, 90);
  insertKey(tree, 100);

  printf("%d\n", searchKey(search(tree->root, 20), 20));
  printf("%d\n", searchKey(search(tree->root, 10), 10));
  printf("%d\n", searchKey(search(tree->root, 100), 50));

  printTree(tree);

  return 0;
}
