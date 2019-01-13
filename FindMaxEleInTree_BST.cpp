/***************************************************
 * Title :
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include <iostream>
using namespace std;
// We have used a global veriable.
static int maxval = INT_MIN;
void findMax(TreeNode *root) {
  if (root == NULL)
    return;
  findMax(root->left);
  findMax(root->right);
  maxval = max(maxval, root->val);
}

int main() {
  findMax(createTree({1, 2, 3, 4, 5, 6, 7}));
  cout << maxval << endl;
  return 0;
}
