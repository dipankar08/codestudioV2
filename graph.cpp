/***************************************************
 * Title : Graph Traverals.
 * Author: Dipankar Dutta
 ****************************************************/
#include "graph.h"
#include <queue>
#include <stack>
using namespace std;
// dfs using recusrion.
void dfs(Graph *g, int i, vector<bool> &visited) {
  if (visited[i] == true) {
    return;
  }
  // let's visit and mark it.
  cout << i << " ";
  visited[i] = true;
  // Vist all adj nodes.
  for (int j : g->adjList[i]) {
    if (visited[j] != true) {
      dfs(g, j, visited);
    }
  }
}
void dfs_recusrion(Graph *g) {
  vector<bool> visited(g->adjList.size(), false);
  // We should try to visit all the node for disjoint graph.
  for (int i = 0; i < g->adjList.size(); i++) {
    dfs(g, i, visited);
  }
  cout << endl;
}

void dfs_stack(Graph *g) {
  vector<bool> visited(g->adjList.size(), false);
  stack<int> s;
  s.push(0);
  visited[0] = true;
  while (!s.empty()) {
    // take out from stack and visist it
    int i = s.top();
    s.pop();
    cout << i << " ";
    for (auto j : g->adjList[i]) {
      if (!visited[j]) {
        s.push(j);
        visited[j] = true;
      }
    }
  }
  cout << endl;
}
void bfs_queue(Graph *g) {
  vector<bool> visited(g->adjList.size(), false);
  queue<int> q;
  q.push(0);
  visited[0] = true;
  while (!q.empty()) {
    // take out from stack and visist it
    int i = q.front();
    q.pop();
    cout << i << " ";
    for (auto j : g->adjList[i]) {
      if (!visited[j]) {
        q.push(j);
        visited[j] = true;
      }
    }
  }
  cout << endl;
}

int main() {
  //  0  ---->  1
  //  ^         |
  //  |         v
  //  2  <----  3
  Graph *graph = new Graph(4, {{0, 1}, {1, 3}, {3, 2}, {2, 0}});
  graph->print();
  dfs_recusrion(graph); // 0 1 3 2
  dfs_stack(graph);     // 0 1 3 2
  bfs_queue(graph);     // 0 1 3 2
  return 0;
}
