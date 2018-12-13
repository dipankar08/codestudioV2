/***************************************************
 * Title : Encode examples
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
string compress(string chars) {
  int indexAns = 0, index = 0;
  while (index < chars.size()) {
    char currentChar = chars[index];
    int count = 0;
    // keep incresing if the index is same.
    while (index < chars.size() && chars[index] == currentChar) {
      index++;
      count++;
    }
    // OK now we got a diffrent char. store the currentChar and also store the
    // count
    chars[indexAns++] = currentChar;
    if (count != 1) {
      for (char c : to_string(count)) {
        chars[indexAns++] = c;
      }
    }
  }
  return chars.substr(0, indexAns);
}

int main() {
  cout << compress("DDDIIIIIIPPPPPAN") << endl; // D3I6P5AN
  cout << compress("ABC") << endl;              // ABC
}
