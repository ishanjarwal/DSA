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

void levelOrderTraversal(node *root) {

  if (root == NULL)
    return;

  queue<node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    node *temp = q.front();
    q.pop();

    if (temp == NULL) {
      cout << endl;
      if (!q.empty()) {
        q.push(NULL);
      }
    } else {
      cout << temp->data << " ";
      if (temp->left) {
        q.push(temp->left);
      }
      if (temp->right) {
        q.push(temp->right);
      }
    }
  }
}

int main() {

  // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
  node *root = buildFromLevelOrder();
  levelOrderTraversal(root);

  cout << endl;
}