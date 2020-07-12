#include <iostream>
#include <queue>
#include "new-compress-trie-tree.cpp"
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
  t.insert({'a', 'b', 'c'});
  t.print();
  return 0;
}
void f(Node<char> &node, vector<char> const &word) {
  node.children[word[0]] = 12313;
  cout << node.children['a'];
}
int main1() {
  Node<char> node;
  vector<Node<char>> v;
  v.push_back(Node<char>());
  string word = "abc";
  f(v[0], {'a', 'b', 'c'});
  return 0;
}