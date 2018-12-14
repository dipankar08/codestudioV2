/***************************************************
 * Title : Letter combination using Backtracking
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
queue<string> letterCombinations(string digits) {
  queue<string> res;
  string charmap[10] = {"",    "",    "abc",  "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};
  res.push("");
  while (res.front().size() != digits.size()) {
    string str = res.front();
    res.pop();
    string chars = charmap[digits[str.size()] - '0'];
    for (int c = 0; c < chars.size(); c++) {
      res.push(str + chars[c]);
    }
  }
  return res;
}

int main() {
  queue<string> q = letterCombinations("234");
  {
    while (!q.empty()) {
      std::cout << q.front() << endl;
      q.pop();
    }
  }
}
