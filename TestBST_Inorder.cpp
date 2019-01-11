/***************************************************
 * Title : Recustive solution by passing max or min.
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include <iostream>
using namespace std;

bool isValidRecur(TreeNode *root, TreeNode *&prev) {
  if (root == nullptr) {
    return true;
  }
  // recur to left
  if (!isValidRecur(root->left, prev)) {
    return false;
  }
  // Inorder check and save the prev
  if (prev != NULL && root->val <= prev->val) {
    return false;
  }
  prev = root;
  // recur in right
  return isValidRecur(root->right, prev);
}

bool isValidBST(TreeNode *root) {
  TreeNode *prev = NULL;
  return isValidRecur(root, prev);
}

int main() {
  cout << isValidBST(createTree({1, 2, 3})) << endl;                     // 0
  cout << isValidBST(createTree({2, 1, 3})) << endl;                     // 1
  cout << isValidBST(createTree({5, 1, 4, tnull, tnull, 3, 6})) << endl; // 0
  cout << isValidBST(createTree({3, 2, 5, 1, 4})) << endl;               // 0
  return 0;
}
