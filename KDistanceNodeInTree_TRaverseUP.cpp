/***************************************************
 * Title :
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include "utils.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
// Just find in below Node.s
void getNodesAtDistanceKBelow(TreeNode *root, int K, vector<int> &res) {
  if (!root) {
    return;
  }
  if (K == 0) {
    res.push_back(root->val);
    return;
  }
  getNodesAtDistanceKBelow(root->left, K - 1, res);
  getNodesAtDistanceKBelow(root->right, K - 1, res);
}
// Find in up.
pair<bool, int> getNodesAtDistanceKAbove(TreeNode *root, TreeNode *target,
                                         int K, vector<int> &res) {
  if (!root) {
    return {false, -1};
  }
  if (root == target) {
    return {true, 1};
  }
  auto left = getNodesAtDistanceKAbove(root->left, target, K, res);
  auto right = getNodesAtDistanceKAbove(root->right, target, K, res);
  if (left.first || right.first) {
    int dist = left.first ? left.second : right.second;
    if (dist == K) {
      res.push_back(root->val);
    } else if (dist < K) {
      getNodesAtDistanceKBelow(left.first ? root->right : root->left,
                               K - dist - 1, res);
    }
    return {true, dist + 1};
  }
  return {false, -1};
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
  vector<int> result;
  getNodesAtDistanceKBelow(target, K, result);
  if (root != target && K > 0) {
    getNodesAtDistanceKAbove(root, target, K, result);
  }
  return result;
}
int main() {
  TreeNode *node = createTree({3, 5, 1, 6, 2, 0, 8, tnull, tnull, 7, 4});
  printVec(distanceK(node, node->left, 2)); // 7, 4, 1,
  return 0;
}
