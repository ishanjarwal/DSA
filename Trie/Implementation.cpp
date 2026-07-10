#include <iostream>
using namespace std;

int charToIndex(char ch) { return ch - 'a'; }

class TrieNode {
public:
  char data;
  TrieNode *children[26];
  bool isTerminal;

  TrieNode(char ch) {
    this->data = ch;
    isTerminal = false;
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
  }

  // Destructor: Automatically cleans up all allocated child nodes recursively
  ~TrieNode() {
    for (int i = 0; i < 26; i++) {
      if (children[i] != nullptr) {
        delete children[i];
      }
    }
  }
};

class Trie {
public:
  TrieNode *root;

  Trie() { this->root = new TrieNode('\0'); }

  // Destructor: Deletes the root node, which cascades down to all nodes
  ~Trie() { delete root; }

  // Optimized: Passed by const reference
  void insert(const string &word) {
    TrieNode *curr = this->root;
    for (auto ch : word) {
      int idx = charToIndex(ch);
      if (curr->children[idx] == nullptr)
        curr->children[idx] = new TrieNode(ch);

      curr = curr->children[idx];
    }
    curr->isTerminal = true;
  }

  // Optimized: Passed by const reference and fixed redundant index checking
  bool search(const string &word) {
    TrieNode *curr = this->root;
    int l = word.length();

    for (int i = 0; i < l; i++) {
      char ch = word[i];
      int idx = charToIndex(ch);

      if (curr->children[idx] == nullptr)
        return false;

      curr = curr->children[idx];
    }
    return curr->isTerminal;
  }

  // Optimized: Passed by const reference
  bool startsWith(const string &prefix) {
    TrieNode *curr = this->root;
    int l = prefix.length();

    for (int i = 0; i < l; i++) {
      char ch = prefix[i];
      int idx = charToIndex(ch);

      if (curr->children[idx] == nullptr)
        return false;

      curr = curr->children[idx];
    }
    return true;
  }

  bool hasNoChildren(TrieNode *node) {
    if (node == nullptr)
      return true;

    for (int i = 0; i < 26; i++) {
      if (node->children[i] != nullptr)
        return false;
    }
    return true;
  }

  bool deleteWordUtil(TrieNode *curr, const string &word, int i) {
    if (curr == nullptr)
      return false;

    // end letter of the word is reached
    if (i == word.length()) {
      curr->isTerminal = false;
      return hasNoChildren(curr);
    }

    int idx = charToIndex(word[i]);

    if (deleteWordUtil(curr->children[idx], word, i + 1)) {
      // Deleting a child will NOT trigger its sibling deletion because
      // the child destructor only handles its own downstream array.
      delete curr->children[idx];
      curr->children[idx] = nullptr;

      return (!curr->isTerminal && hasNoChildren(curr));
    }

    return false;
  }

  void deleteWord(const string &word) {
    // Root should never be deleted or set to nullptr
    deleteWordUtil(root, word, 0);
  }
};

int main() {
  Trie *obj = new Trie();
  obj->insert("bug");
  obj->insert("cat");
  obj->insert("fridge");

  cout << "\"bug\" search : " << obj->search("bug") << endl;
  cout << "\"fri\" startsWith : " << obj->startsWith("fri") << endl;
  cout << "\"dog\" search : " << obj->search("dog") << endl;
  cout << "\"frik\" startsWith : " << obj->startsWith("frik") << endl;

  cout << "Deleting bug" << endl;
  obj->deleteWord("bug");

  cout << "\"bug\" search : " << obj->search("bug") << endl;

  // Clean up the Trie container itself from the heap
  delete obj;
  return 0;
}
