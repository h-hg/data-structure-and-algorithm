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
  ~BST() {
    destory(_root);
  }
  Node<K, V> const * search() const {
    return search(_root);
  }
  void insert(K const &k, V const &v) {
    insert(k, v, _root);
  };
  bool remove(K const &k) {
    return remove(k, _root);
  };
protected:
  Node<K, V> *_root = nullptr;
  int _size = 0;

  Node<K, V>* malloc(K const &k, V const &v) {
    ++_size;
    return new Node<K, V>(k, v);
  }
  //free a node
  void free(Node<K, V> * node) {
    delete node;
    if(--_size == 0)
      _root = nullptr;
  }
  //free the tree rooted at `root`
  void destory(Node<K, V> *root) {
    if(root == nullptr)
      return;
    destory(root -> lc);
    destory(root -> rc);
    free(root);
  }
  Node<K, V> const * search(K const &k, Node<K, V> *root) const {
    if(root == nullptr)
      return nullptr;
    else if(k < root -> k)
      return search(k, root -> lc);
    else if(k == root -> k)
      return root;
    else
      return search(k, root -> rc);    
  }
  void insert(K const &k, V const &v, Node<K, V>* &root) {
    if(root == nullptr)
      root = this->malloc(k, v);
    else if(k < root -> k)
      insert(k, v, root -> lc);
    else if(k == root -> k)
      root -> v = v;
    else
      insert(k, v, root -> rc);
  }
  //remove the max node from tree, and return the node
  Node<K, V>* removeMax(Node<K, V>* &root) {
    if(root -> rc != nullptr) {
      return removeMax(root -> rc);
    } else {
      auto ret = root;
      root = root -> lc;
      return ret;
    }
  }

  bool remove(K const &k, Node<K, V>* &root) {
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
      this -> free(tmp);
      return true;
    }
  }
};

#endif