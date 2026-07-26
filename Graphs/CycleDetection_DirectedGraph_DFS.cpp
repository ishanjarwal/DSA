#include <iostream>
#include <vector>
using namespace std;

bool cycleDetectionUtil(vector<vector<int>> &adj, vector<bool> &visited,
                        vector<bool> &dfsVisited, int x) {
  visited[x] = true;
  dfsVisited[x] = true;
  for (int k : adj[x]) {
    if (!visited[k] && cycleDetectionUtil(adj, visited, dfsVisited, k)) {
      return true;
    } else if (dfsVisited[k]) {
      return true;
    }
  }
  dfsVisited[x] = false;
  return false;
}

bool cycleDetection(vector<vector<int>> &adj, int V) {
  vector<bool> visited(V, false);
  vector<bool> dfsVisited(V, false);

  for (int i = 0; i < V; i++) {
    if (!visited[i] && cycleDetectionUtil(adj, visited, dfsVisited, i))
      return true;
  }
  return false;
}

void addEdge(vector<vector<int>> &adj, int u, int v) { adj[u].push_back(v); }

int main() {
  int V = 8;
  vector<vector<int>> adj(V);
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 3);
  addEdge(adj, 2, 6);
  addEdge(adj, 2, 7);
  addEdge(adj, 3, 4);
  addEdge(adj, 4, 5);
  addEdge(adj, 5, 3);
  addEdge(adj, 7, 6);

  bool res = cycleDetection(adj, V);
  cout << (res ? "Cycle is present" : "Cycle is not present") << endl;

  return 0;
}