/***************************************************
 * Title : Two Sum Example
 * Author: Dipankar Dutta
 ****************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void twoSum(vector<int> arr, int k) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[i] + arr[j] == k) {
        cout << "Found :" << arr[i] << " + " << arr[j] << ": " << k << endl;
      }
    }
  }
}

int main() {
  twoSum({3, 2, 4, 1}, 5);
  twoSum({3, 2, 4, 1}, 10);
}
