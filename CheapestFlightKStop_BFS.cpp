/***************************************************
 * Title : Path problem solved by DFS
 * Author: Dipankar Dutta
 ****************************************************/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> flights, int s, int d, int K) {
  // build the adj matrix.
  unordered_map<int, vector<pair<int, int>>> g;
  for (const auto &e : flights) {
    g[e[0]].emplace_back(e[1], e[2]);
  }
  // define global ans as MAX
  int ans = INT_MAX;
  // we define a queue - which holds the pair of current vertices with cost to
  // reach this point.
  queue<pair<int, int>> q;
  q.push({s, 0});
  // define steps as we explore ina  level wize.
  int steps = 0;
  while (!q.empty()) {
    // We first take the size of this level so that we can take out
    // extacts that amount of nodes the queue
    int n = q.size();
    for (int i = 0; i < n; ++i) {
      auto curr = q.front();
      q.pop();
      // we found the destination - so update min.
      if (curr.first == d) {
        ans = min(ans, curr.second);
      }
      // explore next level.
      for (auto x : g[curr.first]) {
        // No need to visit this path as we will not find the optimal solution
        // anyway as cost is already high.
        if (curr.second + x.second > ans) {
          continue;
        }
        q.push({x.first, curr.second + x.second});
      }
    }
    if (steps++ > K)
      break;
  }

  return ans == INT_MAX ? -1 : ans;
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
