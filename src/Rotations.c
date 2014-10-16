#include <stdio.h>
#include "Rotations.h"
#include "Node.h"

void leftRotate(Node **nodePtr) {
}

void rightRotate(Node **nodePtr) {
  Node *root;
  Node *left = (root = *nodePtr)->left;
  root->left = left->right;
  left->right = root;
  *nodePtr = left;
}