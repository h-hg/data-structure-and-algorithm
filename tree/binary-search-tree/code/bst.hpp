#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

template <typename K, typename V>
struct Node {
  K k; //key
  V v; //value
  Node<K, V> *lc, *rc; //left children, right children
  Node(K const &k, V const & v, Node<K, V> *plc = nullptr, Node<K, V> *prc = nullptr): k(k), v(v), lc(prc), rc(prc){}
};

template <typename K, typename V>
class BST {
public:
  ~BST();
  Node<K, V>* search(K const &key) const;
  void insert(K const &k, V const &v);
  bool remove(K const &k);
protected:
  Node<K, V> *_root = nullptr;

  static void free(Node<K, V> * node);
  static Node<K, V>* search(K const &k, Node<K, V> *root);
  static void insert(K const &k, V const &v, Node<K, V>* &root);
  //remove the max node from tree, and return the node
  static Node<K, V>* removeMax(Node<K, V>* &root);
  static bool remove(K const &k, Node<K, V>* &root);
};


template <typename K, typename V>
void BST<K, V>::free(Node<K, V> * node) {
  if(!node)
    return;
  free(node -> lc);
  free(node -> rc);
  delete node;
}

template <typename K, typename V>
BST<K, V>::~BST() {
  free(_root);
}

template <typename K, typename V>
Node<K, V>* BST<K, V>::search(K const &k, Node<K, V> *root) {
  if(root == nullptr)
    return nullptr;
  else if(k < root -> k)
    return search(k, root -> lc);
  else if(k == root -> k)
    return root;
  else
    return search(k, root -> rc);    
}

template <typename K, typename V>
Node<K, V>* BST<K, V>::search(K const &key) const {
  return search(key, _root);
}


template <typename K, typename V>
void BST<K, V>::insert(K const &k, V const &v, Node<K, V>* &root) {
  if(root == nullptr)
    root = new Node<K, V>(k, v);
  else if(k < root -> k)
    insert(k, v, root -> lc);
  else if(k == root -> k)
    root -> v = v;
  else
    insert(k, v, root -> rc);
}

template <typename K, typename V>
void BST<K, V>::insert(K const &k, V const &v) {
  insert(k, v, _root);
};

template <typename K, typename V>
Node<K, V>* BST<K, V>::removeMax(Node<K, V>* &root) {
  if(root -> rc != nullptr) {
    return removeMax(root -> rc);
  } else {
    auto ret = root;
    root = root -> lc;
    return ret;
  }
}

template <typename K, typename V>
bool BST<K, V>::remove(K const &k, Node<K, V>* &root) {
  if(root == nullptr) {
    return false;
  } else if(k < root -> k) {
    return remove(k, root -> lc);
  } else if(root -> k < k) {
    return remove(k, root -> rc);
  } else {
    auto tmp = root;
    if(root -> lc == nullptr) /* There is no left subtree of root */ {
      root = root -> rc;
    } else /* replace the node wiht max node of left subtree */ {
      auto maxNode = removeMax(root -> lc);
      maxNode -> lc = root -> lc;
      maxNode -> rc = root -> rc;
      root = maxNode;
    }
    delete tmp;
    return true;
  }
}

template <typename K, typename V>
bool BST<K,V>::remove(K const &k) {
  return remove(k, _root);
};

#endif