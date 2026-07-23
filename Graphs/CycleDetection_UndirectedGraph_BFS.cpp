#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool cycleDetectionUtil(const vector<vector<int>> &adj, vector<bool> &visited) {
  queue<pair<int, int>> q;
  vector<int> res;

  q.push({0, -1});
  visited[0] = true;

  while (!q.empty()) {
    auto [node, parent] = q.front();
    q.pop();
    for (int x : adj[node]) {
      if (!visited[x]) {
        q.push({x, node});
        visited[x] = true;
      } else if (x != parent) {
        return true;
      }
    }
  }

  return false;
}

bool cycleDetection(const vector<vector<int>> &adj, int V) {
  vector<bool> visited(V, false);
  for (int i = 0; i < V; i++) {
    if (!visited[i] && cycleDetectionUtil(adj, visited)) {
      return true;
    }
  }
  return false;
}

void addEdge(vector<vector<int>> &adj, int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main() {
  int V = 6;
  vector<vector<int>> adj(V);

  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 3, 4);
  addEdge(adj, 3, 5);
  addEdge(adj, 5, 3);

  bool res = cycleDetection(adj, V);
  cout << (res ? "Cycle is present" : "Cycle is not present") << endl;

  return 0;
}