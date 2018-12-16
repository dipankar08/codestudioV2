/***************************************************
 * Title : Newton's Solution
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int mySqrt(int x) {
  if (x == 0) {
    return 0;
  }
  long i = x;
  while (i > x / i) {
    i = (i + x / i) / 2;
  }
  return (int)i;
}

int main() {
  cout << "result:" << mySqrt(4) << endl;
  cout << "result:" << mySqrt(37) << endl;
  return 0;
}
