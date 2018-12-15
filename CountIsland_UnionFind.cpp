/***************************************************
 * Title :
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/* Union find on Grid DS */
class UnionFind {
private:
  vector<int> father;
  int m, n;
  int count = 0;

public:
  UnionFind(vector<vector<int>> grid) {
    m = grid.size();
    n = grid[0].size();
    father.resize(m * n);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          int id = i * n + j;
          father[id] = id;
          count++;
        }
      }
    }
  }
  void union1(int node1, int node2) {
    int find1 = find(node1);
    int find2 = find(node2);
    if (find1 != find2) {
      father[find1] = find2;
      count--;
    }
  }
  int find(int node) {
    if (father[node] == node) {
      return node;
    }
    father[node] = find(father[node]);
    return father[node];
  }
  int getCount() { return count; }
};

int numIslands(vector<vector<int>> grid) {
  vector<vector<int>> distance = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  if (grid.size() == 0 || grid[0].size() == 0) {
    return 0;
  }
  UnionFind uf = UnionFind(grid);
  int rows = grid.size();
  int cols = grid[0].size();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (grid[i][j] == 1) {
        for (vector<int> d : distance) {
          int x = i + d[0];
          int y = j + d[1];
          if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1) {
            int id1 = i * cols + j;
            int id2 = x * cols + y;
            uf.union1(id1, id2);
          }
        }
      }
    }
  }
  return uf.getCount();
}

int main() {
  vector<vector<int>> grid = {
      {1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 1}};
  cout << "numIslands is: " << numIslands(grid) << endl;
  return 0;
}
