/***************************************************
 * Title : Define Symmetric using iterative using single queue
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include <iostream>
#include <queue>
using namespace std;
bool isSymmetric(TreeNode *root) {
  if (!root) {
    return true;
  }
  queue<pair<TreeNode *, TreeNode *>> q;
  q.push(make_pair(root->left, root->right));
  while (!q.empty()) {
    pair<TreeNode *, TreeNode *> p = q.front();
    q.pop();
    if (!p.first && !p.second) {
      continue;
    }
    if (!p.first || !p.second) {
      return false;
    }
    if (p.first->val != p.second->val) {
      return false;
    }
    q.push(make_pair(p.first->left, p.second->right));
    q.push(make_pair(p.first->right, p.second->left));
  }
  return true;
}
int main() {
  cout << "result:" << isSymmetric(createTree({1, 2, 2, 3, 4, 4, 3})) << endl;
  cout << "result:" << isSymmetric(createTree({1, 2, 2, tnull, 3, tnull, 3}))
       << endl;
  return 0;
}
