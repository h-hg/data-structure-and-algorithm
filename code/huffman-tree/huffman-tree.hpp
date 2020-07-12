#include <queue>
#include <vector>
using namespace std;
template <typename T>
struct Node {
  T w;
  Node(T const &val):w(val){}
  virtual ~Node(){}
};

template <typename T>
struct LeafNode: public Node<T> {
  LeafNode(T const &val):Node<T>(val){}
};

template <typename T>
struct InnerNode:public Node<T> {
  Node<T> *lc, *rc;
  InnerNode(T const &val, Node<T> *plc = nullptr, Node<T>  *prc = nullptr):Node<T>(val), lc(plc), rc(prc){}
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
    q.push(new LeafNode<T>(val));
  //build
  while(q.size() > 1) {
    auto x = q.top();
    q.pop();
    auto y = q.top();
    q.pop();
    q.push(new InnerNode<T>(x->w + y->w, x, y));
  }
  return q.top();
}