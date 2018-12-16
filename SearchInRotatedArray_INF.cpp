/***************************************************
 * Title : Simple Replace INF
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define INFINITY 9999
int search(vector<int> nums, int target) {
  int lo = 0, hi = nums.size();
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    double num = (nums[mid] < nums[0]) == (target < nums[0])
                     ? nums[mid]
                     : target < nums[0] ? -INFINITY : INFINITY;
    if (num < target) {
      lo = mid + 1;
    } else if (num > target) {
      hi = mid;
    } else {
      return mid;
    }
  }
  return -1;
}
int main() {
  cout << "Result:" << search({5, 6, 7, 8, 9, 10, 1, 2, 3}, 3) << endl;
  cout << "Result:" << search({5, 6, 7, 8, 9, 10, 1, 2, 3}, 5) << endl;
  cout << "Result:" << search({5, 6, 7, 8, 9, 10, 1, 2, 3}, 10) << endl;
  cout << "Result:" << search({5, 6, 7, 8, 9, 10, 1, 2, 3}, 1) << endl;
  cout << "Result:" << search({5, 6, 7, 8, 9, 10, 1, 2, 3}, 20) << endl;
  return 0;
}
