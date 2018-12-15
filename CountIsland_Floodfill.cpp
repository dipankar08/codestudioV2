/***************************************************
 * Title :
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void expand(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i,
            int j) {
  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
    return;
  }
  if (grid[i][j] == 1 && !visited[i][j]) {
    visited[i][j] = true;
    expand(grid, visited, i + 1, j);
    expand(grid, visited, i, j + 1);
    expand(grid, visited, i - 1, j);
    expand(grid, visited, i, j - 1);
  }
}

int numIslands(vector<vector<int>> &grid) {
  if (grid.empty())
    return 0;
  int row = grid.size();
  int col = grid[0].size();
  vector<vector<bool>> visited(row, vector<bool>(col, false));
  int ret = 0;
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) {
      if (!visited[i][j] && grid[i][j] == 1) {
        ret++;
        expand(grid, visited, i, j);
      }
    }
  return ret;
}
int main() {
  vector<vector<int>> grid = {
      {1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 1}};
  cout << "numIslands is: " << numIslands(grid) << endl;
  return 0;
}
