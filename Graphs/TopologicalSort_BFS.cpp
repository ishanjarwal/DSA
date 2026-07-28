#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void topologicalSort(const vector<vector<int>> &adj, int V) {
  queue<int> q;

  vector<int> inDeg(V, 0);
  for (auto &i : adj) {
    for (int j : i) {
      inDeg[j]++;
    }
  }

  for (int i = 0; i < V; i++) {
    if (inDeg[i] == 0)
      q.push(i);
  }

  while (!q.empty()) {
    int frnt = q.front();
    q.pop();
    cout << frnt << " ";

    for (int x : adj[frnt]) {
      inDeg[x]--;
      if (inDeg[x] == 0)
        q.push(x);
    }
  }
}
void addEdge(vector<vector<int>> &adj, int u, int v) { adj[u].push_back(v); }

int main() {
  int V = 5;
  vector<vector<int>> adj(V);
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 1, 4);
  addEdge(adj, 2, 4);
  addEdge(adj, 4, 3);

  topologicalSort(adj, V);

  return 0;
}