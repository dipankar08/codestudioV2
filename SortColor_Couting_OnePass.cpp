/***************************************************
 * Title : Couting sort
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void sortColors(vector<int> &A) {
  int n0 = -1, n1 = -1, n2 = -1;
  for (int i = 0; i < A.size(); ++i) {
    if (A[i] == 0) {
      A[++n2] = 2;
      A[++n1] = 1;
      A[++n0] = 0;
    } else if (A[i] == 1) {
      A[++n2] = 2;
      A[++n1] = 1;
    } else if (A[i] == 2) {
      A[++n2] = 2;
    }
  }
}
int main() {
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  sortColors(nums);
  for (int n : nums) {
    cout << n << " ";
  }
  cout << endl;
  return 0;
}
