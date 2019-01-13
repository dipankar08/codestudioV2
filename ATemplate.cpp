/***************************************************
 * Title :
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include "utils.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cout << "result:" << MaxSubArraySum({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << endl;
  cout << "result:" << MaxSubArraySum({-1, -2, -3, -4}) << endl;
  return 0;
}
