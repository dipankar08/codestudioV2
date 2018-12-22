/***************************************************
 * Title : Find IsValid for ( and )
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
bool isValid(string s) {
  stack<char> paren;
  for (char &c : s) {
    switch (c) {
    case '(':
    case '{':
    case '[':
      paren.push(c);
      break;
    case ')':
      if (paren.empty() || paren.top() != '(') {
        return false;
      } else {
        paren.pop();
      }
      break;
    case '}':
      if (paren.empty() || paren.top() != '{') {
        return false;
      } else {
        paren.pop();
      }
      break;
    case ']':
      if (paren.empty() || paren.top() != '[') {
        return false;
      } else {
        paren.pop();
      }
      break;
    default:; // pass
    }
  }
  return paren.empty();
}

int main() {
  cout << isValid("{[()()]}") << endl; // true
  cout << isValid("{(})") << endl;     // false
  cout << isValid("{{]]") << endl;     // false
  return 0;
}
