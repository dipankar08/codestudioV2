/***************************************************
 * Title : Min Path Sum
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int minValue = 999;
void minPathSumHelper(int r /*row*/, int c /*colum*/, int m, int n, int curSum,
                      vector<vector<int>> &grid) {
  if (r > m - 1 || c > n - 1) {
    return;
  }
  curSum += grid[r][c];
  if (r == m - 1 && c == n - 1) {
    if (curSum < minValue) {
      minValue = curSum;
    }
    return;
  }
  if (curSum > minValue) {
    return;
  }
  minPathSumHelper(r + 1, c, m, n, curSum, grid);
  minPathSumHelper(r, c + 1, m, n, curSum, grid);
}

int minPathSum(vector<vector<int>> &grid) {
  if (grid.size() == 0) {
    return 0;
  }
  int m = grid.size();
  int n = grid[0].size();
  minPathSumHelper(0, 0, m, n, 0, grid);
  return minValue;
}
int main() {
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  cout << "Min Sum is :" << minPathSum(grid) << endl; // 7
  return 0;
}
