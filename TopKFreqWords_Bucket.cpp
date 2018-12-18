/***************************************************
 * Title : Using Buckets
 * Author: Dipankar Dutta
 ****************************************************/
#include "utils.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<string> topKFrequent(vector<string> &words, int k) {
  // first build the freq graph
  map<string, int> cnt;
  for (auto &w : words) {
    ++cnt[w];
  }

  // build the buckets from the list of words.
  vector<vector<string>> bucket(words.size());
  for (auto it : cnt) {
    bucket[it.second].push_back(it.first);
  }

  // collect the result from the buckets
  vector<string> res;
  for (int i = (int)bucket.size() - 1; k > 0 && i >= 0; i--) {
    if (bucket[i].empty()) {
      continue;
    }
    int n = min(k, (int)bucket[i].size());
    res.insert(res.end(), bucket[i].begin(), bucket[i].begin() + n);
    k -= n;
  }

  return res;
}

int main() {
  printVec(topKFrequent({"i", "love", "dipankar", "i", "love", "coding"}, 2));
  printVec(topKFrequent(
      {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"},
      4));
  return 0;
}
