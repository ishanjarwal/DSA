#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void topologicalSortUtil(vector<vector<int>> &adj, int node, stack<int> &s,
                         vector<bool> &visited) {
  visited[node] = true;

  for (int x : adj[node]) {
    if (!visited[x]) {
      topologicalSortUtil(adj, x, s, visited);
    }
  }
  s.push(node);
}

void topologicalSort(vector<vector<int>> &adj, int V) {
  stack<int> s;
  vector<bool> visited(V, false);

  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      topologicalSortUtil(adj, i, s, visited);
    }
  }

  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
}

void addEdge(vector<vector<int>> &adj, int u, int v) { adj[u].push_back(v); }

int main() {
  int V = 4;
  vector<vector<int>> adj(V);

  addEdge(adj, 0, 1);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 2);
  addEdge(adj, 3, 2);

  topologicalSort(adj, V);

  return 0;
}