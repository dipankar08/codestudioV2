/***************************************************
 * Title :
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include <deque>
#include <iostream>
#define tnull 1000
using namespace std;
TreeNode *createUtil(deque<int> &data) {
  if (data.size() == 0) {
    return nullptr;
  }
  int val = data.front();
  data.pop_front();
  if (val == tnull) {
    return nullptr;
  }
  TreeNode *currentRoot = new TreeNode(val);
  currentRoot->left = createUtil(data);
  currentRoot->right = createUtil(data);
  return currentRoot;
}

TreeNode *createTree(deque<int> data) { return createUtil(data); }

int main() {
  printTree(createTree({1, 2, TNULL, 3}));
  return 0;
}
