template <typename K>
struct Node {
  K k;
  Node<K> *parent, *lc, *rc;
  Node(K const &key, Node<K> *father = nullptr, Node<K> *plc = nullptr, Node<K> *prc = nullptr):k(key), parent(father), lc(plc), rc(prc) {}
};

template <typename T>
class SplayTree {
protected:
  Node<T> *root = nullptr;
  static void zig(Node<T> *);
  static void zag(Node<T> *);
  static void zig_zig(Node<T> *);
  static void zag_zag(Node<T> *);
  static void zig_zag(Node<T> *);
  static void zag_zig(Node<T> *);
  static Node<T>* splay(Node<T> *);
  static Node<T>* merge(Node<T> *x, Node<T> *y);
  static Node<T>* bst_search(T const &val, Node<T> *root);
  static Node<T>* bst_insert(T const &val, Node<T>* &root);
  static Node<T>* bst_rm_min(Node<T> *root);
  static Node<T> *bst_rm_max(Node<T> *root);
  static Node<T> *bst_max(Node<T> *root);
  static Node<T> *bst_min(Node<T> *root);
  static void free(Node<T> *);
public:
  bool find(T const &val);
  void insert(T const &val);
  void remove(T const &val);
  ~SplayTree();
};

template <typename T>
void SplayTree<T>::free(Node<T> *p) {
  if(p == nullptr)
    return;
  free(p -> lc);
  free(p -> rc);
  delete p;
}

template <typename T>
SplayTree<T>::~SplayTree() {
  free(root);
}

template <typename T>
void SplayTree<T>::zag(Node<T> *x) {
  Node<T> *l = x -> lc, *p = x -> parent, *pp = p -> parent;
  p -> rc = l;
  if(l)
    l -> parent = p;
  x -> parent = pp;
  if(pp)
    (p == pp -> lc ? pp -> lc : pp -> rc) = x;
  p -> parent = x;
  x -> lc = p;
}

template <typename T>
void SplayTree<T>::zig(Node<T> *x) {
  Node<T> *r = x -> rc, *p = x -> parent, *pp = p -> parent;
  p -> lc = r;
  if(r)
    r -> parent = p;
  x -> parent = pp;
  if(pp)
    (p == pp -> lc ? pp -> lc : pp -> rc) = x;
  p -> parent = x;
  x -> rc = p;
}

template <typename T>
void SplayTree<T>::zig_zig(Node<T> *x) {
  zig(x -> parent);
  zig(x);
}

template <typename T>
void SplayTree<T>::zag_zag(Node<T> *x) {
  zag(x -> parent);
  zag(x);
}

template <typename T>
void SplayTree<T>::zig_zag(Node<T> *x) {
  zig(x);
  zag(x);
}

template <typename T>
void SplayTree<T>::zag_zig(Node<T> *x) {
  zag(x);
  zig(x);
}

// Rotate node x to root node
template <typename T>
Node<T>* SplayTree<T>::splay(Node<T> *x) {
  Node<T> *p = x -> parent, *pp = nullptr;
  while(p) {
    pp = p -> parent;
    if(pp == nullptr) {
      p -> lc == x ? zig(x) : zag(x);
    } else if(x == p -> lc) {
      p == pp -> lc ? zig_zig(x) : zig_zag(x);
    } else {
      p == pp -> rc ? zag_zag(x) : zag_zig(x);
    }
    p = x -> parent;
  }
  return x;
}

template <typename T>
Node<T>* SplayTree<T>::bst_search(T const &val, Node<T> *x) {
  while(x) {
    if(x -> k == val)
      return x;
    else if(val < x -> k)
      x = x -> lc;
    else
      x = x -> rc;
  }
  return x;
}

template <typename T>
bool SplayTree<T>::find(T const& val) {
  auto x = bst_search(val, root);
  if(x == nullptr)
    return false;
  root = splay(x);
  return true;
}

template <typename T>
Node<T>* SplayTree<T>::bst_insert(T const &val, Node<T>* &root) {
  if(root == nullptr)
    return root = new Node<T>(val);
  Node<T> *parent = nullptr, **x_ptr = &root;
  while(*x_ptr) {
    parent = *x_ptr;
    if(val == (*x_ptr) -> k)
      return *x_ptr;
    else if(val < (*x_ptr) -> k)
      x_ptr = &((*x_ptr) -> lc);
    else
      x_ptr = &((*x_ptr) -> rc);
  }
  return *x_ptr = new Node<T>(val, parent);
}

template <typename T>
Node<T>* SplayTree<T>::bst_min(Node<T> *root) {
  while(root -> lc)
    root = root -> lc;
  return root;
}

template <typename T>
Node<T>* SplayTree<T>::bst_max(Node<T> *root) {
  while(root -> rc)
    root = root -> rc;
  return root;
}

template <typename T>
void SplayTree<T>::insert(T const &val) {
  auto x = bst_insert(val, root);
  root = splay(x);
}

template <typename T>
void SplayTree<T>::remove(T const &val) {
  if(!find(val))
    return;
  Node<T> *foo = root, *l = root -> lc, *r = root -> rc;
  if(l)
    l -> parent = nullptr;
  if(r)
    r -> parent = nullptr;
  root = merge(l, r);
  delete foo;
}

//all node in x is smaller than y
template <typename T>
Node<T>* SplayTree<T>::merge(Node<T> *x, Node<T> *y) {
  if(!x)
    return y;
  if(!y)
    return x;
  Node<T> *root = bst_max(x);
  splay(root);
  root -> rc = y;
  y -> parent = root;
  return root;
}