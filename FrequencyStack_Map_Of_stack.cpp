/***************************************************
 * Title : Solving using map of stack
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
class FreqStack {
  unordered_map<int, int> freq;
  unordered_map<int, stack<int>> group;
  int maxfreq;

public:
  FreqStack() { maxfreq = 0; }

  void push(int x) {
    int f = freq.find(x) == freq.end() ? 1 : freq[x] + 1;
    freq.insert({x, f});
    if (f > maxfreq) {
      maxfreq = f;
    }
    if (group.find(f) == group.end()) {
      stack<int> fs;
      group.insert({f, fs});
    }
    group[f].push(x);
  }

  int pop() {
    int x = group[maxfreq].top();
    group[maxfreq].pop();
    freq.insert({x, freq[x] - 1});
    if (group[maxfreq].size() == 0) {
      maxfreq--;
    }
    return x;
  }
};

int main() {
  FreqStack mFreqStack;
  mFreqStack.push(5);               // 5
  mFreqStack.push(7);               // 5 7
  mFreqStack.push(5);               // 5 7 5
  mFreqStack.push(7);               // 5 7 5 7
  mFreqStack.push(4);               // 5 7 5 7 4
  mFreqStack.push(5);               // 5 7 5 7 4 5
  cout << mFreqStack.pop() << endl; // return 5; // 5 7 5 7 4
  cout << mFreqStack.pop()
       << endl; // return 7; ( 5, 7 both most frg but 7 wins) // 5 7 5 4
  cout << mFreqStack.pop() << endl; // return 5 ( as 5 most fre) // 5 7 4.
  cout << mFreqStack.pop() << endl; // return 4 ( as all have same fre) // 5 7

  return 0;
}
