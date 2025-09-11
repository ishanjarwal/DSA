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

node *buildTree() {

  int data;
  cout << "Enter data for node : ";
  cin >> data;

  if (data == -1) {
    return NULL;
  }

  node *root = new node(data);

  cout << "Enter data for left of " << root->data << endl;
  cout << "  ";
  root->left = buildTree();

  cout << "Enter data for right of " << root->data << endl;
  cout << "  ";
  root->right = buildTree();

  return root;
}

node *findPredeccesar(node *&curr) {
  node *pred = curr->left;
  while (pred->right != NULL && pred->right != curr) {
    pred = pred->right;
  }
  return pred;
}

void morrisTraversal(node *&root) {
  node *curr = root;
  while (curr != NULL) {
    if (!curr->left) {
      cout << curr->data << " ";
      curr = curr->right;
    } else {
      node *pred = findPredeccesar(curr);
      if (pred->right == NULL) {
        pred->right = curr;
        curr = curr->left;
      } else {
        pred->right = NULL;
        cout << curr->data << " ";
        curr = curr->right;
      }
    }
  }
}

int main() {
  node *root = buildTree();
  // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
  cout << endl << "Morris Traversal for Inorder : ";
  morrisTraversal(root);
}