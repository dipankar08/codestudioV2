/***************************************************
 * Title : Uisng passing ref
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include <cmath>
#include <iostream>
using namespace std;

int closestValue(TreeNode *root, double target) {
  double minn = INT_MAX;
  int result = root->val;

  while (root != nullptr) {
    if (target > root->val) {

      double diff = abs(root->val - target);
      if (diff < minn) {
        minn = min(minn, diff);
        result = root->val;
      }
      root = root->right;
    } else if (target < root->val) {

      double diff = abs(root->val - target);
      if (diff < minn) {
        minn = min(minn, diff);
        result = root->val;
      }
      root = root->left;
    } else {
      return root->val;
    }
  }

  return result;
}

int main() {
  TreeNode *root = new TreeNode(9);
  root->left = new TreeNode(4);
  root->right = new TreeNode(17);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(6);
  root->left->right->left = new TreeNode(5);
  root->left->right->right = new TreeNode(7);
  root->right->right = new TreeNode(22);
  root->right->right->left = new TreeNode(20);
  cout << closestValue(root, 4) << endl;  // 4
  cout << closestValue(root, 18) << endl; // 17
  cout << closestValue(root, 12) << endl; // 9
  return 0;
}
