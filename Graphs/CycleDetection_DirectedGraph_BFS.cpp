#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool detectCycle(const vector<vector<int>> &adj, int V) {
  vector<int> inDeg(V, 0);
  queue<int> q;

  for (auto &i : adj) {
    for (int j : i) {
      inDeg[j]++;
    }
  }
  for (int i = 0; i < V; i++) {
    if (inDeg[i] == 0)
      q.push(i);
  }

  int count = 0;
  while (!q.empty()) {
    int frnt = q.front();
    q.pop();
    count++;

    for (int x : adj[frnt]) {
      inDeg[x]--;
      if (inDeg[x] == 0) {
        q.push(x);
      }
    }
  }

  return count != V;
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

  cout << (detectCycle(adj, V) ? "Cycle is present" : "Cycle is not present")
       << endl;

  return 0;
}