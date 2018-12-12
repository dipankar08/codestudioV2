/***************************************************
 * Title : majorityElement Basic
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int majorityElement(vector<int> nums) {
  unordered_map<int, int> counts;
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    if (++counts[nums[i]] > n / 2) {
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
