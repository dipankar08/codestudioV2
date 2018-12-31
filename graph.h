/***************************************************
 * Title : Graph Representation.
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Graph {
  vector<vector<int>> adjList;
  vector<vector<int>> adjMatrix;
  // the constrator is
  Graph(int n, vector<pair<int, int>> edges) {
    // build adj list.
    adjList.resize(n, {});
    for (int i = 0; i < edges.size(); i++) {
      adjList[edges[i].first].push_back(edges[i].second);
    }
    // build maj matrix.
    adjMatrix.resize(n, vector<int>(n, 0));
    for (int i = 0; i < edges.size(); i++) {
      adjMatrix[edges[i].first][edges[i].second] = 1;
    }
  }
  void print() {
    cout << endl << "Adjacent List:" << endl;
    for (int i = 0; i < adjList.size(); i++) {
      if (adjList[i].size() > 0) {
        cout << i << "->";
        for (auto j : adjList[i]) {
          cout << j << "->";
        }
        cout << endl;
      }
    }
    cout << endl << "Adj Matrix :" << endl;
    for (int i = 0; i < adjMatrix.size(); i++) {
      for (int j = 0; j < adjMatrix.size(); j++) {
        cout << adjMatrix[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
};

// Node Presentation.
struct UndirectedGraphNode {
  int val;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : val(x){};
};