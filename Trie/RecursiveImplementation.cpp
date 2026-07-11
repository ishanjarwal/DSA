#include <iostream>
#include <string>
using namespace std;

const int ALPHABET_RANGE = 26;

class Node {
public:
  bool isTerminal;
  int childCount;
  Node *children[26];

  Node() {
    isTerminal = false;
    childCount = 0;
    for (int i = 0; i < ALPHABET_RANGE; i++) {
      children[i] = nullptr;
    }
  }
};

class Trie {
private:
  void destroy(Node *root) {
    if (root == nullptr)
      return;

    for (int i = 0; i < ALPHABET_RANGE; i++) {
      destroy(root->children[i]);
    }

    delete root;
  }

public:
  Node *root;

  Trie() { this->root = new Node(); }

  ~Trie() { destroy(this->root); }

  void insertUtil(Node *root, const string &word, int idx) {
    if (idx == word.length()) {
      root->isTerminal = true;
      return;
    }

    if (root->children[word[idx] - 'a'] == nullptr) {
      root->children[word[idx] - 'a'] = new Node();
      root->childCount++;
    }

    insertUtil(root->children[word[idx] - 'a'], word, idx + 1);
  }

  void insert(string word) {
    cout << "Inserting " << word << endl;
    insertUtil(this->root, word, 0);
  }

  bool searchUtil(Node *root, const string &word, int idx) {
    if (idx == word.length()) {
      return root->isTerminal;
    }

    if (root->children[word[idx] - 'a'] == nullptr) {
      return false;
    }

    return searchUtil(root->children[word[idx] - 'a'], word, idx + 1);
  }

  bool search(string word) { return searchUtil(this->root, word, 0); }

  bool startsWithUtil(Node *root, const string &word, int idx) {
    if (idx == word.length()) {
      return true;
    }

    if (root->children[word[idx] - 'a'] == nullptr) {
      return false;
    }

    return startsWithUtil(root->children[word[idx] - 'a'], word, idx + 1);
  }

  bool startsWith(string word) { return startsWithUtil(this->root, word, 0); }

  // isLeaf is not needed if you use childCount
  bool isLeaf(Node *root) {
    for (int i = 0; i < ALPHABET_RANGE; i++) {
      if (root->children[i] != nullptr) {
        return false;
      }
    }
    return true;
  }

  bool deleteWordUtil(Node *root, const string &word, int idx) {
    if (root == nullptr)
      return false;

    if (idx == word.length()) {
      if (!root->isTerminal)
        return false;
      root->isTerminal = false;
      return root->childCount == 0;
    }

    if (root->children[word[idx] - 'a'] == nullptr)
      return false;

    if (deleteWordUtil(root->children[word[idx] - 'a'], word, idx + 1)) {
      delete root->children[word[idx] - 'a'];
      root->children[word[idx] - 'a'] = nullptr;
      root->childCount--;
    }

    return !root->isTerminal && root->childCount == 0;
  }

  void deleteWord(string word) {
    cout << "Deleting " << word << endl;
    bool res = deleteWordUtil(this->root, word, 0);
    return;
  }
};

int main() {
  Trie *t = new Trie();

  t->insert("coding");
  t->insert("code");
  t->insert("coly");
  t->insert("cod");
  t->insert("codding");

  cout << "is coding present : " << t->search("coding") << endl;
  cout << "is coly present : " << t->search("coly") << endl;
  cout << "is coder present : " << t->search("coder") << endl;

  cout << "does any word start with co :" << t->startsWith("co") << endl;

  t->deleteWord("code");

  cout << "is code present : " << t->search("code") << endl;
  cout << "is coding present : " << t->search("coding") << endl;
  cout << "is coly present : " << t->search("coly") << endl;
  cout << "is coder present : " << t->search("coder") << endl;

  return 0;
}