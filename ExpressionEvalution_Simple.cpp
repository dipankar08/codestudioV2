/***************************************************
 * Title : Expression Evaluation Using Stack
 * Author: Dipankar Dutta
 ****************************************************/
#include "utils.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define isDigit(x) ((x <= '9' && x >= '0') ? true : false)
int calculate(string s) {
  int sign = 1, result = 0;
  stack<int> st;
  // We loop though all the charater in the string.
  for (int i = 0; i < s.size(); i++) {
    cout << "Expression:" << s.substr(i) << " Stack:";
    printStack(st);
    cout << " Result:" << result << endl;
    // let tokanize the full number.
    if (isDigit(s[i])) {
      int sum = s[i] - '0';
      while (i + 1 < s.size() && isDigit(s[i + 1])) {
        sum = sum * 10 + s[i + 1] - '0';
        i++;
      }
      result += sum * sign;
    } else if (s[i] == '+') {
      sign = 1;
    } else if (s[i] == '-') {
      sign = -1;
    } else if (s[i] == '(') {
      st.push(result);
      st.push(sign);
      result = 0;
      sign = 1;
    } else if (s[i] == ')') {
      int first = st.top();
      st.pop();
      int second = st.top();
      st.pop();
      result = result * first + second;
    } else {
      // invalid char ignore.
    }
  }
  return result;
}

int main() {
  cout << "result:" << calculate("1+1") << endl;
  cout << "result:" << calculate("2 - 1 + 2") << endl;
  cout << "result:" << calculate("10 - (20 + 30)") << endl;
  cout << "result:" << calculate("(1+(4+5+2)-3)+(6+8)") << endl;
  return 0;
}
