/***************************************************
 * Title : K-th Smallest using DAC
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int kthUtil(vector<int> arr1, vector<int> arr2, int start1, int end1,
            int start2, int end2, int k) {
  if (start1 == end1) {
    return arr2[k];
  }
  if (start2 == end2) {
    return arr1[k];
  }
  int mid1 = (end1 - start1) / 2;
  int mid2 = (end2 - start2) / 2;
  if (mid1 + mid2 < k) {
    if (arr1[mid1] > arr2[mid2]) {
      return kthUtil(arr1, arr2, start1, end1, mid2 + 1, end2, k - mid2 - 1);
    } else {
      return kthUtil(arr1, arr2, mid1 + 1, end1, start2, end2, k - mid1 - 1);
    }
  } else {
    if (arr1[mid1] > arr2[mid2]) {
      return kthUtil(arr1, arr2, start1, mid1, start2, end2, k);
    } else {
      return kthUtil(arr1, arr2, start1, end1, start2, mid2, k);
    }
  }
}

int kth(vector<int> arr1, vector<int> arr2, int k) {
  return kthUtil(arr1, arr2, 0, arr1.size() - 1, 0, arr2.size() - 1, k);
}

int main() {
  cout << kth({2, 3, 6, 7, 9}, {1, 4, 8, 10}, 5) << endl;          // 6
  cout << kth({10, 20, 40, 60}, {15, 35, 50, 70, 100}, 4) << endl; // 35
  cout << kth({2}, {1}, 2) << endl; // NOT WORKS. Can you fix it ?
  return 0;
}
