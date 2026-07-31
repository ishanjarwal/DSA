#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> shortestPath(const vector<vector<int>> &adj, int V, int src,
                         int dest) {
  vector<int> res;
  vector<bool> visited(V, false);
  queue<int> q;
  vector<int> parent(V);

  visited[src] = true;
  q.push(src);
  parent[src] = -1;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    if (node == dest)
      break;

    for (int neighbor : adj[node]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        parent[neighbor] = node;
        q.push(neighbor);
      }
    }
  }

  if (!visited[dest])
    return {};

  for (int cur = dest; cur != -1; cur = parent[cur])
    res.push_back(cur);

  reverse(res.begin(), res.end());

  return res;
}

void addEdge(vector<vector<int>> &adj, int u, int v) {
  adj[u - 1].push_back(v - 1);
  adj[v - 1].push_back(u - 1); // comment for directed graph
}

int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int>> adj(V);

  for (int i = 0; i < E; i++) {
    int x, y;
    cin >> x >> y;
    addEdge(adj, x, y);
  }

  vector<int> path = shortestPath(adj, V, 1, 5);
  for (int x : path) {
    cout << x + 1 << " ";
  }
}

// Undirected input
//   8
//   9
//   1 2
//   1 3
//   1 4
//   2 5
//   5 8
//   3 8
//   4 6
//   6 7
//   7 8

// Directed Input
// 6
// 9
// 1 2
// 1 3
// 2 4
// 2 3
// 3 4
// 3 5
// 3 6
// 4 5
// 5 6