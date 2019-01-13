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
  vector<int> result;
  if (!root) {
    return result;
  }
  deque<TreeNode *> tree;
  tree.push_back(root);
  int flag = 0;
  while (!tree.empty()) {
    int count = tree.size();
    vector<int> level;
    while (count-- > 0) {
      TreeNode *cur = tree.front();
      tree.pop_front();
      level.push_back(cur->val);
      if (cur->left) {
        tree.push_back(cur->left);
      }
      if (cur->right) {
        tree.push_back(cur->right);
      }
    }
    if (flag & 1) {
      reverse(level.begin(), level.end());
    }
    for (auto x : level) {
      result.push_back(x);
    }
    flag++;
  }
  return result;
}
int main() {
  printVec(zigzagLevelOrder(createTree({3, 9, 20, tnull, tnull, 15, 7})));
  return 0;
}
