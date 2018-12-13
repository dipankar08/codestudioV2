/***************************************************
 * Title : Print RLE for a string
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void printRLE(string str) {
  int n = str.length();
  for (int i = 0; i < n; i++) {
    // Count occurrences of current character
    int count = 1;
    while (i < n - 1 && str[i] == str[i + 1]) {
      count++;
      i++;
    }
    // Print character and its count
    if (count > 1) {
      cout << str[i] << count;
    } else {
      cout << str[i];
    }
  }
  cout << endl;
}

int main() {
  printRLE("DDDIIIIIIPPPPPAN"); // D3I6P5AN
  printRLE("ABC");              // ABC
}
