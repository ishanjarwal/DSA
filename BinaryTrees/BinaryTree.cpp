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

void levelOrderTraversal(node *root) {
  queue<node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    node *temp = q.front();

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

    q.pop();
  }
}

void inorder(node *root) {
  if (root == NULL)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void preorder(node *root) {
  if (root == NULL)
    return;

  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(node *root) {
  if (root == NULL)
    return;

  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

int main() {
  node *root = buildTree();
  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  // levelOrderTraversal(root);

  cout << endl;

  cout << "In-Order Traversal : ";
  inorder(root);

  cout << endl;

  cout << "Pre-Order Traversal : ";
  preorder(root);

  cout << endl;

  cout << "Post-Order Traversal : ";
  postorder(root);
}