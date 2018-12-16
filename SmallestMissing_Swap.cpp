/***************************************************
 * Title : Two Scan approch with Swap
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int firstMissingPositive(vector<int> A) {
  for (int i = 0; i < A.size(); ++i) {
    while (A[i] > 0 && A[i] <= A.size() && A[A[i] - 1] != A[i]) {
      swap(A[i], A[A[i] - 1]);
    }
  }

  for (int i = 0; i < A.size(); ++i) {
    if (A[i] != i + 1) {
      return i + 1;
    }
  }

  return A.size() + 1;
}
int main() {
  cout << "result:" << firstMissingPositive({1, 2, 0}) << endl;
  cout << "result:" << firstMissingPositive({3, 4, -1, 1}) << endl;
  cout << "result:" << firstMissingPositive({7, 8, 9, 11, 12}) << endl;
  return 0;
}
