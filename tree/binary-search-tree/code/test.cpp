#include <queue>
#include <iostream>
#include <string>
#include "bst.hpp"
using namespace std;

template <typename K, typename V>
class Tester: public BST<K, V> {
public:
  void print() const {
    queue<Node<K, V>*> q;
    q.push(BST<K, V>::_root);
    while(q.size()) {
      for(int i = 0, n = q.size(); i < n; ++i) {
        auto p = q.front();
        q.pop();
        cout << (p->v) << ' ';
        if(p->lc)
          q.push(p->lc);
        if(p->rc)
          q.push(p->rc);
      }
      cout << endl;
    }
    cout << endl;
  }
  void insert(K const &k, V const &v) {
    BST<K, V>::insert(k, v, BST<K, V>::_root);
    check();
  };
  bool remove(K const &k) {
    auto ret = BST<K, V>::remove(k, BST<K, V>::_root);
    check();
    return ret;
  };
protected:
  void check() const {
    try {
      check(BST<K, V>::_root);
    } catch(const string &e) {
       cout << e << endl;
    }
  }
  void check(Node<K, V> * root) const {
    if(root == nullptr)
      return;
    if(root -> lc && !(root -> lc -> v < root -> v))
      throw string("Error relation on (" + to_string(root -> v) + ") and it's left child (" + to_string(root -> lc -> v) + ")");
    if(root -> rc && !(root -> v < root -> rc -> v))
      throw string("Error relation on (" + to_string(root -> v) + ") and it's right child (" + to_string(root -> lc -> v) + ")");
    check(root -> lc);
    check(root -> rc);
  }
};

using namespace std;
int main() {
  Tester<int, int> t;
  t.insert(10,10);
  t.insert(1,1);
  t.insert(100, 100);
  t.insert(50,50);
  t.insert(25,25);
  t.insert(61,61);
  t.print();
  t.remove(100);
  t.print();
  return 0;
}