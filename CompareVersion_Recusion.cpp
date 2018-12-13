/***************************************************
 * Title : extractNum
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int versionCompareUtil(string &v1, string &v2, int i1, int i2) {
  int n1 = 0, n2 = 0;
  // both string ends
  if (i1 >= v1.size() && i2 >= v2.size()) {
    return 0;
  }
  int j1 = i1, j2 = i2;
  // find next number for v1
  while (j1 < v1.size() && v1[j1] != '.') {
    n1 = 10 * n1 + v1[j1++] - '0';
  }
  // find next major for v2
  while (j2 < v2.size() && v2[j2] != '.') {
    n2 = 10 * n2 + v2[j2++] - '0';
  }
  // just compare
  if (n1 > n2) {
    return 1;
  } else if (n1 < n2) {
    return -1;
  } else {
    return versionCompareUtil(v1, v2, ++j1, ++j2);
  }
}
int versionCompare(string version1, string version2) {
  return versionCompareUtil(version1, version2, 0, 0);
}
int main() {
  cout << versionCompare("1.10", "1.11") << endl; //-1
  cout << versionCompare("1.11", "1.10") << endl; // 1
  cout << versionCompare("1.10", "1.10") << endl; // 0
}
