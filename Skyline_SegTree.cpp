/***************************************************
 * Title : Solving using Multi-Map
 * Author: Dipankar Dutta
 ****************************************************/
#include "segTree.h"
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<pair<int, int>> getSkyline(vector<vector<int>> buildings) {
  unordered_map<int, int> coord_map;
  vector<int> all_pos;
  for (vector<int> &v : buildings) {
    if (coord_map.find(v[0]) == coord_map.end()) {
      all_pos.push_back(v[0]);
      coord_map[v[0]] = 0;
    }
    if (coord_map.find(v[1]) == coord_map.end()) {
      all_pos.push_back(v[1]);
      coord_map[v[1]] = 0;
    }
  }
  sort(all_pos.begin(), all_pos.end());
  for (int index = 0; index < all_pos.size(); index++) {
    coord_map[all_pos[index]] = index;
  }

  SegTree tree(all_pos.size());
  for (vector<int> &v : buildings) {
    int i0 = coord_map[v[0]];
    int i1 = coord_map[v[1]];
    tree.insert(i0, i1 - 1, v[2]);
  }
  vector<pair<int, int>> res;
  int last_h = 0;
  for (int i = 0; i < all_pos.size(); i++) {
    int h = tree.query(i);
    if (h != last_h) {
      res.push_back(make_pair(all_pos[i], h));
      last_h = h;
    }
  }
  return res;
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