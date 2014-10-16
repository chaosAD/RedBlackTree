#include <stdio.h>
#include "RedBlackTree.h"
#include "ErrorCode.h"

void _addRedBlackTree(Node **rootPtr, Node *newNode);

void addRedBlackTree(Node **rootPtr, Node *newNode) {
  _addRedBlackTree(rootPtr, newNode);
//  (**rootPtr).color = 'b';
  (*rootPtr)->color = 'b';
}

void _addRedBlackTree(Node **rootPtr, Node *newNode) {
  Node *root = *rootPtr;
  if(root == NULL) {
    *rootPtr = newNode;
    return;
  }
  if(newNode->data < root->data) {
    _addRedBlackTree(&root->left, newNode);
  } else if(newNode->data > root->data) {
    _addRedBlackTree(&root->right, newNode);
  }
}