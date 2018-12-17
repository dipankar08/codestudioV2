/***************************************************
 * Title : Merge from backward in place
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void printVec(vector<int> v) {
  for (auto c : v) {
    cout << c << " ";
  }
  cout << endl;
}
void merge(vector<int> &arr1, vector<int> &arr2) {
  // shift first array
  // {1,2,3,0,0} => {0,0,1,2,3}
  int temp = arr1.size() - arr2.size() - 1;
  while (temp >= 0) {
    arr1[temp + arr2.size()] = arr1[temp];
    arr1[temp] = 0;
    temp--;
  }
  printVec(arr1);
  int i = arr2.size();
  int j = 0;
  int k = 0;
  while (i < arr1.size() && j < arr2.size()) {
    if (arr1[i] < arr2[j]) {
      arr1[k++] = arr1[i++];
    } else {
      arr1[k++] = arr2[j++];
    }
  }
  while (j < arr2.size()) {
    arr1[k++] = arr2[j++];
  }
}
int main() {
  vector<int> arr1 = {10, 20, 30, 50, 0, 0, 0};
  vector<int> arr2 = {5, 15, 40};
  merge(arr1, arr2);
  printVec(arr1);
  return 0;
}
