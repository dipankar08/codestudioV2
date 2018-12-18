/***************************************************
 * Title : Uisng Max Heap
 * Author: Dipankar Dutta
 ****************************************************/
#include "utils.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> topKFrequent(vector<string> words, int k) {
  // build the freq first
  unordered_map<string, int> freq;
  for (auto w : words) {
    freq[w]++;
  }

  // define type and comp function.
  auto comp = [&](const pair<string, int> &a, const pair<string, int> &b) {
    return a.second < b.second || (a.second == b.second && a.first > b.first);
  };
  typedef priority_queue<pair<string, int>, vector<pair<string, int>>,
                         decltype(comp)>
      my_priority_queue_t;
  my_priority_queue_t pq(comp);
  // adding all elemnet in the pq.
  for (auto w : freq) {
    pq.emplace(w.first, w.second);
  }

  // build the output by taking the k elemnets
  // you need to add in back as we are poing from max heap.
  vector<string> output;
  while (!pq.empty() && output.size() < k) {
    output.push_back(pq.top().first);
    pq.pop();
  }
  return output;
}

int main() {
  printVec(topKFrequent({"i", "love", "dipankar", "i", "love", "coding"}, 2));
  printVec(topKFrequent(
      {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"},
      4));
  return 0;
}
