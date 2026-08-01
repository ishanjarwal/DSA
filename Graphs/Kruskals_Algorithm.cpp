#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int u, v, wt;
};

class UnionFind {
private:
  vector<int> parent, rank;

public:
  UnionFind(int n) {
    parent.resize(n + 1);
    rank.assign(n + 1, 0);

    parent[0] = -1;
    rank[0] = -1;
    for (int i = 1; i < n + 1; i++)
      parent[i] = i;
  }

  int findParent(int node) {
    if (parent[node] != node)
      parent[node] = findParent(parent[node]);

    return parent[node];
  }

  bool unite(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);

    if (pu == pv)
      return false;

    if (rank[pu] < rank[pv]) {
      parent[pu] = pv;
    } else if (rank[pu] > rank[pv]) {
      parent[pv] = pu;
    } else {
      parent[pv] = pu;
      rank[pu]++;
    }

    return true;
  }
};

int kruskals(vector<Edge> &edges, int V) {
  sort(edges.begin(), edges.end(),
       [](const Edge &a, const Edge &b) { return a.wt < b.wt; });

  UnionFind uf(V);

  int mstCost = 0;
  int edgesUsed = 0;

  for (const auto &edge : edges) {
    if (uf.unite(edge.u, edge.v)) {
      mstCost += edge.wt;
      edgesUsed++;

      if (edgesUsed == V - 1)
        break;
    }
  }

  // Graph is disconnected
  if (edgesUsed != V - 1) {
    cout << "Graph is disconnected. MST does not exist.\n";
    return -1;
  }

  return mstCost;
}

int main() {
  int V, E;
  cin >> V >> E;

  vector<Edge> edges;

  for (int i = 0; i < E; i++) {
    int u, v, wt;
    cin >> u >> v >> wt;
    edges.push_back({u, v, wt});
  }

  int cost = kruskals(edges, V);

  if (cost != -1)
    cout << "Cost of MST: " << cost << '\n';

  return 0;
}

// 6
// 9
// 4 3 9
// 4 0 4
// 3 0 1
// 3 2 5
// 3 1 3
// 0 1 2
// 2 1 3
// 2 5 8
// 1 5 7

// 6
// 9
// 5 4 9
// 5 1 4
// 4 1 1
// 4 3 5
// 4 2 3
// 1 2 2
// 3 2 3
// 3 6 8
// 2 6 7