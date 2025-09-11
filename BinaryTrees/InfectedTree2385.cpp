#include <cstddef>
#include <ios>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void printMap(const map<TreeNode *, TreeNode *> &mp) {
  for (const auto &entry : mp) {
    TreeNode *key = entry.first;
    TreeNode *value = entry.second;

    cout << "Node : ";
    if (key)
      cout << key->val;
    else
      cout << "NULL";

    cout << " -> Parent: ";
    if (value)
      cout << value->val;
    else
      cout << "NULL";

    cout << endl;
  }
}
void nodeToParent(map<TreeNode *, TreeNode *> &m, TreeNode *&root,
                  TreeNode *parent) {
  if (root == NULL) {
    return;
  }
  m[root] = parent;
  nodeToParent(m, root->left, root);
  nodeToParent(m, root->right, root);
}

TreeNode *goToTarget(TreeNode *root, int target) {
  if (root == nullptr)
    return nullptr;

  if (root->val == target)
    return root;

  TreeNode *left = goToTarget(root->left, target);
  if (left != nullptr)
    return left;

  return goToTarget(root->right, target);
}

int solve(map<TreeNode *, TreeNode *> &nodeToParent, TreeNode *&root,
          int start) {
  int time = 0;
  queue<TreeNode *> q;
  map<TreeNode *, bool> visited;

  TreeNode *startNode = goToTarget(root, start);

  q.push(startNode);
  visited[startNode] = true;

  while (!q.empty()) {
    bool isAdded = false;
    int size = q.size();
    for (int i = 0; i < size; i++) {
      TreeNode *temp = q.front();
      q.pop();

      if (temp->left && !visited[temp->left]) {
        visited[temp->left] = true;
        q.push(temp->left);
        isAdded = true;
      }

      if (temp->right && !visited[temp->right]) {
        visited[temp->right] = true;
        q.push(temp->right);
        isAdded = true;
      }

      TreeNode *p = nodeToParent[temp];
      if (p && !visited[p]) {
        visited[nodeToParent[temp]] = true;
        q.push(nodeToParent[temp]);
        isAdded = true;
      }
    }

    if (isAdded) {
      time++;
    }
  };

  return time;
}

int main() {

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(7);
  root->left->right->left = new TreeNode(8);
  root->right->right = new TreeNode(6);
  root->right->right->right = new TreeNode(9);
  root->right->right->right->right = new TreeNode(10);

  // create the map
  map<TreeNode *, TreeNode *> m;
  nodeToParent(m, root, NULL);
  printMap(m);
  int time = solve(m, root, 8);
  cout << "Total infection time : " << time << " seconds";

  return 0;
}