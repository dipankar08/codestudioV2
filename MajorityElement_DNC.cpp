/***************************************************
 * Title : majorityElement DNC
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// Helper recursive function
int majority(vector<int> nums, int left, int right) {
  if (left == right) {
    return nums[left];
  }
  int mid = left + ((right - left) >> 1);
  int lm = majority(nums, left, mid);
  int rm = majority(nums, mid + 1, right);
  if (lm == rm) {
    return lm;
  }
  return count(nums.begin() + left, nums.begin() + right + 1, lm) >
                 count(nums.begin() + left, nums.begin() + right + 1, rm)
             ? lm
             : rm;
}
int majorityElement(vector<int> nums) {
  return majority(nums, 0, nums.size() - 1);
}

int main() {
  cout << "result:" << majorityElement({3, 3, 4, 2, 4, 4, 2, 4, 4}) << endl;
  cout << "result:" << majorityElement({3, 3, 4, 2, 4, 4, 2, 4}) << endl;
  return 0;
}
