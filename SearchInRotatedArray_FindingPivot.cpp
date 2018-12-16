/***************************************************
 * Title : Find Pivot and then do binary serach.
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int search(vector<int> A, int target) {
  int low = 0, high = A.size() - 1;
  // find the index of the smallest value using binary search.
  // lowop will terminate since mid < hi, and low or high will shrink by at
  // least 1. Proof by contradiction that mid < hi: if mid==hi, then low==high
  // and lowop would have been terminated.
  while (low < high) {
    int mid = (low + high) / 2;
    if (A[mid] > A[high])
      low = mid + 1;
    else
      high = mid;
  }
  // low == high is the index of the smallest value and also the number of
  // places rotated.
  int rot = low;
  low = 0;
  high = A.size() - 1;
  // The usual binary search and accounting for rotation.
  while (low <= high) {
    int mid = (low + high) / 2;
    int realmid = (mid + rot) % A.size();
    if (A[realmid] == target) {
      return realmid;
    }
    if (A[realmid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
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
