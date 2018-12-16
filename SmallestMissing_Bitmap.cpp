/***************************************************
 * Title : Uising O(1) Bitmap
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int firstMissingPositive(vector<int> nums) {
  int N = (int)nums.size();
  const unsigned int ks = 31;        // bit to tag value (.flag)
  const unsigned int kf = (1 << ks); // our flag value
  const unsigned int km = kf - 1;    // mask to extract actual value

  // clear out negative values, and values greater than N
  // (if value greater than N, then there must be a gap below it, so we can
  // ignore them too)
  int max = 0;
  for (int i = 0; i < N; i++) {
    if (nums[i] < 0 || nums[i] > N)
      nums[i] = 0;
  }

  // now tag nums[i] into flag 'bit' of it's index's location   (nums[ nums[i]-1
  // ].flag = 1) this is the trickly/unobvious part of the algorithm...
  for (int i = 0; i < N; i++) {
    int t = nums[i] & km; // original unmodified value
    if (t > 0) {
      nums[t - 1] = kf | (nums[t - 1] & km); // flag it's index as existing
    }
  }

  // finally look for any first num with missing .flag bit
  for (int i = 0; i < N; i++) {
    if ((nums[i] & kf) == 0)
      return i + 1;
  }
  return N + 1;
}
int main() {
  cout << "result:" << firstMissingPositive({1, 2, 0}) << endl;
  cout << "result:" << firstMissingPositive({3, 4, -1, 1}) << endl;
  cout << "result:" << firstMissingPositive({7, 8, 9, 11, 12}) << endl;
  return 0;
}
