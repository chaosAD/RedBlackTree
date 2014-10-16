#include <stdio.h>
#include "unity.h"
#include "Node.h"
#include "InitNode.h"
#include "Rotations.h"
#include "CustomAssertions.h"

Node node1, node5, node8, node10, node15;

void setUp(void) {
  resetNode(&node1, 1);
  resetNode(&node5, 5);
  resetNode(&node8, 8);
  resetNode(&node10, 10);
  resetNode(&node15, 15);
}

void tearDown(void) {}

/**
 *         root
 *           |         root
 *           v           |
 *          10           v
 *         /             5
 *        5     --->   /  \
 *       /            1   10
 *      1
 */
void test_rightRotate_3_nodes(void) {
	setNode(&node1, NULL, NULL, 'b');
  setNode(&node5, &node1, NULL, 'b');
  setNode(&node10, &node5, NULL, 'b');
  Node *root = &node10;

  rightRotate(&root);

  TEST_ASSERT_EQUAL_PTR(root, &node5);
  TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
  TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
  TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
  TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
  TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
  TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
  TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
}

/**
 *         root         root
 *           |           |
 *           v           v
 *          10           5
 *         /            / \
 *        5     --->   1  10
 *       / \              /
 *      1  8             8
 */
void test_rightRotate_4_nodes(void) {
	setNode(&node1, NULL, NULL, 'b');
  setNode(&node8, NULL, NULL, 'b');
  setNode(&node5, &node1, &node8, 'b');
  setNode(&node10, &node5, NULL, 'b');
  Node *root = &node10;

  rightRotate(&root);

  TEST_ASSERT_EQUAL_PTR(root, &node5);
  //                     left right color   node
  TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(&node8, NULL, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node8);
}