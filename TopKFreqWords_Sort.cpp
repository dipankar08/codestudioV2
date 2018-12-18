/***************************************************
 * Title : Build freq and sort
 * Author: Dipankar Dutta
 ****************************************************/
#include "utils.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
static bool comp(pair<int, string> &a, pair<int, string> &b) {
  if (a.first == b.first) {
    return a.second < b.second;
  } else {
    return a.first > b.first;
  }
}

vector<string> topKFrequent(vector<string> words, int k) {
  // define a map.
  map<string, int> h;

  // build freq
  for (int i = 0; i < words.size(); i++) {
    h[words[i]]++;
  }
  // build the vector from the map
  vector<pair<int, string>> v;
  for (auto e : h) {
    v.push_back(make_pair(e.second, e.first));
  }
  // custom sort the vector
  sort(v.begin(), v.end(), comp);

  // taking k value from the vector
  vector<string> ret;
  for (int i = 0; i < k; i++) {
    ret.push_back(v[i].second);
  }
  return ret;
}

int main() {
  printVec(topKFrequent({"i", "love", "dipankar", "i", "love", "coding"}, 2));
  printVec(topKFrequent(
      {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"},
      4));
  return 0;
}
