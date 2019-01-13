/***************************************************
 * Title :
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include "utils.h"
#include <iostream>
#include <vector>
using namespace std;
bool validate(TreeNode *node, TreeNode *&prev, int &count) {
  if (node == NULL){
    return true;
  }
  if (!validate(node->left, prev, count)){
    return false;
  }
  if (prev != NULL && prev->val >= node->val){
    return false;
  }
  prev = node;
  ++count;
  return validate(node->right, prev, count);
}
bool isValidBST(TreeNode *root, int &count) {
  count = 0;
  TreeNode *prev = NULL;
  return validate(root, prev, count);
}
int largestBSTSubtree(TreeNode *root) {
  int count = 0;
  if (isValidBST(root, count)) {
    return count;
  } else
    return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
}

int main() {
  TreeNode *root = createTree({10, 5, 15, 1, 8, tnull, 7});
  cout << largestBSTSubtree(root) << endl;
  return 0;
}
