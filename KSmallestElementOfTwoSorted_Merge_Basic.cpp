/***************************************************
 * Title : K-th Smallest with merge
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int kth(vector<int> arr1, vector<int> arr2, int k) {
  vector<int> sorted1(arr1.size() + arr2.size());
  int i = 0, j = 0, d = 0;
  while (i < arr1.size() && j < arr2.size()) {
    if (arr1[i] < arr2[j]) {
      sorted1[d++] = arr1[i++];
    } else {
      sorted1[d++] = arr2[j++];
    }
  }
  while (i < arr1.size()) {
    sorted1[d++] = arr1[i++];
  }
  while (j < arr2.size()) {
    sorted1[d++] = arr2[j++];
  }
  return sorted1[k - 1];
}

int main() {
  cout << kth({2, 3, 6, 7, 9}, {1, 4, 8, 10}, 5) << endl; // 6
  return 0;
}
