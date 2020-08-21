//#include "splay-tree-parent.hpp"
#include "splay-tree-top2down.hpp"
#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class Test: public SplayTree<T> {
public:
  void print() {
    queue<Node<T> *> q;
    q.push(SplayTree<T>::root);
    while(q.size()) {
      for(int i = 0, n = q.size(); i < n; ++i) {
        auto node = q.front();
        q.pop();
        cout << (node -> k) << ' ';
        if(node -> lc)
          q.push(node -> lc);
        if(node -> rc)
          q.push(node -> rc);
      }
      cout << endl;
    }
    cout << endl;
  }
};

int main() {
  Test<int> t;
  vector<int> v = {10, 50, 40, 30, 20, 60};
  for(auto &val : v) {
    t.insert(val);
    cout << "insert " << val << ":\n";
    t.print();
  }
  cout << "remove 60:\n";
  t.remove(60);
  t.print();
  //t.find(30);
  //cout << "find 30:\n";
  //t.print();
  return 0;
}