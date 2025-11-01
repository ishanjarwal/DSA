#include <iostream>
#include <queue>
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

  void print() {
    cout << endl;
    printRec(this->root);
  }

  void printRec(Node *root) {
    if (root == NULL)
      return;
    cout << root->data << " ";

    printRec(root->left);
    printRec(root->right);
  }

  void levelOrder() {
    cout << endl;
    queue<Node *> q;
    q.push(this->root);
    q.push(NULL);

    while (!q.empty()) {
      Node *front = q.front();
      q.pop();

      if (front == NULL) {
        cout << endl;
        if (!q.empty()) {
          q.push(NULL);
        }
      } else {

        cout << front->data << " ";

        if (front->left != NULL) {
          q.push(front->left);
        }
        if (front->right != NULL) {
          q.push(front->right);
        }
      }
    }
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
  //   b->print();
  b->levelOrder();
  return 0;
}