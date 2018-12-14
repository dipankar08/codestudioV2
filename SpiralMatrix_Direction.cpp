/***************************************************
 * Title :
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void printSpiralMatrix(vector<vector<int>> matrix) {
  vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int nr = matrix.size();
  if (nr == 0)
    return;
  int nc = matrix[0].size();
  if (nc == 0)
    return;

  vector<int> nSteps{nc, nr - 1};

  int iDir = 0;        // index of direction.
  int ir = 0, ic = -1; // initial position
  while (nSteps[iDir % 2]) {
    for (int i = 0; i < nSteps[iDir % 2]; ++i) {
      ir += dirs[iDir][0];
      ic += dirs[iDir][1];
      cout << matrix[ir][ic] << " ";
    }
    nSteps[iDir % 2]--;
    iDir = (iDir + 1) % 4;
  }
  cout << endl;
}

int main() {
  printSpiralMatrix(
      {{1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {13, 14, 15, 16, 17, 18}});
}
