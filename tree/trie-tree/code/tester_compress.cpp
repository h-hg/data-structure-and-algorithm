#include <iostream>
#include <queue>
#include <string>

#include "compress-trie-tree.hpp"
using namespace std;
template <typename T>
class Tester: public CompressTrieTree<T> {
public:
  using CompressTrieTree<T>::CompressTrieTree;

  void print() const {
    queue<int> q;
    q.push(0);
    while(q.size()) {
      for(int i = 0, n = q.size(); i < n; ++i) {
        auto idx = q.front();
        q.pop();
        auto &node = CompressTrieTree<T>::_tree[idx];

        print(node);
        cout << ' ';
        
        for(auto &p : node.children)
          q.push(p.second);
      }
      cout << endl;
    }
  }
private:
  void print(Node<T> const &node) const {
    cout << '"';
    for(int i = node.st; i < node.ed; ++i)
      cout << CompressTrieTree<T>::_buff[i];
    cout << '"' << "[" << node.st << "," << node.ed << ")" << "<" << node.finish << ">";
  }
};

int main() {
  Tester<char> t;
  vector<string> strs = {
    "minimize",
    "inimize",
    "nimize",
    "imize",
    "mize",
    "ize",
    "ze",
    "e"
  };
  for(auto &vec: strs) {
    vector<char> str(vec.begin(), vec.end());
    cout << "insert " << vec << ":\n";
    t.insert(str);
    t.print();
    cout << endl;
  }
  vector<char> tmp(strs[4].begin(), strs[4].end());
  cout << t.search(tmp) << endl;
  return 0;
}