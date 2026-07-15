#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class Graph {
public:
  unordered_map<int, list<int>> adj;
  bool directed;

  Graph(bool directed = false) { this->directed = directed; }

  void addEdge(int u, int v) {
    adj[u].push_back(v);
    if (!this->directed) {
      adj[v].push_back(u);
    }
  }

  void print() {
    for (const auto &[key, nodeList] : this->adj) {
      cout << key << " -> ";
      for (int node : nodeList) {
        cout << node << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  Graph *g = new Graph(true);
  g->addEdge(0, 1);
  g->addEdge(0, 2);
  g->addEdge(1, 3);
  g->addEdge(1, 2);
  g->addEdge(3, 1);

  g->print();
  return 0;
}