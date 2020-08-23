#include <random>
#include <queue>
using namespace std;

template <typename K>
struct Node {
  K k;
  Node<K> *lc, *rc;
  int priority;
  Node(K const &key, Node<K> *plc = nullptr, Node<K> *prc = nullptr): k(key), lc(plc), rc(prc), priority(rand()) {}
  static int rand() {
    static default_random_engine e(0L);
    static uniform_int_distribution<int> random;
    return random(e) % 100;
  }
};

template <typename T>
class Treap {
protected:
  Node<T> *root = nullptr;
  static void free(Node<T> *);
  static Node<T>* bst_search(T const &key, Node<T> *root);
  static void rotate_right(Node<T>* &root);
  static void rotate_left(Node<T>* &root);
  static bool insert_helper(Node<T>* &root, Node<T> *node);
  static bool remove_helper(Node<T>* &root, T const &key);
public:
  bool insert(T const &key);
  bool find(T const &key);
  bool remove(T const &key);
  ~Treap();
};

template <typename T>
void Treap<T>::free(Node<T> *root) {
  if(!root)
    return;
  free(root -> lc);
  free(root -> rc);
  delete root;
}

template <typename T>
Treap<T>::~Treap() {
  free(root);
}

template <typename T>
void Treap<T>::rotate_right(Node<T>* &root) {
  auto l = root -> lc;
  root -> lc = l -> rc;
  l -> rc = root;
  root = l;
}

template <typename T>
void Treap<T>::rotate_left(Node<T>* &root) {
  auto r = root -> rc;
  root -> rc = r -> lc;
  r -> lc = root;
  root = r;
}

template <typename T>
Node<T>* Treap<T>::bst_search(T const &key, Node<T> *root) {
  while(root) {
    if(key < root -> k)
      root = root -> lc;
    else if(root -> k == key)
      return root;
    else
      root = root -> rc;
  }
  return root;
}

template <typename T>
bool Treap<T>::find(T const &key) {
  return bst_search(key, root);
}

template <typename T>
bool Treap<T>::insert_helper(Node<T>* &root, Node<T> *node) {
  if(root == nullptr) {
    root = node;
    return true;
  } else if(node -> k < root -> k) {
    if(!insert_helper(root -> lc, node))
      return false;
    if(root -> priority > node -> priority)
      rotate_right(root);
    return true;
  } else if(node -> k == root -> k) {
    delete node;
    return false;
  } else {
    if(!insert_helper(root -> rc, node))
      return false;
    if(root -> priority > node -> priority)
      rotate_left(root);
    return true;
  }
}

template <typename T>
bool Treap<T>::insert(T const &key) {
  Node<T> *node = new Node<T>(key);
  return insert_helper(root, node);
}

template <typename T>
bool Treap<T>::remove_helper(Node<T> *&root, T const &key) {
  if(!root)
    return false;
  else if(key < root -> k)
    return remove_helper(root -> lc, key);
  else if(key == root -> k) {
    Node<T> **pnode = &root, *lc = root -> lc, *rc = root -> rc;
    while(lc && rc) {
      if(lc -> priority < rc -> priority) {
        rotate_right(*pnode);
        pnode = &((*pnode) -> rc);
      } else {
        rotate_left(*pnode);
        pnode = &((*pnode) -> lc);
      }
      lc = (*pnode) -> lc;
      rc = (*pnode) -> rc;
    }
    Node<T> *foo = *pnode;
    *pnode = lc ? (*pnode) -> lc : (*pnode) -> rc;
    delete foo;
    return true;
  } else
    return remove_helper(root -> rc, key);
}

template <typename T>
bool Treap<T>::remove(T const &key) {
  return remove_helper(root, key);
}