#include <vector>
#include <queue>
using namespace std;

template <typename T>
struct Node {
  T w;
  Node<T> *lc, *rc;
  Node(T const &val, Node<T> *plc = nullptr, Node<T> *prc = nullptr):w(val), lc(plc), rc(prc){}
};

template <typename T>
struct Compare {
  bool operator()(const Node<T> * p1, const Node<T> *p2) {
    return p1->w > p2->w;
  }
};

template <typename T>
Node<T>* build(vector<T> &v) {
  //init
  priority_queue<Node<T>*, vector<Node<T>*>, Compare<T>> q;
  for(auto &val: v)
    q.push(new Node<T>(val));
  //build
  while(q.size() > 1) {
    auto x = q.top();
    q.pop();
    auto y = q.top();
    q.pop();
    q.push(new Node<T>(x->w + y->w, x, y));
  }
  return q.top();
}