#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Edge {
public:
  int u, v, wt;
  Edge(int u, int v, int wt) : u(u), v(v), wt(wt) {}
};

vector<int> bellmanFord(const vector<vector<pair<int, int>>> &adj, int V, int E,
                        int src) {
  vector<int> dist(V, INT_MAX);
  vector<int> parent(V, -1);
  vector<Edge> edges;
  edges.reserve(E);

  dist[src] = 0;

  for (int u = 0; u < V; u++) {
    for (auto &v : adj[u]) {
      Edge e(u, v.first, v.second);
      edges.push_back(e);
    }
  }

  for (int i = 0; i < V - 1; i++) {
    bool updated = false;

    for (auto &edge : edges) {
      if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.wt < dist[edge.v]) {
        dist[edge.v] = dist[edge.u] + edge.wt;
        parent[edge.v] = edge.u;
        updated = true;
      }
    }
    if (!updated)
      break;
  }

  for (auto &edge : edges) {
    if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.wt < dist[edge.v]) {
      cout << "Negative Cycle Exists. Shortest Distance not possible" << endl;
      return {};
    }
  }

  return dist;
}

void addEdge(vector<vector<pair<int, int>>> &adj, int u, int v, int wt) {
  adj[u].push_back({v, wt});
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

  vector<int> distances = bellmanFord(adj, V, E, 0);
  cout << endl << "Distances : " << endl;
  for (int i = 0; i < distances.size(); i++) {
    cout << i << " - " << distances[i] << endl;
  }

  return 0;
}

// without -ve cycle
// 3
// 3
// 0 1 2
// 0 2 2
// 1 2 -1

// with -ve cycle
// 3
// 3
// 0 1 -12
// 1 2 -8
// 2 0 6