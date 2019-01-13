/***************************************************
 * Title :
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include "utils.h"
#include <iostream>
#include <vector>
using namespace std;
vector<int> zigzagLevelOrder(TreeNode *root) {
  vector<int> ans;
  stack<TreeNode *> s_odd;
  stack<TreeNode *> s_even;
  bool odd = true;
  if (root)
    s_odd.push(root);
  while (!s_odd.empty() || !s_even.empty()) {
    vector<int> level;
    while (odd && !s_odd.empty()) {
      TreeNode *now = s_odd.top();
      s_odd.pop();
      level.push_back(now->val);
      if (now->left)
        s_even.push(now->left);
      if (now->right)
        s_even.push(now->right);
    }
    while (!odd && !s_even.empty()) {
      TreeNode *now = s_even.top();
      s_even.pop();
      level.push_back(now->val);
      if (now->right)
        s_odd.push(now->right);
      if (now->left)
        s_odd.push(now->left);
    }
    odd = !odd;
    for (auto x : level) {
      ans.push_back(x);
    }
  }
  return ans;
}
int main() {
  printVec(zigzagLevelOrder(createTree({3, 9, 20, tnull, tnull, 15, 7})));
  return 0;
}
