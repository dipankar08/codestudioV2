/***************************************************
 * Title : Linear serach
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int mySqrt(int x) {
  if (x == 0)
    return 0;
  for (int i = 1; i <= x / i; i++) {
    // Look for the critical point:i*i <= x && (i+1)(i+1) > x
    if (i <= x / i && (i + 1) > x / (i + 1)) {
      return i;
    }
  }
  return -1;
}

int main() {
  cout << "result:" << mySqrt(4) << endl;
  cout << "result:" << mySqrt(37) << endl;
  return 0;
}
