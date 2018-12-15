/***************************************************
 * Title : Sample Flood fill algo
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void floodFillUtil(vector<vector<int>> &screen, int x, int y, int prevC,
                   int newC) {
  int m = screen.size();
  int n = screen[0].size();
  // check out of bound
  if (x < 0 || x >= m || y < 0 || y >= n) {
    return;
  }
  // DONOT expand of it is not the previous color.
  if (screen[x][y] != prevC) {
    return;
  }

  screen[x][y] = newC;

  // Recur for north, east, south and west
  floodFillUtil(screen, x + 1, y, prevC, newC);
  floodFillUtil(screen, x - 1, y, prevC, newC);
  floodFillUtil(screen, x, y + 1, prevC, newC);
  floodFillUtil(screen, x, y - 1, prevC, newC);
}

void floodFill(vector<vector<int>> &screen, int x, int y, int newC) {
  int prevC = screen[x][y];
  floodFillUtil(screen, x, y, prevC, newC);
}

void print(vector<vector<int>> screen) {
  cout << "Maze is :" << endl;
  for (int i = 0; i < screen.size(); i++) {
    for (int j = 0; j < screen[0].size(); j++) {
      cout << screen[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  vector<vector<int>> screen = {
      {1, 1, 1, 1}, {0, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 1}};
  print(screen);
  floodFill(screen, 0, 0, 2);
  print(screen);
}
