#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Node {
public:
  bool isEnd;
  int childCount;
  Node *children[26];

  Node() {
    isEnd = false;
    childCount = 0;
    for (int i = 0; i < 26; i++) {
      this->children[i] = nullptr;
    }
  }
};

class Trie {
public:
  Node *root;

  Trie() { this->root = new Node(); }

  void insertUtil(Node *root, const string &word, int i) {
    if (i == word.length()) {
      root->isEnd = true;
      return;
    }

    int idx = word[i] - 'a';
    if (root->children[idx] == nullptr) {
      root->children[idx] = new Node();
      root->children[idx]->childCount++;
    }

    insertUtil(root->children[idx], word, i + 1);
  }

  void insert(string word) { insertUtil(this->root, word, 0); }

  void printSuggestions(Node *curr, vector<string> &temp, string prefix) {
    if (curr->isEnd) {
      temp.push_back(prefix);
    }

    for (int i = 0; i < 26; i++) {
      Node *next = curr->children[i];
      if (next) {
        prefix.push_back('a' + i);
        printSuggestions(next, temp, prefix);
        prefix.pop_back();
      }
    }
  }

  vector<vector<string>> getSuggestions(const string &query) {
    Node *prev = this->root;
    vector<vector<string>> ans;
    string prefix = "";
    for (int i = 0; i < query.length(); i++) {
      char lastChar = query[i];
      prefix.push_back(lastChar);

      // check if prev has the last character
      Node *curr = prev->children[lastChar - 'a'];
      if (!curr) {
        break;
      }
      vector<string> temp;
      printSuggestions(curr, temp, prefix);
      ans.push_back(temp);
      // move the prev counter forward
      temp.clear();
      prev = curr;
    }

    return ans;
  }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList,
                                      string &queryStr) {
  Trie *t = new Trie();
  for (auto word : contactList) {
    t->insert(word);
  }

  return t->getSuggestions(queryStr);
}