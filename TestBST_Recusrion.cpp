/***************************************************
 * Title : Recustive solution by passing max or min.
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include <iostream>
using namespace std;

bool isValidRecur(TreeNode *root, long min, long max) {
  if (!root) {
    return true;
  }
  int val = root->val;
  if (val <= min || val >= max) {
    return false;
  }
  return isValidRecur(root->left, min, val) &&
         isValidRecur(root->right, val, max);
}
bool isValidBST(TreeNode *root) {
  return isValidRecur(root, LONG_MIN, LONG_MAX);
}

int main() {
  cout << isValidBST(createTree({1, 2, 3})) << endl; // 0
  cout << isValidBST(createTree({2, 1, 3})) << endl; // 1
  cout << isValidBST(createTree({5, 1, 4, tnull, tnull, 3, 6})) << endl; //0 
  cout << isValidBST(createTree({3, 2, 5, 1, 4})) << endl; // 0
  return 0;
}
