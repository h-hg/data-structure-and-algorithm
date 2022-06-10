#include <string>
#include <vector>
using namespace std;
class Trie {
  vector<Trie*> children;
  bool isEnd = false;
  
  Trie* searchPrefix(string const &str) {
    auto root = this;
    for(auto c: str) {
      int idx = c - 'a';
      if(!root -> children[idx])
        return nullptr;
      root = root -> children[idx];
    }
    return root;
  }
public:
  Trie() : children(26, nullptr) {}
  
  void insert(string word) {
    auto root = this;
    for(auto c : word) {
      int idx = c - 'a';
      if(!root->children[idx])
        root -> children[idx] = new Trie();
      root = root -> children[idx];
    }
    root -> isEnd = true;
  }
  
  bool search(string word) {
    auto node = searchPrefix(word);
    return node && node -> isEnd;
  }
  
  bool startsWith(string prefix) {
    return searchPrefix(prefix);
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */