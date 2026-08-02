#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<vector<int>> &adj, vector<int> &disc, vector<int> &low,
         vector<int> &parent, vector<bool> &visited, vector<int> &points,
         int node, int &timer) {
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
      dfs(adj, disc, low, parent, visited, points, neighbor, timer);
      low[node] = min(low[node], low[neighbor]);

      //   articulation point condition
      if (low[neighbor] >= disc[node] && parent[node] != -1) {
        points.push_back(node);
      }
    }
  }

  if (parent[node] == -1 && adj[node].size() > 1) {
    points.push_back(node);
  }
}

vector<int> articulationPoints(const vector<vector<int>> &adj, int V) {
  vector<int> disc(V, -1), low(V, -1), parent(V, -1);
  vector<bool> visited(V, false);
  vector<int> points;
  int timer = 0;

  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      dfs(adj, disc, low, parent, visited, points, i, timer);
    }
  }

  return points;
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

  vector<int> points = articulationPoints(adj, V);
  cout << "Articulation Points in the Graph : " << endl;
  for (int i = 0; i < points.size(); i++)
    cout << points[i] << " " << endl;

  return 0;
}

// 5
// 5
// 0 1
// 1 2
// 0 4
// 0 3
// 3 4