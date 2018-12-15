/***************************************************
 * Title : Sample Union Find Alogorithm
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class UnionFind {
private:
  vector<int> parent;
  int count = 0;

public:
  UnionFind(vector<int> nums) {
    parent.resize(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      parent[i] = i;
      count++;
    }
  }
  void union1(int node1, int node2) {
    int find1 = find(node1);
    int find2 = find(node2);
    if (find1 != find2) {
      parent[find1] = find2;
      count--;
    }
  }
  int find(int node) {
    if (parent[node] == node) {
      return node;
    }
    parent[node] = find(parent[node]);
    return parent[node];
  }
  int getCount() { return count; }
};
int main() {
  UnionFind uf({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  // make set {0,1,2,3,4}
  uf.union1(0, 1);
  uf.union1(1, 2);
  uf.union1(2, 3);
  uf.union1(1, 4);
  // make set {5,6}
  uf.union1(5, 6);
  // make set {7,8,9}
  uf.union1(9, 8);
  uf.union1(7, 8);
  cout << uf.getCount() << endl;
  return 0;
}
