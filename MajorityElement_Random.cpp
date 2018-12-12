/***************************************************
 * Title : majorityElement Vote
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int majorityElement(vector<int> nums) {
  int n = nums.size();
  srand(unsigned(time(NULL)));
  while (true) {
    int idx = rand() % n;
    int candidate = nums[idx];
    int counts = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == candidate) {
        counts++;
      }
    }
    if (counts > n / 2) {
      return candidate;
    }
  }
}
int main() {
  cout << "result:" << majorityElement({3, 3, 4, 2, 4, 4, 2, 4, 4}) << endl;
  // cout << "result:" << majorityElement({3, 3, 4, 2, 4, 4, 2, 4}) << endl; //
  // this will fall INF loop
  return 0;
}
