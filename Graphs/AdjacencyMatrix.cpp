#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createGraph(int v, vector<pair<int, int>> &edges) {
  int size = edges.size();
  vector<vector<int>> matrix(v, vector<int>(v, 0));
  for (int i = 0; i < size; i++) {
    int u = edges[i].first;
    int v = edges[i].second;
    matrix[u][v] = 1;

    // for undirected graphs
    // matrix[v][u] = 1;
  }

  return matrix;
}

int main() {
  int v = 3;

  // List of edges {u,v} or node pairs
  vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {1, 0},
                                  {2, 1}, {0, 0}, {1, 1}, {2, 2}};

  vector<vector<int>> matrix = createGraph(v, edges);

  cout << "Adjacency Matrix Representation:" << endl;
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }

  return 0;
}