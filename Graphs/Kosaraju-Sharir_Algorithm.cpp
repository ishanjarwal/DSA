#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void topologicalSort(const vector<vector<int>> &adj, int src,
                     vector<bool> &visited, stack<int> &s) {
  visited[src] = true;

  for (int nbr : adj[src]) {
    if (!visited[nbr]) {
      topologicalSort(adj, nbr, visited, s);
    }
  }

  s.push(src);
}

void dfs(const vector<vector<int>> &adj, int src, vector<bool> &visited,
         vector<int> &scc) {
  visited[src] = true;
  scc.push_back(src);

  for (int nbr : adj[src]) {
    if (!visited[nbr]) {
      dfs(adj, nbr, visited, scc);
    }
  }
}

vector<vector<int>> kosaraju(vector<vector<int>> &adj, int V) {
  vector<vector<int>> ans;
  stack<int> s;
  vector<bool> visited(V, false);

  //   topological sort via dfs
  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      topologicalSort(adj, i, visited, s);
    }
  }

  // transpose graph
  vector<vector<int>> transposeGraph(V);
  for (int u = 0; u < V; u++) {
    visited[u] = false;
    for (int v : adj[u]) {
      transposeGraph[v].push_back(u);
    }
  }

  // dfs call using stack
  while (!s.empty()) {
    int top = s.top();
    s.pop();

    if (!visited[top]) {
      vector<int> scc;
      dfs(transposeGraph, top, visited, scc);
      ans.push_back(scc);
    }
  }

  return ans;
}

void addEdge(vector<vector<int>> &adj, int u, int v) { adj[u].push_back(v); }

int main() {

  int V, E;
  cin >> V >> E;
  vector<vector<int>> adj(V);

  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    addEdge(adj, u, v);
  }

  vector<vector<int>> scc = kosaraju(adj, V);
  cout << "Strongly Connected Components in the Graph : " << endl;
  for (vector<int> i : scc) {
    for (int x : i) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}

// 5
// 5
// 0 2
// 2 1
// 1 0
// 2 3
// 3 4
