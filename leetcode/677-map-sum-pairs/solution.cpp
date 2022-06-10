#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct TrieNode {
  int val = 0;
  vector<TrieNode *> children;
  TrieNode() : children(26, nullptr) {}
};
class MapSum {
  TrieNode *root;
  unordered_map<string, int> str2val;
public:
  MapSum() : root(new TrieNode) {}

  void insert(string key, int val) {
    // overridde
    int delta = val;
    if(str2val.count(key))
      delta -= str2val[key];
    str2val[key] = val;
    auto node = this -> root;
    for (auto c : key) {
      int idx = c - 'a';
      if (!node -> children[idx])
        node -> children[idx] = new TrieNode();
      node = node -> children[idx];
      node -> val += delta;
    }
  }

  int sum(string prefix) {
    auto node = this->root;
    for (auto c : prefix) {
      int idx = c - 'a';
      if (!node -> children[idx])
        return 0;
      node = node -> children[idx];
    }
    return node -> val;
  }
};