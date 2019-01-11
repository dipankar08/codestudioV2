/***************************************************
 * Title : Easy But Wrong solution.
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include <iostream>
using namespace std;

bool isValidBST(TreeNode *root) {
  if (root == NULL) {
    return true;
  }
  if (root->left != NULL && root->left->val > root->val) {
    return false;
  }
  if (root->right != NULL && root->right->val < root->val) {
    return false;
  }
  if (!isValidBST(root->left) || !isValidBST(root->right)) {
    return false;
  }
  return true;
}

int main() {
  cout << isValidBST(createTree({1, 2, 3})) << endl;                     // 0
  cout << isValidBST(createTree({2, 1, 3})) << endl;                     // 1
  cout << isValidBST(createTree({5, 1, 4, tnull, tnull, 3, 6})) << endl; // 0
  cout << isValidBST(createTree({3, 2, 5, 1, 4})) << endl; // 1 <-- Wrong
  return 0;
}