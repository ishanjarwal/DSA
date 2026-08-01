#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int minIndex(const vector<int> &keys, const vector<bool> &mst) {
  int minValue = INT_MAX, minIndex = -1;
  for (int i = 0; i < keys.size(); i++) {
    if (keys[i] < minValue && mst[i] == false) {
      minValue = keys[i];
      minIndex = i;
    }
  }
  return minIndex;
}

vector<int> prims(const vector<vector<pair<int, int>>> &adj, int V) {
  vector<int> keys(V, INT_MAX);
  vector<bool> mst(V, false);
  vector<int> parent(V, -1);

  keys[0] = 0;

  for (int count = 0; count < V; count++) {
    int u = minIndex(keys, mst);

    if (u == -1)
      break;

    mst[u] = true;

    for (auto &[neighbor, neighborWt] : adj[u]) {
      if (!mst[neighbor] && neighborWt < keys[neighbor]) {
        keys[neighbor] = neighborWt;
        parent[neighbor] = u;
      }
    }
  }

  int cost = 0;
  for (int x : keys)
    cost += x;

  cout << "Minimum Cost : " << cost << endl;

  return parent;
}

void addEdge(vector<vector<pair<int, int>>> &adj, int u, int v, int wt) {
  adj[u].push_back({v, wt});
  adj[v].push_back({u, wt}); // comment for directed graph
}

int main() {

  int V, E;
  cin >> V >> E;
  vector<vector<pair<int, int>>> adj(V);

  for (int i = 0; i < E; i++) {
    int u, v, wt;
    cin >> u >> v >> wt;
    addEdge(adj, u, v, wt);
  }

  vector<int> parents = prims(adj, V);
  cout << "Parents" << endl;
  for (int i = 0; i < parents.size(); i++)
    cout << i << " " << parents[i] << endl;

  return 0;
}

// 5
// 6
// 0 1 2
// 1 2 3
// 0 3 6
// 3 1 8
// 1 4 5
// 4 2 7