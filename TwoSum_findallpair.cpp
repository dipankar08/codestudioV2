/***************************************************
 * Title : Two Sum Using HashMap
 * Author: Dipankar Dutta
 ****************************************************/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> numbers, int target) {
  unordered_map<int, int> hashMap;
  vector<int> result;
  for (int i = 0; i < numbers.size(); i++) {
    int numberToFind = target - numbers[i];
    if (hashMap.find(numberToFind) != hashMap.end()) {
      result.push_back(hashMap[numberToFind] + 1);
      result.push_back(i + 1);
      return result;
    }
    hashMap[numbers[i]] = i;
  }
  return result;
}
void print(vector<int> in) {
  cout << "Result: [";
  for (int i : in) {
    cout << i << ", ";
  }
  cout << "]" << endl;
}
int main() {
  print(twoSum({3, 2, 4, 1}, 5));
  print(twoSum({3, 2, 4, 1}, 10));
  return 0;
}
