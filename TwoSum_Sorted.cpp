/***************************************************
 * Title : Two Sum Using HashMap
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void twoSum(vector<int> numbers, int target) {
  // You need to sort it first.
  std::sort(numbers.begin(), numbers.end());
  int i = 0, j = numbers.size() - 1;
  while (i < j) {
    int sum = numbers[i] + numbers[j];
    if (sum == target) {
      cout << "Found" << endl;
      return;
    } else if (sum > target) {
      j--;
    } else {
      i++;
    }
  }
  cout << "Not found" << endl;
}

int main() {
  twoSum({3, 2, 4, 1}, 5);
  twoSum({3, 2, 4, 1}, 10);
}
