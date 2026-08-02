#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<vector<int>> &adj, vector<int> &disc, vector<int> &low,
         vector<int> &parent, vector<bool> &visited,
         vector<pair<int, int>> &bridges, int node, int &timer) {
  visited[node] = true;
  disc[node] = low[node] = timer++;

  for (int neighbor : adj[node]) {

    // skip parent
    if (neighbor == parent[node])
      continue;

    // not parent but visited, update low
    if (visited[neighbor]) {
      low[node] = min(low[node], disc[neighbor]);
    } else {
      // update parent, recurse and update the low
      parent[neighbor] = node;
      dfs(adj, disc, low, parent, visited, bridges, neighbor, timer);
      low[node] = min(low[node], low[neighbor]);

      //   bridge condition
      if (low[neighbor] > disc[node]) {
        bridges.push_back({node, neighbor});
      }
    }
  }
}

vector<pair<int, int>> tarjan(const vector<vector<int>> &adj, int V) {
  vector<int> disc(V, -1), low(V, -1), parent(V, -1);
  vector<bool> visited(V, false);
  vector<pair<int, int>> bridges;
  int timer = 0;

  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      dfs(adj, disc, low, parent, visited, bridges, i, timer);
    }
  }

  return bridges;
}

void addEdge(vector<vector<int>> &adj, int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u); // comment for directed graph
}

int main() {

  int V, E;
  cin >> V >> E;
  vector<vector<int>> adj(V);

  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    addEdge(adj, u, v);
  }

  vector<pair<int, int>> bridges = tarjan(adj, V);
  cout << "Bridges in the Graph : " << endl;
  for (int i = 0; i < bridges.size(); i++)
    cout << bridges[i].first << "-" << bridges[i].second << endl;

  return 0;
}

// 5
// 5
// 0 1
// 1 2
// 0 2
// 0 3
// 3 4