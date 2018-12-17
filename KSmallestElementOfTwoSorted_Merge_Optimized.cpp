/***************************************************
 * Title : K-th Smallest without actual merge
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int kth(vector<int> arr1, vector<int> arr2, int k) {
  int i = 0, j = 0;
  while (1) {
    if (arr1[i] > arr2[j]) {
      if (i + j == k) {
        return arr2[j];
      }
      j++;
    } else if (arr1[i] < arr2[j]) {
      if (i + j == k) {
        return arr1[j];
      }
      i++;
    } else { //(arr1[i]==arr2[j])
      if (i + j == k) {
        return arr2[i];
      }
      i++;
      j++;
      k++;
    }
  }
}

int main() {
  cout << kth({2, 3, 6, 7, 9}, {1, 4, 8, 10}, 5) << endl; // 6
  return 0;
}
