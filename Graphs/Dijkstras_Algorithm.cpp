#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> dijkstra(const vector<vector<pair<int, int>>> &adj, int src,
                     int V) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  vector<int> dist(V, INT_MAX);

  dist[src] = 0;
  pq.emplace(0, src);

  while (!pq.empty()) {
    auto [distance, node] = pq.top();
    pq.pop();

    if (distance > dist[node])
      continue;

    for (auto &[neighbor, weight] : adj[node]) {
      if (distance + weight < dist[neighbor]) {
        dist[neighbor] = distance + weight;
        pq.emplace(dist[neighbor], neighbor);
      }
    }
  }

  return dist;
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

  vector<int> res = dijkstra(adj, 0, V);
  for (int x : res)
    cout << x << " ";

  return 0;
}

// 5
// 7
// 2 1 3
// 2 0 1
// 1 0 7
// 0 3 2
// 1 3 5
// 1 4 1
// 3 4 7
