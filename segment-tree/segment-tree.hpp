#ifndef _SEGMENT_TREE_H
#define _SEGMENT_TREE_H
#include <vector>
template <typename T>
struct Node {
  int l, r;
  Node<T> *lc, *rc;
  mutable T val;
  mutable T mark;
  Node(int left, int right, Node<T> *plc = nullptr, Node<T> *prc = nullptr, T const &total = T()):l(left), r(right), lc(plc), rc(prc), val(total), mark(0){}
};

template <typename T>
class SegmentTree {
public:
  ~SegmentTree() {
    destory(_root);
  }
  SegmentTree(int n) {
    _root = build(0, n);
  }
  // query
  T query(int l, int r) const {
    return query(l, r, _root);
  }
  void change(int l, int r, T const &delta) {
    change(l, r, delta, _root);
  }
protected:
  Node<T> *_root = nullptr;

  //free the tree rooted at `root`
  void destory(Node<T> *root) {
    if(root == nullptr)
      return;
    destory(root -> lc);
    destory(root -> rc);
    delete root;
  }
  
  Node<T>* build(int l, int r) {
    auto node = new Node<T>(l, r);
    if(l + 1 < r) {
      int mid = (l + r) / 2;
      node -> lc = build(l, mid);
      node -> rc = build(mid, r);
    }
    return node;
  }
  T query(int l, int r, Node<T> const *root) const {
    if(l <= root -> l && root -> r <= r) /* The interval of the query contains the interval of the current node */{
      return root -> val;
    } else {
      update(root);
      T ans = 0;
      int mid = (root -> l + root -> r) / 2;
      if(l < mid)
        ans += query(l, r, root -> lc);
      if(r > mid)
        ans += query(l, r, root -> rc);
      return ans;
    }
  }
  
  void change(int l, int r, T const &delta, Node<T> *root) {
    if(l <= root -> l && root -> r <= r) {
      root -> val += delta * (root -> r - root -> l);
      root -> mark += delta;
    } else {
      update(root);
      int mid = (root -> l + root -> r) / 2;
      if(l < mid)
        change(l, r, delta, root -> lc);
      if(r > mid)
        change(l, r, delta, root -> rc);
      root -> val = root -> lc -> val + root -> rc -> val;
    }
  }
  void update(Node<T> const *root) const {
    if(root -> mark == T(0))
      return;
    auto lc = root -> lc, rc = root -> rc;
    lc -> mark += root -> mark;
    lc -> val += root -> mark * (lc -> r - lc -> l);
    rc -> mark += root -> mark;
    rc -> val += root -> mark * (rc -> r - rc -> l);
    root -> mark = T(0);
  }
};

#endif