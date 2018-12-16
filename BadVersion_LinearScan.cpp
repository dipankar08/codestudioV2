/***************************************************
 * Title :
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

// Linear sacn to detect the bad version.
int firstBadVersion(int n) {
  for (int i = 1; i < n; i++) {
    if (isBadVersion(i)) {
      return i;
    }
  }
  return n;
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
