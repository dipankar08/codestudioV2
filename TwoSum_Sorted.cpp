/***************************************************
 * Title : Two Sum Example
 * Author: Dipankar Dutta
 ****************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void twoSum(vector<int> &numbers, int target) {
  int i = 0, j = numbers.size() - 1;
  while (i < j) {
    int sum = numbers[i] + numbers[j];
    if (sum == target) {
      cout << "Found";
    } else if (sum > target) {
      j--;
    } else {
      i++;
    }
  }
  cout << "Not found";
}
