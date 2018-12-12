/***************************************************
 * Title : majorityElement Vote
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int findCandidate(vector<int> a) {
  int maj_index = 0, count = 1;
  for (int i = 1; i < a.size(); i++) {
    if (a[maj_index] == a[i]) {
      count++;
    } else {
      count--;
    }
    if (count == 0) {
      maj_index = i;
      count = 1;
    }
  }
  return a[maj_index];
}

bool isMajority(vector<int> a, int cand) {
  int count = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == cand) {
      count++;
    }
  }
  if (count > a.size() / 2) {
    return 1;
  } else {
    return 0;
  }
}
int majorityElement(vector<int> nums) {
  int cand = findCandidate(nums);
  if (isMajority(nums, cand)) {
    return cand;
  } else {
    return -1;
  }
}
int main() {
  cout << "result:" << majorityElement({3, 3, 4, 2, 4, 4, 2, 4, 4}) << endl;
  cout << "result:" << majorityElement({3, 3, 4, 2, 4, 4, 2, 4}) << endl;
  return 0;
}
