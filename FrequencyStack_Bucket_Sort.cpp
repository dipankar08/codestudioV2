/***************************************************
 * Title : Solving using Bucket sort
 * Author: Dipankar Dutta
 ****************************************************/
#include "utils.h"
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
class FreqStack {
  vector<stack<int>> bucket;
  unordered_map<int, int> map;

public:
  FreqStack() {}

  void push(int x) {
    // first incremenet the frequnecy map.
    if (map.find(x) == map.end()) {
      map[x] = 1;
    } else {
      map[x]++;
    }
    // get the current frequnecy of x and no bucket[freq - 1] exist - crean the
    // buckets
    int freq = map[x];
    if (freq - 1 >= bucket.size()) {
      bucket.push_back(stack<int>());
    }
    // push the element in that buckets
    bucket[freq - 1].push(x);
    // cout << "After push:" << x << " : ";
    // printState();
  }

  int pop() {
    // get the height buckets
    int freq = bucket.size();
    // pop out the top elemnet.
    int x = bucket[freq - 1].top();
    bucket[freq - 1].pop();
    // if that bucket is empty - just delete that buckets.
    if (bucket[freq - 1].empty()) {
      bucket.erase(bucket.begin() + freq - 1);
    }
    // reduce the frequnecy of the map -if the fre goes to zero -delete
    map[x]--;
    if (map[x] == 0) {
      map.erase(x);
    }

    // cout << "After Pop:" << x << " : ";
    // printState();
    // return the pop elemnet
    return x;
  }
  void printState() {
    for (int i = 0; i < bucket.size(); i++) {
      cout << "Bucket:" << i;
      printStack(bucket[i]);
      cout << " ";
    }
    cout << endl;
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
