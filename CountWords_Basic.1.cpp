/***************************************************
 * Title : Count Words
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define IN 1
#define OUT 0

unsigned CountWordsInASentense(string str) {
  int state = OUT;
  unsigned wc = 0;
  for (char c : str) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++wc;
    }
  }
  return wc;
}

int main() {
  cout << "result:" << CountWordsInASentense("   DIPANKAR DUTTA    ") << endl;
  cout << "result:" << CountWordsInASentense("\n\n   \n\n\n  ") << endl;
  return 0;
}
