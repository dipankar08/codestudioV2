/***************************************************
 * Title : LargestHistogram Problem using DAC
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int maxCombineArea(const vector<int> &height, int s, int m, int e) {
  // Expand from the middle to find the max area containing height[m] and
  // height[m+1]
  int i = m, j = m + 1;
  int area = 0, h = min(height[i], height[j]);
  while (i >= s && j <= e) {
    h = min(h, min(height[i], height[j]));
    area = max(area, (j - i + 1) * h);
    if (i == s) {
      ++j;
    } else if (j == e) {
      --i;
    } else {
      // if both sides have not reached the boundary,
      // compare the outer bars and expand towards the bigger side
      if (height[i - 1] > height[j + 1]) {
        --i;
      } else {
        ++j;
      }
    }
  }
  return area;
}
int maxAreaUtils(const vector<int> &height, int s, int e) {
  // if the range only contains one bar, return its height as area
  if (s == e) {
    return height[s];
  }
  // otherwise, divide & conquer, the max area must be among the following 3
  // values
  int m = s + (e - s) / 2;
  // 1 - max area from left half
  int area = maxAreaUtils(height, s, m);
  // 2 - max area from right half
  area = max(area, maxAreaUtils(height, m + 1, e));
  // 3 - max area across the middle
  area = max(area, maxCombineArea(height, s, m, e));
  return area;
}

int largestRectangleArea(vector<int> height) {
  if (height.empty()) {
    return 0;
  }
  return maxAreaUtils(height, 0, height.size() - 1);
}

int main() {
  cout << "result:" << largestRectangleArea({2, 1, 5, 6, 2, 3}) << endl; // 10
  cout << "result:" << largestRectangleArea({6, 2, 5, 4, 5, 1, 6})
       << endl; // 12
  return 0;
}
