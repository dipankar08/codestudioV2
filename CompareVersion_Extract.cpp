/***************************************************
 * Title : extractNum
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void extractNum(string s) {
  int value = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '.') {
      cout << value << " ";
      value = 0;
    } else {
      value = value * 10 + (s[i] - '0');
    }
  }
  cout << value << endl;
}
int main() {
  extractNum("10.12.56.67"); // 10 12 56 67
}
