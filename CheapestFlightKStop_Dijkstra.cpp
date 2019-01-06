/***************************************************
 * Title : Path problem solved by Dijkstra
 * Author: Dipankar Dutta
 ****************************************************/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> flights, int src, int dst,
                      int K) {
  // wefine graph as Adj mtarix.
  unordered_map<int, unordered_map<int, int>> mp;
  for (const vector<int> &flight : flights) {
    mp[flight[0]][flight[1]] = flight[2];
  }
  // the PQ contains the {cost, currentnodes, remaining count_of_interidete
  // node}
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
      minheap;
  // insert the initial payload.
  minheap.push({0, src, K + 1});
  while (!minheap.empty()) {
    vector<int> top = minheap.top();
    minheap.pop();
    int price = top[0];
    int city = top[1];
    int stops = top[2]; // remaning stop
    if (city == dst) {
      return price;
    }
    // if we have more reamining sort.
    if (stops > 0) {
      for (auto &t : mp[city]) {
        minheap.push({price + t.second, t.first, stops - 1});
      }
    }
  }
  return -1;
}
int main() {
  cout << "With 1 Stop:"
       << findCheapestPrice(3, {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}}, 0, 2, 1)
       << endl;
  cout << "With 0 Stop:"
       << findCheapestPrice(3, {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}}, 0, 2, 0)
       << endl;

  return 0;
}
