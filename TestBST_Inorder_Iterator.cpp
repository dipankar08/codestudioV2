/***************************************************
 * Title : Recustive solution by passing max or min.
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include <iostream>
#include <stack>
using namespace std;

bool isValidBST(TreeNode *root) {
  if (root == nullptr) {
    return true;
  }
  stack<TreeNode *> st;
  TreeNode *pre = nullptr;
  while (root != nullptr || !st.empty()) {
    while (root != nullptr) {
      st.push(root);
      root = root->left;
    }
    root = st.top();
    st.pop();
    if (pre != nullptr && root->val <= pre->val) {
      return false;
    }
    pre = root;
    root = root->right;
  }
  return true;
}

int main() {
  cout << isValidBST(createTree({1, 2, 3})) << endl;                     // 0
  cout << isValidBST(createTree({2, 1, 3})) << endl;                     // 1
  cout << isValidBST(createTree({5, 1, 4, tnull, tnull, 3, 6})) << endl; // 0
  cout << isValidBST(createTree({3, 2, 5, 1, 4})) << endl;               // 0
  return 0;
}
