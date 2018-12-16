/***************************************************
 * Title : Using Modified Binary search
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int search(vector<int> nums, int target) {
  int start = 0;
  int end = nums.size() - 1;
  while (start <= end) {
    int mid = (start + end) / 2;
    if (target == nums[mid]) {
      return mid;
    }
    // [start...mid] is sorted
    if (nums[start] <= nums[mid]) {
      // target lies in [start...mid]
      if (target >= nums[start] && target < nums[mid]) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    } else { // [mid ...end] is sorted
      // target lies in [mid..end]
      if (target > nums[mid] && target <= nums[end]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
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
