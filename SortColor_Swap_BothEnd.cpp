/***************************************************
 * Title : Swap both ends
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void sortColors(vector<int> &A) {
  int second = A.size() - 1, zero = 0;
  for (int i = 0; i <= second; i++) {
    // We just pushing 2 at the end
    while (A[i] == 2 && i < second) {
      swap(A[i], A[second--]);
    }
    // just keep pushing zero at the begining.
    while (A[i] == 0 && i > zero) {
      swap(A[i], A[zero++]);
    };
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
