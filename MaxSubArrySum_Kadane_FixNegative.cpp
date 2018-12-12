/***************************************************
 * Title : Two Sum Using HashMap
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int MaxSubArraySum(vector<int> arr) {
  // find maximum element present in given array
  int max_num = *(std::max_element(arr.begin(), arr.end()));
  // if array contains all negative values, return maximum element
  if (max_num < 0) {
    return max_num;
  }
  // same code as before
  int max_so_far = 0;
  int max_ending_here = 0;
  for (int i = 0; i < arr.size(); i++) {
    max_ending_here = max_ending_here + arr[i];
    max_ending_here = max(max_ending_here, 0);
    max_so_far = max(max_so_far, max_ending_here);
  }
  return max_so_far;
}
int main() {
  cout << "result:" << MaxSubArraySum({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << endl;
  cout << "result:" << MaxSubArraySum({-1, -2, -3, -4}) << endl; // not works
  return 0;
}
