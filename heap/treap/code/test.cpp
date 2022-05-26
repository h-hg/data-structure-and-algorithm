#include "treap.hpp"
#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class Test: public Treap<T> {
public:
  void print() {
    queue<Node<T> *> q;
    q.push(Treap<T>::root);
    while(q.size()) {
      for(int i = 0, n = q.size(); i < n; ++i) {
        auto node = q.front();
        q.pop();
        cout << (node -> k) << '(' << (node -> priority) << ')' << ' ';
        if(node -> lc)
          q.push(node -> lc);
        if(node -> rc)
          q.push(node -> rc);
      }
      cout << endl;
    }
  }
};
int main() {
  vector<int> v = {11, 7, 14, 3, 9, 18, 16, 15};
  Test<int> t;
  for(auto &val : v) {
    //cout << "insert: " << val << endl;
    t.insert(val);
    //t.print();
  }
  t.remove(9);
  t.print();
  return 0;
}