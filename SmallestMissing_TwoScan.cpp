/***************************************************
 * Title : Two Scan approch
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int> A) {
  // pass 1
  for (int i = 0; i < A.size(); i++) {
    int pick = A[i];
    while (pick > 0 && pick <= A.size() && A[pick - 1] != pick) {
      int tmp = A[pick - 1];
      A[pick - 1] = pick;
      pick = tmp;
    }
  }
  // pass 2
  for (int i = 0; i < A.size(); i++) {
    if (A[i] != i + 1)
      return i + 1;
  }
  return A.size() + 1;
}

int main() {
  cout << "result:" << firstMissingPositive({1, 2, 0}) << endl;
  cout << "result:" << firstMissingPositive({3, 4, -1, 1}) << endl;
  cout << "result:" << firstMissingPositive({7, 8, 9, 11, 12}) << endl;
  return 0;
}
