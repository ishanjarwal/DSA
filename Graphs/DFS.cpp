// DFS for a connected undirected graph;

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dfs(vector<vector<int>> &adj) {
  int V = adj.size();

  stack<int> s;
  vector<int> res;
  vector<bool> visited(V, false);

  s.push(0);
  visited[0] = true;

  while (!s.empty()) {
    int top = s.top();
    s.pop();

    res.push_back(top);

    for (int x : adj[top]) {
      if (!visited[x]) {
        visited[x] = true;
        s.push(x);
      }
    }
  }

  return res;
}

void addEdge(vector<vector<int>> &adj, int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main() {
  int V = 5;
  vector<vector<int>> adj(V);

  // creating adjacency list
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 0);
  addEdge(adj, 2, 0);
  addEdge(adj, 2, 3);
  addEdge(adj, 2, 4);

  // Perform DFS starting from the source vertex 0
  vector<int> res = dfs(adj);

  for (int x : res)
    cout << x << " ";
}