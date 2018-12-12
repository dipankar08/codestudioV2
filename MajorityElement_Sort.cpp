/***************************************************
 * Title : majorityElement Basic
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// This solution will  only works if there is a majority.
int majorityElement(vector<int> nums) {
  nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
  return nums[nums.size() / 2];
}
int main() {
  cout << "result:" << majorityElement({3, 3, 4, 2, 4, 4, 2, 4, 4}) << endl;
  cout << "result:" << majorityElement({3, 3, 4, 2, 4, 4, 2, 4}) << endl;
  return 0;
}
