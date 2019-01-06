/***************************************************
 * Title : Path problem solved by BellmanFord
 * Author: Dipankar Dutta
 ****************************************************/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Same as bellman ford just run it k+1 iterations.
int findCheapestPrice(int n, vector<vector<int>> edges, int src, int sink,
                      int k) {

  // define a cost matix. cost[i] indicate min cost to reach i from src with j
  // nodes where j will increase incrementaly.
  vector<int> cost(n, 1e8);
  // cost to reach src is zero.
  cost[src] = 0;
  // incremanet intermidiate nodes from 0 to k(inclusive)
  for (int z = 0; z <= k; z++) {
    // we need to use a temp arary as it will be chnaged inline.
    vector<int> tempCost(cost);
    for (auto e : edges) {
      tempCost[e[1]] = min(tempCost[e[1]], cost[e[0]] + e[2]);
    }
    // swich the result arrat.
    cost = tempCost;
  }
  return cost[sink] == 1e8 ? -1 : cost[sink];
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
