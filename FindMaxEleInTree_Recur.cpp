/***************************************************
 * Title :
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include <iostream>
using namespace std;

int findMax(TreeNode *root) {
  if (root == NULL) {
    return INT_MIN;
  }
  int max_left = findMax(root->left);
  int max_right = findMax(root->right);
  return max(max(max_left, max_right), root->val);
}

int main() {
  cout << findMax(createTree({1, 2, 3, 5, 4, 7, 6})) << endl;
  return 0;
}
