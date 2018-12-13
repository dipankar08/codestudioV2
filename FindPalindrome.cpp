/***************************************************
 * Title : Palindrome check
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Two pointer approach,
bool isPalindromeStr(string s) {
  for (int left = 0, right = s.size() - 1; left < right; left++, right--) {
    if (s[left] != s[right]) {
      return false;
    }
  }
  return true;
}

// calcuating the reverse
bool isPalindromeNum(int number) {
  int temp = number;
  int reverse = 0;
  while (temp != 0) {
    reverse = reverse * 10 + temp % 10;
    temp = temp / 10;
  }
  return number == reverse;
}

// Recusion technique
bool isPalindromeUtil(int num, int *dupNum) {
  if (num >= 0 && num < 10) {
    return (num == (*dupNum) % 10);
  }
  if (!isPalindromeUtil(num / 10, dupNum)) {
    return false;
  }
  // This will excute when you goes up in recustion stack.
  *dupNum /= 10;
  // last compare
  return (num % 10 == (*dupNum) % 10);
}

int isPalindromeNum2(int num) {
  // convert to +ve if -ve.
  if (num < 0) {
    num = -num;
  }
  // Create a separate copy of num used in recursion.
  int *dupNum = new int(num);
  // now execute recustion.
  return isPalindromeUtil(num, dupNum);
}

int main() {
  cout << isPalindromeStr("1") << endl;     // 1
  cout << isPalindromeStr("ab") << endl;    // 0
  cout << isPalindromeStr("abcba") << endl; // 1

  cout << isPalindromeNum(1) << endl;                      // 1
  cout << isPalindromeNum(10) << endl;                     // 0
  cout << isPalindromeNum(101) << endl;                    // 1
  cout << "Worng:" << isPalindromeNum(9100000019) << endl; // overflow
  cout << isPalindromeNum2(9100000019) << endl;            // Works fine
}
