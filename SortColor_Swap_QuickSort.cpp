/***************************************************
 * Title : Couting sort
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums) {
  int tmp = 0, low = 0, mid = 0, high = nums.size() - 1;
  // We are scaning the array from left to right with pointer mid
  while (mid <= high) {
    // if mid meets a zero, swap with low and incremenet low.
    if (nums[mid] == 0) {
      tmp = nums[low];
      nums[low] = nums[mid];
      nums[mid] = tmp;
      low++;
      mid++;
    } else if (nums[mid] == 1) {
      // if mid meets a one, it just proceeds.
      mid++;
    } else if (nums[mid] == 2) {
      // if mid meets a two, it swap with high(2) and decremnet high.
      tmp = nums[high];
      nums[high] = nums[mid];
      nums[mid] = tmp;
      high--;
    }
  }
}

int main() {
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  sortColors(nums);
  for (int n : nums) {
    cout << n << " ";
  }
  cout << endl;
  return 0;
}
