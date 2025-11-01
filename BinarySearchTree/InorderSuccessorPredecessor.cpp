#include <ios>
#include <iostream>
#include <stack>
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

  void inorder() {
    Node *curr = this->root;

    stack<Node *> s;

    while (curr != NULL || !s.empty()) {

      while (curr != NULL) {
        s.push(curr);
        curr = curr->left;
      }

      curr = s.top();
      s.pop();

      cout << curr->data << " ";

      curr = curr->right;
    }
  }

  int inorderSuccessor(int target) {
    Node *curr = this->root;
    Node *ans = NULL;

    while (curr != NULL) {
      if (curr->data > target) {
        ans = curr;
        curr = curr->left;
      } else {
        curr = curr->right;
      }
    }

    return ans ? ans->data : -1;
  }

  int inorderPred(int target) {
    Node *curr = this->root;

    Node *ans = NULL;

    while (curr != NULL) {
      if (curr->data < target) {
        ans = curr;
        curr = curr->right;
      } else {
        curr = curr->left;
      }
    }

    return ans ? ans->data : -1;
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
  // 5 3 7 2 4 6 9 1 8 10 -1
  //   b->print();
  b->inorder();

  cout << endl;
  int ans = b->inorderSuccessor(8);
  cout << "Inorder successor of 8 is : " << ans;

  cout << endl;
  ans = b->inorderPred(4);
  cout << "Inorder successor of 4 is : " << ans;
  return 0;
}