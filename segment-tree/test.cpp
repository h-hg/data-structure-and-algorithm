#include "segment-tree.hpp"
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Tester: public SegmentTree<T> {
public:
  Tester(int n):SegmentTree<T>(n){}
   void print() const {
    queue<Node<T>*> q;
    q.push(SegmentTree<T>::_root);
    while(q.size()) {
      for(int i = 0, n = q.size(); i < n; ++i) {
        auto p = q.front();
        q.pop();
        cout << "[" << (p->l) << ", " << (p->r) << ")<" << (p->val) << ">(" << (p->mark) << ") ";
        if(p->lc)
          q.push(p->lc);
        if(p->rc)
          q.push(p->rc);
      }
      cout << endl;
    }
    cout << endl;
  }
protected:
  void check() const{

  }
};

int main() {
  const int n = 9;
  Tester<int> t(n);
  t.print();
  cout << endl;
  for(int i = 0; i < n; ++i)
    t.change(i, i + 1, i);
  for(int i = 0;i < n; ++i)
    t.query(i, i + 1);
  t.print();
  cout << endl;
  t.change(0, 5, 1);
  t.print();
  cout << endl << t.query(1,4) << endl;
  t.print();
  return 0;
}