/***************************************************
 * Title : Path problem solved by DP
 * Author: Dipankar Dutta
 ****************************************************/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>> flights, int src, int dst,
                      int K) {
  // The idea is to find the optimal path of path length k when we know the
  // optimal solution of path lenghh k-1/ The solution works like BellManFord
  // alogorithm. We incremenetany find the higher path length solution. dp[k][m]
  // represents the shortest distance from src to m with the number of edges
  // between them at most k
  vector<vector<int>> dp(K + 2, vector<int>(n, INT_MAX));
  // filling out base case for source
  for (int i = 0; i <= K + 1; i++) {
    dp[i][src] = 0;
  }
  // Now we trying to to path length from 1 .. K+1
  for (int i = 1; i <= K + 1; i++) {
    // Iterate over all the edges
    for (auto &f : flights) {
      // WE know there is path calculated to f[0]
      // for edge (f[0] ->f[1]);
      if (dp[i - 1][f[0]] != INT_MAX) {
        // optimal path to f[1] by f[0] from src with i length
        dp[i][f[1]] = min(dp[i][f[1]], dp[i - 1][f[0]] + f[2]);
      }
    }
    return (dp[K + 1][dst] == INT_MAX) ? -1 : dp[K + 1][dst];
  }
  int main() {
    cout << "With 1 Stop:"
         << findCheapestPrice(3, {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}}, 0, 2,
                              1)
         << endl;
    cout << "With 0 Stop:"
         << findCheapestPrice(3, {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}}, 0, 2,
                              0)
         << endl;

    return 0;
  }
