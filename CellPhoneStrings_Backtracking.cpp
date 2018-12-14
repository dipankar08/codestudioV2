/***************************************************
 * Title : Letter combination using Backtracking
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
void backtracking(const vector<vector<char>> &table, vector<string> &res,
                  string &local, int index, const string &digits) {
  // last vase where local is the answer.
  if (index == digits.size()) {
    res.push_back(local);
  } else {
    for (int i = 0; i < table[digits[index] - '0'].size(); i++) {
      // We are considered each char from map[2], that explore the path {a,b,c}
      local.push_back(table[digits[index] - '0'][i]);
      backtracking(table, res, local, index + 1, digits);
      local.pop_back();
    }
  }
}

vector<string> letterCombinations(string digits) {
  vector<string> res; // empty.
  if (digits.size() == 0) {
    return res;
  }
  string local;
  // we can define as a 2D vector rather having a map
  vector<vector<char>> table(2, vector<char>());     // index 0 and 1
  table.push_back(vector<char>{'a', 'b', 'c'});      // index 2
  table.push_back(vector<char>{'d', 'e', 'f'});      // 3
  table.push_back(vector<char>{'g', 'h', 'i'});      // 4
  table.push_back(vector<char>{'j', 'k', 'l'});      // 5
  table.push_back(vector<char>{'m', 'n', 'o'});      // 6
  table.push_back(vector<char>{'p', 'q', 'r', 's'}); // 7
  table.push_back(vector<char>{'t', 'u', 'v'});      // 8
  table.push_back(vector<char>{'w', 'x', 'y', 'z'}); // 9

  backtracking(table, res, local, 0, digits);
  return res;
}

int main() {
  vector<string> ans = letterCombinations("234");
  for (string s : ans) {
    cout << s << endl;
  }
}
