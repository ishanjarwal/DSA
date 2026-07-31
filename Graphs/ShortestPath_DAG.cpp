#include <climits>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void dfs(const vector<vector<pair<int, int>>> &adj, stack<int> &s,
         vector<bool> &visited, int node) {
  visited[node] = true;

  for (auto &[next, wt] : adj[node]) {
    if (!visited[next]) {
      dfs(adj, s, visited, next);
    }
  }

  s.push(node);
}

int shortestDistance(const vector<vector<pair<int, int>>> &adj, int V, int src,
                     int dest) {
  vector<bool> visited(V, false);
  stack<int> s;

  for (int i = 0; i < V; i++) {
    if (!visited[i])
      dfs(adj, s, visited, i);
  }

  vector<int> dist(V, INT_MAX);
  dist[src] = 0;

  while (!s.empty()) {
    int top = s.top();
    s.pop();

    if (dist[top] != INT_MAX) {
      for (auto &[curr, wt] : adj[top]) {
        int cost = dist[top] + wt;
        if (cost < dist[curr]) {
          dist[curr] = cost;
        }
      }
    }
  }
  return dist[dest];
}

void addEdge(vector<vector<pair<int, int>>> &adj, int u, int v, int w) {
  adj[u].push_back({v, w});
}

int main() {

  int V, E;
  cin >> V >> E;
  vector<vector<pair<int, int>>> adj(V);

  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    addEdge(adj, u, v, w);
  }

  // 6
  // 9
  // 0 1 5
  // 0 2 3
  // 1 2 2
  // 1 3 6
  // 2 3 7
  // 2 4 4
  // 2 5 2
  // 3 4 -1
  // 4 5 -2

  cout << shortestDistance(adj, V, 1, 5);

  return 0;
}