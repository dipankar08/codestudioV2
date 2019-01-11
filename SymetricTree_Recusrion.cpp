/***************************************************
 * Title : Define Symmetric using recusrsives
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include <iostream>
#include <vector>
using namespace std;
bool helper(TreeNode *p, TreeNode *q) {
  if (!p && !q) {
    return true;
  } else if (!p || !q) {
    return false;
  }

  if (p->val != q->val) {
    return false;
  }

  return helper(p->left, q->right) && helper(p->right, q->left);
}
bool isSymmetric(TreeNode *root) {
  if (!root) {
    return true;
  }
  return helper(root->left, root->right);
}

int main() {
  cout << "result:" << isSymmetric(createTree({1, 2, 2, 3, 4, 4, 3})) << endl;
  cout << "result:" << isSymmetric(createTree({1, 2, 2, tnull, 3, tnull, 3}))
       << endl;
  return 0;
}
