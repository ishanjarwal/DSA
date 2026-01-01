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


  Node* inorderPred(Node* &root,int target) {
    Node *ans = NULL;

    while (root != NULL) {
      if (root->data < target) {
        ans = root;
        root = root->right;
      } else {
        root = root->left;
      }
    }

    return ans;
  }


  Node* delete(Node* root, int data){
    if(root == NULL) return NULL;

    if(root->data == data){
        // case 1 : 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // case 2 : 1 child
        // left child
        if(root->right == NULL && root->left != NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }


        // case 3 : 2 child
        if(root->left != NULL && root->right != NULL){
            // taking the inorder predecessar
            Node* temp = root->left;
            while(temp->right != NULL){
                temp = temp->right;
            }

            root->data = temp->data;
            root->left = delete(root->left, temp->data);
            return root;
        }
    }

    if(root->data < data){
        // move to the right
        root->right = delete(root->right, data);
        return root;
    }

    if(root->data > data){
        // move to the left
        root->left = delete(root->left, data);
        return root;
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