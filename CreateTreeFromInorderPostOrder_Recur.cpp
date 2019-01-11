/***************************************************
 * Title : Using Recusrion.
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include <iostream>
#include <vector>
using namespace std;
TreeNode *create(vector<int> &inorder, vector<int> &postorder, int is, int ie,
                 int ps, int pe) {
  if (ps > pe) {
    return nullptr;
  }
  TreeNode *node = new TreeNode(postorder[pe]);
  int pos;
  for (int i = is; i <= ie; i++) {
    if (inorder[i] == node->val) {
      pos = i;
      break;
    }
  }
  node->left = create(inorder, postorder, is, pos - 1, ps, ps + pos - is - 1);
  node->right = create(inorder, postorder, pos + 1, ie, pe - ie + pos, pe - 1);
  return node;
}
TreeNode *buildTree(vector<int> inorder, vector<int> postorder) {
  return create(inorder, postorder, 0, inorder.size() - 1, 0,
                postorder.size() - 1);
}

int main() {
  printTree(buildTree({9, 3, 15, 20, 7}, {9, 15, 7, 20, 3})); //
  return 0;
}
