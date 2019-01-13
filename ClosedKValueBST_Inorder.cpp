/***************************************************
 * Title : Inorder and select
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include "utils.h"
#include <cmath>
#include <iostream>
#include <stack>
using namespace std;
// Just a inorder traversal but stotre the value in a vectpr
void inorder(TreeNode *root, vector<int> &v) {
  if (!root){
    return;
  }
  inorder(root->left, v);
  v.push_back(root->val);
  inorder(root->right, v);
}
vector<int> closestKValues(TreeNode *root, double target, int k) {
  vector<int> res, v;
  inorder(root, v);
  int idx = 0;
  // output is shored so now select k closed. 
  double diff = numeric_limits<double>::max();
  for (int i = 0; i < v.size(); ++i) {
    if (diff >= abs(target - v[i])) {
      diff = abs(target - v[i]);
      idx = i;
    }
  }
  int left = idx - 1, right = idx + 1;
  for (int i = 0; i < k; ++i) {
    res.push_back(v[idx]);
    if (left >= 0 && right < v.size()) {
      if (abs(v[left] - target) > abs(v[right] - target)) {
        idx = right;
        ++right;
      } else {
        idx = left;
        --left;
      }
    } else if (left >= 0) {
      idx = left;
      --left;
    } else if (right < v.size()) {
      idx = right;
      ++right;
    }
  }
  return res;
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
  printVec(closestKValues(root, 4, 3));  // 3.4.5
  printVec(closestKValues(root, 18, 3)); // 17,20, 22
  printVec(closestKValues(root, 12, 3)); // 9,7,17

  return 0;
}
