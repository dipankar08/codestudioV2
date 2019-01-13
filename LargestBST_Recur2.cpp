/***************************************************
 * Title :
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include "utils.h"
#include <iostream>
#include <vector>
using namespace std;
// hold the return value.
class Result {
public:
  int size;
  int maxVal;
  int minVal;
  Result(int s, int maxv, int minv) : size(s), maxVal(maxv), minVal(minv) {}
};
Result *helper(TreeNode *root, int &res) {
  if (!root) {
    return new Result(0, INT_MIN, INT_MAX);
  }
  Result *leftResult = helper(root->left, res);
  Result *rightResult = helper(root->right, res);

  if (leftResult->size == -1 || leftResult->maxVal >= root->val ||
      rightResult->size == -1 || rightResult->minVal <= root->val) {
    return new Result(-1, 0, 0);
  }
  int cnt = 1 + leftResult->size + rightResult->size;
  res = max(res, cnt);
  return new Result(cnt, max(rightResult->maxVal, root->val),
                    min(root->val, leftResult->minVal));
}
int largestBSTSubtree(TreeNode *root) {
  int res = 0;
  helper(root, res);
  return res;
}

int main() {
  TreeNode *root = createTree({10, 5, 15, 1, 8, tnull, 7});
  cout << largestBSTSubtree(root) << endl;
  return 0;
}
