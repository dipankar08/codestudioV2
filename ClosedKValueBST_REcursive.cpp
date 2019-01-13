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
void closestKValues(TreeNode *root, double target, int k,
                    priority_queue<pair<double, int>> &pq) {
  if (!root)
    return;

  double diff = abs(target - root->val);
  pq.push(make_pair(diff, root->val));
  if (pq.size() > k){
    pq.pop();
  }
  closestKValues(root->left, target, k, pq);
  closestKValues(root->right, target, k, pq);
}
vector<int> closestKValues(TreeNode *root, double target, int k) {
  priority_queue<pair<double, int>> pq;

  closestKValues(root, target, k, pq);
  vector<int> result;
  while (!pq.empty()) {
    result.emplace_back(pq.top().second);
    pq.pop();
  }
  return result;
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
