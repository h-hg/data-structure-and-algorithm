
#include <queue>
#include <iostream>
#include <string>
#include "avl-tree.hpp"

using namespace std;

template <typename K, typename V>
class Tester: public AVLT<K, V> {
public:
  void print() {
    queue<Node<K, V>*> q;
    q.push(AVLT<K, V>::_root);
    while(q.size()) {
      for(int i = 0, n = q.size(); i < n; ++i) {
        auto p = q.front();
        q.pop();
        cout << (p->v) << '(' << (p->h) << ") ";
        if(p->lc != nullptr)
          q.push(p->lc);
        if(p->rc != nullptr)
          q.push(p->rc);
      }
      cout << endl;
    }
    cout << endl;
  }
  void insert(K const &k, V const &v) {
    AVLT<K, V>::insert(k, v, AVLT<K, V>::_root);
    check();
  }
  bool remove(K const &k) {
    auto ret = AVLT<K, V>::remove(k, AVLT<K, V>::_root);
    check();
    return ret;
  }
protected:
  void check() const {
    try {
      check(AVLT<K, V>::_root);
    } catch(const string &e) {
      cout << e << endl;
    }
  }
  int check(Node<K, V> *root) const {
    if(root == nullptr)
      return 0;
    if(root -> lc && !(root -> lc -> v < root -> v))
      throw string("Error relation on (" + to_string(root -> v) + ") and it's left child (" + to_string(root -> lc -> v) + ")");
    if(root -> rc && !(root -> v < root -> rc -> v))
      throw string("Error relation on (" + to_string(root -> v) + ") and it's right child (" + to_string(root -> lc -> v) + ")");
    int lch = check(root -> lc),
        rch = check(root -> rc);
    if(abs(lch - rch) > 1 || max(lch, rch) + 1 != root -> h)
      throw string("Error balance factoron ont (" + to_string(root->k) + "), left subtree height is " + to_string(lch) + ", right subtree height is " + to_string(rch));
    return max(lch, rch) + 1;
  }
};


int main() {
  Tester<int,int> t;
  //vector<int> v = {3, 2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9};
  vector<int> v = {50, 30, 70, 15, 40, 60, 88, 22, 65, 75, 90, 78};
  for(int i = 0; i < v.size(); ++i) {
    t.insert(v[i], v[i]);
  }
  t.print();
  t.remove(30);
  t.print();
  //t.remove(5);
  //t.print();
  return 0;
}