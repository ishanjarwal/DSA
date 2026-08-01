#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
public:
  vector<int> parent;
  vector<int> rank;
  UnionFind(int size) {
    parent.resize(size + 1);
    rank.resize(size + 1);

    parent[0] = -1;
    rank[0] = -1;
    for (int i = 1; i < size + 1; i++) {
      parent[i] = i;
      rank[i] = 0;
    }
  }

  int findParent(int x) {
    if (parent[x] == x)
      return x;

    return parent[x] = findParent(parent[x]);
  }

  void unite(int u, int v) {
    int parU = findParent(u);
    int parV = findParent(v);

    if (parU == parV)
      return;

    if (rank[parU] > rank[parV]) {
      parent[parV] = parU;
    } else if (rank[parU] < rank[parV]) {
      parent[parU] = parV;
    } else {
      parent[parV] = parU;
      rank[parU]++;
    }
  }

  void print() {
    for (int i = 1; i < parent.size(); i++)
      findParent(i); // Compress all paths

    for (int i = 1; i < parent.size(); i++)
      cout << parent[i] << " ";
  }
};

int main() {

  UnionFind uf(7);

  uf.unite(1, 2);
  uf.unite(2, 3);
  uf.unite(4, 5);
  uf.unite(6, 7);
  uf.unite(5, 6);
  uf.unite(3, 7);

  uf.print();

  return 0;
}