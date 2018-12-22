/***************************************************
 * Title : Solving using # PQ Not Working
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
// defines comparator.
class Compare {
public:
  bool operator()(vector<int> a, vector<int> b) {
    if (a[1] == b[1]) {
      return b[2] - a[2];
    } else {
      return b[1] - a[1];
    }
  }
};

class FreqStack {
  unordered_map<int, int> map;
  std::priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
  int index;

public:
  FreqStack() { index = 0; }
  void push(int x) {
    // determine frequnecy of the x and store in map.
    if (map.find(x) == map.end()) {
      map[x] = 1;
    } else {
      map[x]++;
    }
    // push the touple in PQ.
    pq.push(vector<int>({x, map[x], index++}));
    cout<<"Push "<< x<<" State:";
    printState();
  }

  int pop() {
    // Take the item from the PQ.
    int temp = pq.top()[0];
    pq.pop();
    // reduce the frequnecy of x in map. delete if frews goes to zero.
    if (map[temp] == 1) {
      map.erase(temp);
    } else {
      map[temp] = map[temp] - 1;
    }
    return temp;
  }
  void printState(){
    cout<<"Top Now:"<<pq.top()[0]<<endl;
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
