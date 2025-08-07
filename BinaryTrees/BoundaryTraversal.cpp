#include <cstddef>
#include <iostream>
#include <queue>

using namespace std;

class node {
public:
  int data;
  node *left;
  node *right;

  node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

node *buildFromLevelOrder() {
  queue<node *> q;
  int data;
  cout << "Enter data for root node : " << endl;
  cin >> data;
  node *root = new node(data);

  q.push(root);

  while (!q.empty()) {
    node *temp = q.front();
    q.pop();

    int left;
    cout << "Enter left data for " << temp->data << endl;
    cin >> left;

    if (left != -1) {
      temp->left = new node(left);
      q.push(temp->left);
    }

    int right;
    cout << "Enter right data for " << temp->data << endl;
    cin >> right;

    if (right != -1) {
      temp->right = new node(right);
      q.push(temp->right);
    }
  }
  return root;
};

void leftPart(node *root, vector<int> &result) {
  if (root == NULL || (root->left == NULL && root->right == NULL))
    return;
  result.push_back(root->data);
  if (root->left)
    leftPart(root->left, result);
  else
    leftPart(root->right, result);
}

void leafNodes(node *root, vector<int> &result) {
  if (root == NULL)
    return;
  leafNodes(root->left, result);
  if (root->left == NULL && root->right == NULL)
    result.push_back(root->data);
  leafNodes(root->right, result);
}

void rightPart(node *root, vector<int> &result) {
  if (root == NULL || (root->left == NULL && root->right == NULL))
    return;
  if (root->right)
    rightPart(root->right, result);
  else
    rightPart(root->left, result);
  result.push_back(root->data); // reverse order
}

vector<int> boundaryTraversal(node *root) {
  vector<int> result;
  if (root == NULL)
    return result;

  // Add root only if it's not a leaf
  if (!(root->left == NULL && root->right == NULL))
    result.push_back(root->data);

  leftPart(root->left, result);
  leafNodes(root, result);
  rightPart(root->right, result);

  return result;
}

int main() {

  // 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
  node *root = buildFromLevelOrder();
  vector<int> result = boundaryTraversal(root);
  for (auto i : result) {
    cout << i << " ";
  }
}