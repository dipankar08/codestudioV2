/***************************************************
 * Title : Uisng passing ref
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include <iostream>
using namespace std;
void findMax2Helper(TreeNode *root, int &result) {
  if (root == NULL)
    return;
  result = max(result, root->val);
  findMax2Helper(root->left, result);
  findMax2Helper(root->right, result);
}

int findMax(TreeNode *root) {
  int result = 0;
  findMax2Helper(root, result);
  return result;
}

int main() {
  cout << findMax(createTree({1, 2, 3, 5, 4, 7, 6})) << endl;
  return 0;
}
