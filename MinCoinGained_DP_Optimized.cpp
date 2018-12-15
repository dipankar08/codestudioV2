/***************************************************
 * Title : Min Path Sum using DP Optimzed
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>> &grid) {
  int m = grid.size();
  int n = grid[0].size();

  // Define one D Array
  vector<int> sum(n, 0);
  sum[0] = grid[0][0];

  // set the first row
  for (int i = 1; i < n; i++) {
    sum[i] = sum[i - 1] + grid[0][i];
  }
  // calculate the value for other rows
  for (int i = 1; i < m; i++) {
    sum[0] = sum[0] + grid[i][0];
    for (int j = 1; j < n; j++) {
      sum[j] = min(sum[j], sum[j - 1]) + grid[i][j];
    }
  }
  return sum[n - 1];
}

int main() {
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  cout << "Min Sum is :" << minPathSum(grid) << endl; // 7
  return 0;
}
