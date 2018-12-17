/***************************************************
 * Title : K-th Smallest by applying invariants
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int kth(vector<int> arr1, vector<int> arr2, int k) {
  if (arr1.size() + arr2.size() < k) {
    return -1;
  }
  // define the serach space for i
  int iMin = 0;
  int iMax = min((int)arr1.size(), k - 1);

  int i = 0;
  int j = 0;
  while (iMin <= iMax) {
    // note that we are applying as binary search to find the right i
    // then from i, we have tried to find right j
    i = (iMin + iMax) / 2;
    j = k - 1 - i; // because of zero based index
    if (arr2[j - 1] > arr1[i]) {
      // i is too small, must increase it
      iMin = i + 1;
    } else if (i > 0 && arr1[i - 1] > arr2[j]) {
      // i is too big, must decrease it
      iMax = i - 1;
    } else {
      // i is perfect
      return min(arr1[i], arr2[j]);
    }
  }
  return -1;
}

int main() {
  cout << kth({2, 3, 6, 7, 9}, {1, 4, 8, 10}, 5) << endl;          // 6
  cout << kth({10, 20, 40, 60}, {15, 35, 50, 70, 100}, 4) << endl; // 35
  return 0;
}
