// DFS for a connected undirected graph;

#include <iostream>
#include <vector>
using namespace std;

void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int src,
            vector<int> &res) {

  visited[src] = 1;
  res.push_back(src);

  for (int x : adj[src]) {
    if (!visited[x]) {
      dfsRec(adj, visited, x, res);
    }
  }

  return;
}

vector<int> dfs(vector<vector<int>> &adj) {
  int V = adj.size();
  vector<int> res;
  vector<bool> visited(V, false);

  dfsRec(adj, visited, 0, res);

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

  for (int i = 0; i < V; i++)
    cout << res[i] << " ";
}