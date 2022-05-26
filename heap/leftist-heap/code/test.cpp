#include <queue>
#include <iostream>
#include "leftist-heap.hpp"

template <typename T>
class test: public LeftistHeap<T>{
public:
  test(vector<T> const&v):LeftistHeap<T>(v){}
  test(){}
  void print() const {
    //bfs
    queue<Node<T> *> q;
    q.push(LeftistHeap<T>::root);
    while(q.size()) {
      for(int i = 0, n = q.size(); i < n; ++i) {
        auto node = q.front();
        q.pop();
        cout << (node -> k) << '(' << (node -> npl) << ") ";
        if(node->lc)
          q.push(node -> lc);
        if(node -> rc)
          q.push(node -> rc);
      }
      cout << endl;
    }
    cout << endl;
  }
};
int main2() {
  test<int> t1, t2;
  int a[] = {10, 40, 24, 30, 36, 20, 12, 16};
  int b[] = {17, 13, 11, 15, 19, 21, 23};
  for(int i = 0, n = sizeof(a) / sizeof(a[0]); i < n; ++i) {
    //cout << "insert: " << a[i] << endl;
    t1.insert(a[i]);
    //t1.print();
  }
  cout << "t1: \n";
  t1.print();
  for(int i = 0, n = sizeof(b) / sizeof(b[0]); i < n; ++i)
    t2.insert(b[i]);
  cout << "\nt2: \n";
  t2.print();
  cout << "\nmerge:\n";
  t1.merge(t2);
  t1.print();
  return 0;
}

int main() {
  vector<int> a = {10, 40, 24, 30, 36, 20, 12, 16};
  test<int> t1, t2(a);
  int b[] = {17, 13, 11, 15, 19, 21, 23};
  for(int i = 0, n = a.size(); i < n; ++i) {
    t1.insert(a[i]);
  }
  cout << "t1:\n";
  t1.print();
  cout << "\nt2\n";
  t2.print();
  return 0;
}