/***************************************************
 * Title :
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include "utils.h"
#include <iostream>
#include <vector>
using namespace std;
// return max sum of a dowm path
int helper(TreeNode *root, int &res) {
  if (!root) {
    return 0;
  }
  int left = helper(root->left, res);
  int right = helper(root->right, res);
  left = max(left, 0);
  right = max(right, 0);

  /* sum of path crossing root */
  res = max(res, root->val + left + right);

  return root->val + max(left, right);
}
int maxPathSum(TreeNode *root) {
  int res = INT_MIN;
  helper(root, res);
  return res;
}

int main() {
  cout << "result:" << maxPathSum(createTree({1, 2, 3})) << endl; // 6
  cout << "result:" << maxPathSum(createTree({-10, 9, 20, tnull, tnull, 15, 7}))
       << endl; // 42
  return 0;
}
