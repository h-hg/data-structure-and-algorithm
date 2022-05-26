template <typename K>
struct Node {
  K k;
  Node<K> *lc, *rc;
  Node(K const &key, Node<K> *plc = nullptr, Node<K> *prc = nullptr):k(key), lc(plc), rc(prc) {}
  Node(): k(K()), lc(nullptr), rc(nullptr) {}
};

template <typename T>
class SplayTree {
protected:
  Node<T> *root = nullptr;
  static void free(Node<T> *);
  static void left_join(Node<T>* &root, Node<T>* &l);
  static void right_join(Node<T>* &root, Node<T>* &r);
  static Node<T>* rotate_left(Node<T> *root);
  static Node<T>* rotate_right(Node<T> *root);
  static Node<T>* splay(Node<T> *root, T const &k);
public:
  ~SplayTree();
  bool find(T const &val);
  void insert(T const &val);
  void remove(T const &val);
};

template <typename T>
void SplayTree<T>::free(Node<T> *root) {
  if(root == nullptr)
    return;
  free(root -> lc);
  free(root -> rc);
  delete root;
}

template <typename T>
SplayTree<T>::~SplayTree() {
  free(root);
}

template <typename T>
void SplayTree<T>::left_join(Node<T>* &root, Node<T>* &l) {
  l -> rc = root;
  l = root;
  root = root -> rc;
  //l -> rc = nullptr; // unnecessary
}

template <typename T>
void SplayTree<T>::right_join(Node<T> *&root, Node<T> *&r) {
  r -> lc = root;
  r = root;
  root = root -> lc;
  //r -> lc = nullptr; // Unnecessary
}

template <typename T>
Node<T>* SplayTree<T>::rotate_right(Node<T> *root) {
  auto l = root -> lc;
  root -> rc = l -> rc;
  l -> rc = root;
  return l;
}

template <typename T>
Node<T>* SplayTree<T>::rotate_left(Node<T> *root) {
  auto r = root -> rc;
  root -> rc = r -> lc;
  r -> lc = root;
  return r;
}

template <typename T>
Node<T>* SplayTree<T>::splay(Node<T> *root, T const &target) {
  Node<T> node, *l = &node, *r = &node;
  while(1) {
    if(target < root -> k) {
      if(root -> lc == nullptr)
        break;
      else if(target < root -> lc -> k) {
        root = rotate_right(root);
        if(root -> lc == nullptr)
          break;
      }
      right_join(root, r);
    } else if(target > root -> k) {
      if(root -> rc == nullptr)
        break;
      else if(target > root -> rc -> k) {
        root = rotate_left(root);
        if(root -> rc == nullptr)
          break;
      }
      left_join(root, l);
    } else // k == root -> k
      break;
  }
  //merge
  l -> rc = root -> lc;
  r -> lc = root -> rc;
  root -> lc = node.rc;
  root -> rc = node.lc;
  
  return root;
}

template <typename T>
void SplayTree<T>::insert(T const &val) {
  if(root == nullptr) {
    root = new Node<T>(val);
    return;
  }
  root = splay(root, val);
  if(root -> k < val) {
    Node<T> *node = new Node<T>(val, root, root -> rc);
    root -> rc = nullptr;
    root = node;
  } else if(root -> k > val) {
    Node<T> *node = new Node<T>(val, root -> lc, root);
    root -> lc = nullptr;
    root = node;
  }
}

template <typename T>
void SplayTree<T>::remove(T const &val) {
  if(root == nullptr)
    return;
  root = splay(root, val);
  if(root -> k == val) {
    Node<T> *foo = root, *l = root -> lc;
    if(l) {
      l = splay(l, val); // Let the maximum of l be the root of l.
      l -> rc = root -> rc;
      root = l;
    } else
      root = root -> rc;
    delete foo;
  }
}

template <typename T>
bool SplayTree<T>::find(T const &val) {
  root = splay(root, val);
  return root -> k == val;
}