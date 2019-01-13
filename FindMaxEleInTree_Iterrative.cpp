/***************************************************
 * Title : Iterative
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include <iostream>
#include <queue>
using namespace std;

int findMax(TreeNode *root) {
  int result = INT_MIN;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *temp = q.front();
    q.pop();
    result = max(result, temp->val);
    if (temp->left) {
      q.push(temp->left);
    }
    if (temp->right) {
      q.push(temp->right);
    }
  }
  return result;
}

int main() {
  cout << findMax(createTree({1, 2, 3, 5, 4, 7, 6})) << endl;
  return 0;
}
