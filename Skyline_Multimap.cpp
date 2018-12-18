/***************************************************
 * Title : Solving using Multi-Map
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<pair<int, int>> getSkyline(vector<vector<int>> buildings) {
  vector<pair<int, int>> edges;
  vector<pair<int, int>> result;
  // First build unifited edges, height of begining is -ve height.
  int left, right, height;
  for (int i = 0; i < buildings.size(); i++) {
    left = buildings[i][0];
    right = buildings[i][1];
    height = buildings[i][2];
    edges.push_back(make_pair(left, -height));
    edges.push_back(make_pair(right, height));
  }
  // Soft the builing on first coordinate of pair - that is on x-cord
  sort(edges.begin(), edges.end());

  // we use the multiset instead of PQ to store the max height util current pos
  multiset<int> m;
  // insert the first one.
  m.insert(0);
  int pre = 0;
  // scan the edges from left
  for (int i = 0; i < edges.size(); i++) {
    pair<int, int> e = edges[i];
    // insert into multi-set if we got the new one else remove it.
    if (e.second < 0) {
      m.insert(-e.second);
    } else {
      m.erase(m.find(e.second));
    }
    // first the current height and see if there is a diff then
    // just log it in the result.
    int cur = *(m.rbegin());
    if (cur != pre) {
      result.push_back(make_pair(e.first, cur));
      pre = cur;
    }
  }
  return result;
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