/***************************************************
 * Title : Tree related DS
 * Author: Dipankar Dutta
 ****************************************************/
#include <iostream>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printTreeHelper(TreeNode *root) {
  if (root == NULL) {
    return;
  }
  cout << root->val << " ";
  printTreeHelper(root->left);
  printTreeHelper(root->right);
}
void printTree(TreeNode *root) {
  cout << "Tree(Inorder):" << endl;
  printTreeHelper(root);
  cout << endl;
}
