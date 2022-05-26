#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

template <typename T>
struct Node {
  T k;
  int npl = 0;
  Node<T> *lc, *rc;
  Node(T const & key, Node<T> *plc = nullptr, Node<T> *prc = nullptr): k(key), lc(plc), rc(prc) {}
};

template <typename T>
class LeftistHeap {
protected:
  Node<T> *root = nullptr;
  static Node<T>* merge(Node<T> *x, Node<T> *y);
  static void free(Node<T> *p);
public:
  void merge(LeftistHeap<T> &tree);
  void insert(T const &val);
  void remove();
  LeftistHeap(){}
  LeftistHeap(vector<T> const &v);
  ~LeftistHeap();
};

template <typename T>
void LeftistHeap<T>::free(Node<T> *p) {
  if(p == nullptr)
    return;
  free(p -> lc);
  free(p -> rc);
  delete p;
}

template <typename T>
LeftistHeap<T>::~LeftistHeap() {
  free(root);
}

template <typename T>
Node<T>* LeftistHeap<T>::merge(Node<T> *x, Node<T> *y) {
  if(x == nullptr)
    return y;
  if(y == nullptr)
    return x;
  if(x -> k > y -> k)
    swap(x, y);
  Node<T>* &xr = x -> rc, * &xl = x -> lc;
  xr = merge(xr, y); // xr must not be nullptr after this operation
  if(xl == nullptr || xr -> npl > xl -> npl)
    swap(xr, xl);
  x -> npl = xr ? xr -> npl + 1 : 0;
  return x;
}

template <typename T>
void LeftistHeap<T>::merge(LeftistHeap<T> &tree) {
  root = merge(root, tree.root);
  tree.root = nullptr;
}

template <typename T>
void LeftistHeap<T>::insert(T const &val) {
  Node<T> *p = new Node<T>(val);
  root = merge(root, p);
}

template <typename T>
void LeftistHeap<T>::remove() {
  auto tmp = root;
  root = merge(root -> lc, root -> rc);
  delete tmp;
}

template <typename T>
LeftistHeap<T>::LeftistHeap(vector<T> const &v) {
  queue<Node<T>*> q;
  for(auto &val : v)
    q.push(new Node<T>(val));
  while(q.size() != 1) {
    auto p1 = q.front();
    q.pop();
    auto p2 = q.front();
    q.pop();
    q.push(merge(p1, p2));
  }
  root = q.front();
  q.pop();
}