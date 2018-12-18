/***************************************************
 * Title : LargestHistogram Problem using Stack
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int largestRectangleArea(vector<int> height) {
  // define the result as 0.
  int ret = 0;
  // adding dummy 0 at the end to fouce the clearup.
  height.push_back(0);
  // we define a stack called index which will store the index of height
  stack<int> indexStack;
  // scan the historgram from left to right
  for (int i = 0; i < height.size(); i++) {
    // Keep poping up the stack elemnet until he got a less height bar
    // In this process - we keep track the maximum result so far.
    while (indexStack.size() > 0 && height[indexStack.top()] >= height[i]) {
      int h = height[indexStack.top()];
      indexStack.pop();
      int sidx = indexStack.size() > 0 ? indexStack.top() : -1;
      if (h * (i - sidx - 1) > ret) {
        ret = h * (i - sidx - 1);
      }
    }
    // at the end put this elment to the stack.
    indexStack.push(i);
  }
  return ret;
}
int main() {
  cout << "result:" << largestRectangleArea({2, 1, 5, 6, 2, 3}) << endl; // 10
  cout << "result:" << largestRectangleArea({6, 2, 5, 4, 5, 1, 6})
       << endl; // 12
  return 0;
}
