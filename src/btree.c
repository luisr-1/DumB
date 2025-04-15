#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct BTreeNode {
  int *keys; //vetor 
  struct BTreeNode **children;
  int num_keys;
  bool is_leaf;
  int capacity; 
} BTreeNode;

int main(void) {
  return 0;
}
