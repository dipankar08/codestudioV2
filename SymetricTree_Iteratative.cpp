/***************************************************
 * Title : Define Symmetric using iterative
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include <iostream>
#include <queue>
using namespace std;
bool isSymmetric(TreeNode *root) {
  TreeNode *left, *right;
  if (!root) {
    return true;
  }
  // we define two queue for doing level wize
  queue<TreeNode *> q1, q2;
  q1.push(root->left);
  q2.push(root->right);
  // let;s so parallel level wize.
  while (!q1.empty() && !q2.empty()) {
    left = q1.front();
    q1.pop();
    right = q2.front();
    q2.pop();
    if (NULL == left && NULL == right) {
      continue;
    }
    if (NULL == left || NULL == right) {
      return false;
    }
    if (left->val != right->val) {
      return false;
    }
    q1.push(left->left);
    q1.push(left->right);
    q2.push(right->right);
    q2.push(right->left);
  }
  return true;
}

int main() {
  cout << "result:" << isSymmetric(createTree({1, 2, 2, 3, 4, 4, 3})) << endl;
  cout << "result:" << isSymmetric(createTree({1, 2, 2, tnull, 3, tnull, 3}))
       << endl;
  return 0;
}
