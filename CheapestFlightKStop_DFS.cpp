/***************************************************
 * Title : Path problem solved by DFS
 * Author: Dipankar Dutta
 ****************************************************/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
void dfs(int s, int d, int k, int cost, vector<int> &visited, int &ans,
         unordered_map<int, vector<pair<int, int>>> &g) {
  // we found the path return cost
  if (s == d) {
    ans = cost;
    return;
  }
  // No more interanl vertices left
  if (k == 0) {
    return;
  }
  // mark s visisted
  visited[s] = 1;
  for (const auto &x : g[s]) {
    if (visited[x.first] == 0) {
      if (cost + x.second > ans) {
        continue; // IMPORTANT!!! prunning as cost is higher - no need to
                  // explore.
      }
      // let's explore as next veriices as x.
      dfs(x.first, d, k - 1, cost + x.second, visited, ans, g);
    }
  }
  // backtrcaks from recusrion - so rest the marking.
  visited[s] = 0;
}

int findCheapestPrice(int n, vector<vector<int>> flights, int s, int d, int K) {
  // converting a list of edges to adjc list.
  unordered_map<int, vector<pair<int, int>>> g;
  for (const auto &e : flights) {
    g[e[0]].emplace_back(e[1], e[2]);
  }
  // ans trcks a overall minimal value.
  // this can be done using global veriable or static veirbale or pass by ref.
  int ans = INT_MAX;
  // we have a visisted array to avoid loops and ensure the node are visisted
  // only once.
  vector<int> visited(n, 0);
  dfs(s, d, K + 1, 0, visited, ans, g);
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
