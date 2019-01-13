/***************************************************
 * Title : Uisng Fwd and Rev Iteraraion
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include "utils.h"
#include <cmath>
#include <iostream>
#include <stack>
using namespace std;
void inOrder(TreeNode *root, double target, bool reverse, stack<int> &order) {
  if (root == NULL)
    return;
  inOrder(reverse ? root->right : root->left, target, reverse, order);
  if ((reverse && root->val <= target) || (!reverse && root->val > target))
    return;
  order.push(root->val);
  inOrder(reverse ? root->left : root->right, target, reverse, order);
}
vector<int> closestKValues(TreeNode *root, double target, int k) {
  vector<int> results;
  stack<int> incr, decr;
  inOrder(root, target, false, incr);
  inOrder(root, target, true, decr);
  while (results.size() < k) {
    if (incr.empty()) {
      results.push_back(decr.top());
      decr.pop();
    } else if (decr.empty()) {
      results.push_back(incr.top());
      incr.pop();
    } else if (abs(incr.top() - target) < abs(decr.top() - target)) {
      results.push_back(incr.top());
      incr.pop();
    } else {
      results.push_back(decr.top());
      decr.pop();
    }
  }
  return results;
}

int main() {
  TreeNode *root = new TreeNode(9);
  root->left = new TreeNode(4);
  root->right = new TreeNode(17);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(6);
  root->left->right->left = new TreeNode(5);
  root->left->right->right = new TreeNode(7);
  root->right->right = new TreeNode(22);
  root->right->right->left = new TreeNode(20);
  printVec(closestKValues(root, 4, 3));  // 3.4.5
  printVec(closestKValues(root, 18, 3)); // 17,20, 22
  printVec(closestKValues(root, 12, 3)); // 9,7,17

  return 0;
}
