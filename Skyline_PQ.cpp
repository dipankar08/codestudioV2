/***************************************************
 * Title : Solving using PQ
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

// priority_queue doenst support remove an entry so I am extending
// this class to support remove.
class custom_priority_queue
    : public std::priority_queue<int, std::vector<int>> {
public:
  bool remove(const int value) {
    auto it = std::find(this->c.begin(), this->c.end(), value);
    if (it != this->c.end()) {
      this->c.erase(it);
      std::make_heap(this->c.begin(), this->c.end(), this->comp);
      return true;
    } else {
      return false;
    }
  }
};

vector<pair<int, int>> getSkyline(vector<vector<int>> buildings) {
  vector<pair<int, int>> res;
  vector<pair<int, int>> height;
  // We normilized all the inputs into pairs.
  // start of a building, height stored as negtive
  // end of a building, height stored as positive
  for (vector<int> b : buildings) {
    height.push_back(make_pair(b[0], -b[2]));
    height.push_back(make_pair(b[1], b[2]));
  }
  // sort the height list based on the x coordinates.
  sort(height.begin(), height.end());

  // a pq that stores all the encountered buildings' heights in descending order
  // PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> (b - a));
  custom_priority_queue pq;
  pq.push(0);
  int preMax = 0;
  // We scan all the building or entryies from left to right.
  for (pair<int, int> h : height) {
    // if  meets a new building (h[1] < 0), so add it to pq,
    // if it has reached the end of the building(h[1] >=0), so remove it
    if (h.second < 0) {
      pq.push(-h.second);
    } else {
      pq.remove(h.second);
    }
    // we see the current max height in all encountered buildings
    // if the max height is different from the previous one,
    // that means a critical point is met, add to result list
    int curMax = pq.top();
    if (curMax != preMax) {
      res.push_back(make_pair(h.first, curMax));
      preMax = curMax;
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
