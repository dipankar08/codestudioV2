/***************************************************
 * Title : Solving using PQ
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> merge(vector<pair<int, int>> left,
                             vector<pair<int, int>> right) {
  vector<pair<int, int>> rs;
  int h1 = 0, h2 = 0;
  // This is simsilar to merge sort - we scan all the elemnet and try to merge
  // them.
  while (left.size() > 0 && right.size() > 0) {
    int x = 0, h = 0;
    if (left[0].first < right[0].first) {
      x = left[0].first;
      h1 = left[0].second;
      h = max(h1, h2);
      left.erase(left.begin());
    } else if (left[0].first > right[0].first) {
      x = right[0].first;
      h2 = right[0].second;
      h = max(h1, h2);
      right.erase(right.begin());
    } else {
      x = left[0].first;
      h1 = left[0].second;
      h2 = right[0].second;
      h = max(h1, h2);
      left.erase(left.begin());
      right.erase(right.begin());
    }
    if (rs.size() == 0 || h != rs.back().second) {
      rs.push_back(make_pair(x, h));
    }
  }
  rs.insert(rs.end(), left.begin(), left.end());
  rs.insert(rs.end(), right.begin(), right.end());
  return rs;
}

vector<pair<int, int>> recurSkyline(vector<vector<int>> buildings, int left,
                                    int right) {
  // If we have more than one elment using D&C
  if (left < right) {
    int mid = left + (right - left) / 2;
    return merge(recurSkyline(buildings, left, mid),
                 recurSkyline(buildings, mid + 1, right));
  } else {
    // Ok - We have one element - so base case.
    vector<pair<int, int>> res;
    res.push_back(make_pair(buildings[left][0], buildings[left][2]));
    res.push_back(make_pair(buildings[left][1], 0));
    return res;
  }
}

vector<pair<int, int>> getSkyline(vector<vector<int>> buildings) {
  // just run the recursion.
  return recurSkyline(buildings, 0, buildings.size() - 1);
}

void printAns(vector<pair<int, int>> vec) {
  for (pair<int, int> p : vec) {
    cout << "[" << p.first << "," << p.second << "]"
         << ", ";
  }
  cout << endl;
}
int main() {
  printAns(getSkyline(
      {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}}));

  vector<vector<int>> input = {{1, 5, 11},   {2, 7, 6},   {3, 9, 13},
                               {12, 16, 7},  {14, 25, 3}, {19, 22, 18},
                               {23, 29, 13}, {24, 28, 4}};
  printAns(getSkyline(input));
  return 0;
}
