#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
public:
  vector<int> representative;

  //   Each one is the representative of its own by default
  UnionFind(int size) {
    representative.resize(size);

    for (int i = 0; i < size; i++) {
      representative[i] = i;
    }
  }

  //   Find the representative of the set that contains i
  int find(int i) {
    if (representative[i] == i)
      return i;

    return find(representative[i]);
  }

  void unite(int x, int y) {
    int representativeX = find(x);
    int representativeY = find(y);

    representative[representativeY] = representativeX;
  }
};

int main() {
  int size = 5;
  UnionFind uf(size);
  uf.unite(1, 2);
  uf.unite(3, 4);

  bool inSameSet = (uf.find(1) == uf.find(2));
  cout << "Are 1 and 2 in the same set? " << (inSameSet ? "Yes" : "No") << endl;

  inSameSet = (uf.find(1) == uf.find(3));
  cout << "Are 1 and 3 in the same set? " << (inSameSet ? "Yes" : "No") << endl;

  inSameSet = (uf.find(3) == uf.find(4));
  cout << "Are 3 and 4 in the same set? " << (inSameSet ? "Yes" : "No") << endl;
}