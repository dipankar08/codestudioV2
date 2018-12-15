/***************************************************
 * Title : Min Path Sum using DP
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>> &grid) {
  int m = grid.size();
  int n = grid[0].size();
  // temp 2D array to store the solsution.
  vector<vector<int>> sum(m, vector<int>(n, grid[0][0]));
  // fill first col
  for (int i = 1; i < m; i++) {
    sum[i][0] = sum[i - 1][0] + grid[i][0];
  }
  // fill first first row
  for (int j = 1; j < n; j++) {
    sum[0][j] = sum[0][j - 1] + grid[0][j];
  }
  // compute other values using buttom up
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
    }
  }
  return sum[m - 1][n - 1];
}
int main() {
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  cout << "Min Sum is :" << minPathSum(grid) << endl; // 7
  return 0;
}
