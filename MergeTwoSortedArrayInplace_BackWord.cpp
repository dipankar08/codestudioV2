/***************************************************
 * Title : Merge from backward in place
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr1, vector<int> &arr2) {
  // k indiacte the index of output from the end
  // i points the last index of arr1
  // j points the last index of arr2
  int k = arr1.size() - 1; // arr1 is the full array
  int j = arr2.size() - 1;
  int i = arr1.size() - arr2.size() - 1;
  while (i >= 0 && j >= 0) {
    if (arr1[i] > arr2[j]) {
      arr1[k--] = arr1[i--];
    } else {
      arr1[k--] = arr2[j--];
    }
  }
  while (j >= 0) {
    arr1[k--] = arr2[j--];
  }
}
int main() {
  vector<int> arr1 = {10, 20, 30, 0, 0, 0};
  vector<int> arr2 = {5, 15, 40};
  merge(arr1, arr2);
  for (int i : arr1) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
