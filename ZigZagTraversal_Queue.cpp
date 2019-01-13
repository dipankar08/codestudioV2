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
  vector<int> res;
  bool left2right = true;
  queue<TreeNode *> q;
  if (root) {
    q.push(root);
  }
  while (!q.empty()) {
    int sz = q.size();
    vector<int> level(sz);
    for (int i = 0; i < sz; i++) {
      TreeNode *node = q.front();
      q.pop();
      left2right ? level[i] = node->val : level[sz - 1 - i] = node->val;
      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
    }
    for (auto x : level) {
      res.push_back(x);
    }
    left2right ^= 1;
  }
  return res;
}
int main() {
  printVec(zigzagLevelOrder(createTree({3, 9, 20, tnull, tnull, 15, 7})));
  return 0;
}
