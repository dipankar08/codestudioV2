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
map<int, vector<int>> edge;
vector<int> ans;
void dfs(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  if (root->left != nullptr) {
    dfs(root->left);
    edge[root->val].push_back(root->left->val);
    edge[root->left->val].push_back(root->val);
  }
  if (root->right != nullptr) {
    dfs(root->right);
    edge[root->val].push_back(root->right->val);
    edge[root->right->val].push_back(root->val);
  }
}
// Traverse from the node and find all the k distance as it is undireted one.
void dfs2(int u, int fa, int dep, int K) {
  if (dep == K) {
    ans.push_back(u);
    return;
  }
  for (int i = 0; i < edge[u].size(); ++i) {
    int v = edge[u][i];
    if (v == fa)
      continue;
    dfs2(v, u, dep + 1, K);
  }
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
  // builds the undirceted graph by strong the edges.
  dfs(root);
  dfs2(target->val, -1, 0, K);
  return ans;
}

int main() {
  TreeNode *node = createTree({3, 5, 1, 6, 2, 0, 8, tnull, tnull, 7, 4});
  printVec(distanceK(node, node->left, 2)); // 7, 4, 1,
  return 0;
}
