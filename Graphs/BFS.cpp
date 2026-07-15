// BFS for an Undirected and Connected Graph (meaning all nodes have atleast one
// edge)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfs(vector<vector<int>> &adjList) {
  vector<int> traversed;
  vector<bool> visited(adjList.size());
  queue<int> q;

  q.push(0);
  visited[0] = true;

  while (!q.empty()) {
    int frnt = q.front();
    q.pop();
    traversed.push_back(frnt);

    for (int x : adjList[frnt]) {
      if (!visited[x]) {
        q.push(x);
        visited[x] = true;
      }
    }
  }
  return traversed;
};

void addEdge(vector<vector<int>> &adj, int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main() {
  int V = 5;
  vector<vector<int>> adj(V);

  addEdge(adj, 1, 2);
  addEdge(adj, 1, 0);
  addEdge(adj, 2, 0);
  addEdge(adj, 2, 3);
  addEdge(adj, 2, 4);

  vector<int> res = bfs(adj);

  for (int i : res)
    cout << i << " ";

  return 0;
}