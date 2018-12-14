/***************************************************
 * Title : Letter combination using DFS
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
void letterCombinationsRecursive(string digits, vector<string> &result,
                                 string word, map<char, string> &digitMap) {
  // nothing left
  if (digits == "") {
    result.push_back(word);
    return;
  }

  char currNum = digits[0];
  for (int i = 0; i < digitMap[currNum].length(); i++) {
    letterCombinationsRecursive(digits.substr(1) /* take out first char*/,
                                result, word + digitMap[currNum][i], digitMap);
  }
}

vector<string> letterCombinations(string digits) {
  vector<string> result;
  if (digits == "") {
    return result;
  }
  map<char, string> digitMap;
  digitMap['2'] = "abc";
  digitMap['3'] = "def";
  digitMap['4'] = "ghi";
  digitMap['5'] = "jkl";
  digitMap['6'] = "mno";
  digitMap['7'] = "pqrs";
  digitMap['8'] = "tuv";
  digitMap['9'] = "wxyz";
  digitMap['0'] = "";
  letterCombinationsRecursive(digits, result, "", digitMap);
  return result;
}
int main() {
  vector<string> ans = letterCombinations("234");
  for (string s : ans) {
    cout << s << endl;
  }
}
