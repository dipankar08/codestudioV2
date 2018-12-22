/***************************************************
 * Title : Find IsValid for ( and )
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool isValidParenthesis(string s) {
  cout << "Input:" << s << endl;
  int balance = 0;
  for (char c : s) {
    if (c == '(') {
      balance++;
    }
    if (c == ')') {
      balance--;
    }
    if (balance < 0) {
      // cout << "char:" << c << "  balance:" << balance << endl;
      return false;
    }
    // cout << "char:" << c << "  balance:" << balance << endl;
  }
  if (balance == 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  cout << isValidParenthesis("()(())") << endl;
  cout << isValidParenthesis("()(") << endl;
  cout << isValidParenthesis("())") << endl;
  return 0;
}
