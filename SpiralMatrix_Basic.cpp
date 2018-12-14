/***************************************************
 * Title :
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void printSpiralMatrix(vector<vector<int>> mat) {
  int m = mat.size();
  int n = mat[0].size();
  int left = 0, right = n - 1, top = 0, down = m - 1;
  while (1) {
    for (int i = left; i <= right; i++) {
      cout << mat[top][i] << " ";
    }
    top++;
    // middline line left
    if (top > down)
      break;
    for (int i = top; i <= down; i++) {
      cout << mat[i][right] << " ";
    }
    right--;
    // signle vertical line
    if (right < left)
      break;
    for (int i = right; i >= left; i--) {
      cout << mat[down][i] << " ";
    }
    down--;
    for (int i = down; i >= top; i--) {
      cout << mat[i][left] << " ";
    }
    left++;
  }
  cout << endl;
}

int main() {
  printSpiralMatrix(
      {{1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {13, 14, 15, 16, 17, 18}});
}
