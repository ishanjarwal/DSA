#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;
  Node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

class BST {
public:
  Node *root;

  BST() { this->root = NULL; }

  Node *insert(Node *root, int data) {
    if (root == NULL) {
      root = new Node(data);
      return root;
    }

    if (data < root->data) {
      root->left = insert(root->left, data);
    } else {
      root->right = insert(root->right, data);
    }
    return root;
  }

  void generate() {
    int data;

    while (true) {
      cout << "Enter value : ";
      cin >> data;
      if (data == -1)
        break;
      root = this->insert(this->root, data);
    }
  }

  int minValue() {
    Node *temp = this->root;
    while (temp->left != NULL) {
      temp = temp->left;
    }

    return temp->data;
  }

  int maxValue() {
    Node *temp = this->root;
    while (temp->right != NULL) {
      temp = temp->right;
    }

    return temp->data;
  }

  ~BST() { clear(root); }

  void clear(Node *root) {
    if (!root)
      return;
    clear(root->left);
    clear(root->right);
    delete root;
  }
};

int main() {

  BST *b = new BST();
  b->generate();
  // 10 8 21 7 27 5 4 3 -1

  cout << endl;

  cout << "Minimum value in BST : " << b->minValue();
  cout << endl;
  cout << "Maximum value in BST : " << b->maxValue();
  return 0;
}