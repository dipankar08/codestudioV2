/***************************************************
 * Title : Uisng passing ref
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include <cmath>
#include <iostream>
using namespace std;

void helper(TreeNode *root, double target, int &goal, double &minn) {
  if (root == nullptr)
    return;

  if (abs(root->val - target) < minn) {
    minn = abs(root->val - target);
    goal = root->val;
  }

  if (target < root->val) {
    helper(root->left, target, goal, minn);
  } else {
    helper(root->right, target, goal, minn);
  }
}

int closestValue(TreeNode *root, double target) {
  int goal = 0;
  double minn = INT_MAX;
  helper(root, target, goal, minn);
  return goal;
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
