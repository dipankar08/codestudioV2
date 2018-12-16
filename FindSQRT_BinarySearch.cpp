/***************************************************
 * Title : Binary Search
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
  int start = 1, end = x;
  while (start < end) {
    int mid = start + (end - start) / 2;
    // This is essentaily a check for x >= mid*mid && x <(mid+1)*(mid+1)
    if (mid <= x / mid && (mid + 1) > x / (mid + 1)) { // Found the result
      return mid;
    } else if (mid > x / mid) { // Keep checking the left part
      end = mid;
    } else {
      start = mid + 1; // Keep checking the right part
    }
  }
  return start;
}

int main() {
  cout << "result:" << mySqrt(4) << endl;
  cout << "result:" << mySqrt(37) << endl;
  return 0;
}
