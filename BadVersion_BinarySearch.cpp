/***************************************************
 * Title : Binary Serach
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// helper
int v1 = 100;
bool isBadVersion(int i) {
  if (i < v1) {
    return false;
  } else {
    return true;
  }
}

// Binary serach
int firstBadVersion(int n) {
  int left = 1;
  int right = n;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (isBadVersion(mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

// test
int main() {
  v1 = 100; // set the bad verstion at 100
  cout << "result:" << firstBadVersion(100) << endl;
  v1 = 0; // set the bad version to 50
  cout << "result:" << firstBadVersion(100) << endl;
  v1 = 71; // set the bad version to 71
  cout << "result:" << firstBadVersion(100) << endl;
  return 0;
}
