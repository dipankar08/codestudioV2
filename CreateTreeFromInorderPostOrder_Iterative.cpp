/***************************************************
 * Title : Using Recusrion.
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
TreeNode *buildTree(vector<int> inorder, vector<int> postorder) {
  if (inorder.size() == 0 || postorder.size() == 0)
    return nullptr;
  int ip = inorder.size() - 1;
  int pp = postorder.size() - 1;

  stack<TreeNode *> st;
  TreeNode *prev = nullptr;
  TreeNode *root = new TreeNode(postorder[pp]);
  st.push(root);
  pp--;

  while (pp >= 0) {
    while (!st.empty() && st.top()->val == inorder[ip]) {
      prev = st.top();
      st.pop();
      ip--;
    }
    TreeNode *newNode = new TreeNode(postorder[pp]);
    if (prev != nullptr) {
      prev->left = newNode;
    } else if (!st.empty()) {
      TreeNode *currTop = st.top();
      currTop->right = newNode;
    }
    st.push(newNode);
    prev = nullptr;
    pp--;
  }

  return root;
}

int main() {
  printTree(buildTree({9, 3, 15, 20, 7}, {9, 15, 7, 20, 3})); // 3 9 20 15 7
  return 0;
}
