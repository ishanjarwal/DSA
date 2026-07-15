#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfsDisconnected(const vector<vector<int>> &adjList, vector<bool> &visited,
                     int src, vector<int> &res) {
  queue<int> q;
  visited[src] = true;
  q.push(src);

  while (!q.empty()) {
    int frnt = q.front();
    q.pop();
    res.push_back(frnt);

    for (int x : adjList[frnt]) {
      if (!visited[x]) {
        visited[x] = true;
        q.push(x);
      }
    }
  }
}

vector<int> bfs(const vector<vector<int>> &adjList, int V) {
  vector<int> res;
  vector<bool> visited(V, false);

  for (int i = 0; i < V; i++) {
    if (!visited[i])
      bfsDisconnected(adjList, visited, i, res);
  }
  return res;
}

void addEdge(vector<vector<int>> &adjList, int u, int v) {
  adjList[u].push_back(v);
  adjList[v].push_back(u);
}

int main() {
  int V = 6;
  vector<vector<int>> adjList(V);

  addEdge(adjList, 1, 2);
  addEdge(adjList, 2, 0);
  addEdge(adjList, 0, 3);
  addEdge(adjList, 4, 5);

  vector<int> res = bfs(adjList, V);

  for (int i : res)
    cout << i << " ";

  return 0;
}