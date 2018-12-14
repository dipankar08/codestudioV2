/***************************************************
 * Title : Letter combination using Backtracking
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
void printVec(vector<string> v) {
  cout << "Vector:";
  for (string s : v) {
    cout << s << " ";
  }
  cout << endl;
}
vector<string> letterCombinations(string digits) {
  vector<string> res;
  string charmap[10] = {"",    "",    "abc",  "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};
  // starts with empty ans
  res.push_back("");
  for (int i = 0; i < digits.size(); i++) {
    vector<string> tempres;
    string chars = charmap[digits[i] - '0'];
    for (int c = 0; c < chars.size(); c++) {
      for (int j = 0; j < res.size(); j++) {
        tempres.push_back(res[j] + chars[c]);
      }
    }
    // having new res
    res = tempres;
    // printVec(res); // uncomment to see temp result
  }
  return res;
}
int main() {
  vector<string> ans = letterCombinations("234");
  for (string s : ans) {
    cout << s << endl;
  }
}
