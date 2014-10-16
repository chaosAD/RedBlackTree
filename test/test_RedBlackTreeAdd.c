#include <stdio.h>
#include "unity.h"
#include "Node.h"
#include "Rotations.h"
#include "RedBlackTree.h"
#include "InitNode.h"
#include "CustomAssertions.h"
#include "CException.h"

Node node1, node5, node10, node13, node15;

void setUp(void) {
  resetNode(&node1, 1);
  resetNode(&node5, 5);
  resetNode(&node10, 10);
  resetNode(&node13, 13);
  resetNode(&node15, 15);
}

void tearDown(void) {}

/**
 *         root              root
 *           |    add 10      |
 *           v   -------->    v
 *         NULL              10(b)
 */
void test_addRedBlackTree_add_10_to_empty_tree(void) {
	setNode(&node10, NULL, NULL, 'r');
  Node *root = NULL;

  addRedBlackTree(&root, &node10);

  TEST_ASSERT_EQUAL_PTR(root, &node10);
  //                     left right color   node
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
}

/**
 *          root            root
 *           |     add 5     |
 *           v    ------>    v
 *          10(b)           10(b)
 *                         /
 *                       5(r)
 */
void test_addRedBlackTree_add_5_to_tree_with_root_10(void) {
	setNode(&node10, NULL, NULL, 'b');
  setNode(&node5, NULL, NULL, 'r');
  Node *root = &node10;

  addRedBlackTree(&root, &node5);
  TEST_ASSERT_EQUAL_PTR(root, &node10);
  TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
}

/**
 *          root            root
 *           |     add 13     |
 *           v    ------>     v
 *          10(b)           10(b)
 *                           \
 *                           13(r)
 */
void test_addRedBlackTree_add_13_to_tree_with_root_10(void) {
	setNode(&node10, NULL, NULL, 'b');
  setNode(&node13, NULL, NULL, 'r');
  Node *root = &node10;

  addRedBlackTree(&root, &node13);
  TEST_ASSERT_EQUAL_PTR(root, &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, &node13, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node13);
}

/**
 *          root             root
 *           |                |
 *           v      add 1     v
 *          10(b)  ------>   5(b)
 *          /               /   \
 *        5(r)           1(r)   10(r)
 */
void test_addRedBlackTree_add_1_to_tree_with_5_10_nodes(void) {
	setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node10, &node5, NULL, 'b');
  Node *root = &node10;

  addRedBlackTree(&root, &node1);
  TEST_ASSERT_EQUAL_PTR(root, &node5);
  TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
}
