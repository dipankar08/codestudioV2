/***************************************************
 * Title : Two Sum Using HashMap
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int MaxSubArraySum(vector<int> arr) {
  // stores maximum sum sub-array found so far
  int max_so_far = 0;
  // stores maximum sum of sub-array ending at current position
  int max_ending_here = 0;
  // traverse the given array
  for (int i = 0; i < arr.size(); i++) {
    // update maximum sum of sub-array "ending" at index i
    max_ending_here = max_ending_here + arr[i];
    // if maximum sum is negative, set it to 0
    max_ending_here = max(max_ending_here, 0);
    // update result if current sub-array sum is found to be greater
    max_so_far = max(max_so_far, max_ending_here);
  }
  return max_so_far;
}
int main() {
  cout << "result:" << MaxSubArraySum({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << endl;
  cout << "result:" << MaxSubArraySum({-1, -2, -3, -4}) << endl; // not works
  return 0;
}
