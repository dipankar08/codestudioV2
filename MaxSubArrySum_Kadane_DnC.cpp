/***************************************************
 * Title : MaxSubArraySum Using D&C
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// return structures
struct val {
  int l, m, r, s;
  val(int l, int m, int r, int s) : l(l), m(m), r(r), s(s) {}
};

val dac(vector<int> A, int start, int end) {
  // cout<<"DAC is called for:start: "<<start<<" end:"<<end<<endl;
  if (start == end) {
    return val(A[start], A[start], A[start], A[start]);
  }
  int mid = start + (end - start) / 2;
  val v1 = dac(A, start, mid);
  val v2 = dac(A, mid + 1, end);
  int l, m, r, s;
  l = max(v1.l, v1.s + v2.l);
  m = max(v1.r + v2.l, max(v1.m, v2.m));
  r = max(v2.r, v1.r + v2.s);
  s = v1.s + v2.s;
  return val(l, m, r, s);
}
int MaxSubArraySum(vector<int> A) {
  val v = dac(A, 0, A.size() - 1);
  return v.m;
}

int main() {
  cout << "result:" << MaxSubArraySum({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << endl;
  cout << "result:" << MaxSubArraySum({-1, -2, -3, -4}) << endl;
  return 0;
}
