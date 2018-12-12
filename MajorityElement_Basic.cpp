/***************************************************
 * Title : majorityElement Basic
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int majorityElement(vector<int> nums) {
  int maxCount = 0;
  int index = -1;
  for (int i = 0; i < nums.size(); i++) {
    int count = 0;
    for (int j = 0; j < nums.size(); j++) {
      if (nums[i] == nums[j])
        count++;
    }
    if (count > nums.size() / 2) {
      return nums[i];
    }
  }
  return -1;
}
int main() {
  cout << "result:" << majorityElement({3, 3, 4, 2, 4, 4, 2, 4, 4}) << endl;
  cout << "result:" << majorityElement({3, 3, 4, 2, 4, 4, 2, 4}) << endl;
  return 0;
}
