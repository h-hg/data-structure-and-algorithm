#ifndef _AVL_TREE_H
#define _AVL_TREE_H
#include <algorithm>

template <typename K, typename V>
struct Node {
  K k; //key
  V v; //value
  int h; //height
  Node<K, V> *lc, *rc;
  Node(K const &key, V const &val, Node<K, V> *plc = nullptr, Node<K, V> * prc = nullptr): k(key), v(val), h(1), lc(plc), rc(prc) {}
  //update height
  void updateH() {
    h = std::max( lc ? lc -> h : 0, rc ? rc -> h : 0) + 1;
  }
  //get balance factor
  int getBF() const {
    return (lc ? lc -> h : 0) - (rc ? rc -> h : 0);
  }
};

template <typename K, typename V>
class AVLT {
public:
  Node<K, V> const * search(K const &k) const {
    return search(k, _root);
  };
  void insert(K const &k, V const &v) {
    return insert(k, v, _root);
  }
  bool remove(K const &k) {
    return remove(k, _root);
  }
  ~AVLT() {
    destory(_root);
  }
protected:
  Node<K, V> *_root = nullptr;
  int _size = 0;
  //create a node
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
  //search
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
  static int getHeight(Node<K, V> const *node) {
    return node == nullptr ? 0 : node -> h;
  }
  void ll(Node<K, V>* &root) {
    auto p = root,
         l = p -> lc, //left subtree
         lr = l -> rc;   //right subtree of l
    //rotation
    p -> lc = lr;
    l -> rc = root;
    root = l; //update the root
    //update height
    p -> updateH();
    l -> updateH();
  }
  void rr(Node<K, V>* &root) {
    auto p = root,
         r = p -> rc,
         rl = r -> lc;
    //rotation
    p -> rc = rl;
    r -> lc = p;
    root = r; //update the root
    //update height
    p -> updateH();
    r -> updateH();
  }
  void lr(Node<K, V>* &root) {
    rr(root->lc);
    ll(root);
  }
  void rl(Node<K, V>* &root) {
    ll(root->rc);
    rr(root);
  }
  void insert(K const &k, V const &v, Node<K, V>* &root) {
    if(root == nullptr) {
      root = new Node<K, V>(k,v);
    } else if(k < root -> k) {
      insert(k, v, root -> lc);
      if(root -> getBF() == 2) {
        if(k < root -> lc -> v)
          ll(root);
        else
          lr(root);
      } else {
        root -> updateH();
      }
    } else if(k == root -> k) {
      root -> v = v;
    } else {
      insert(k, v, root -> rc);
      if(root -> getBF() == -2) {
        if(k > root -> rc -> v)
          rr(root);
        else
          rl(root);
      } else {
        root -> updateH();
      }
    }
  }
  Node<K, V>* const removeMax(Node<K, V>* &root) {
    if(root -> rc != nullptr) {
      auto ret = removeMax(root -> rc);
      root -> updateH();
      return ret;
    } else {
      auto ret = root;
      root = root -> lc;
      return ret;
    }
  }
  Node<K, V>* const removeMin(Node<K, V>* &root) {
    if(root -> lc != nullptr) {
      auto ret = removeMin(root -> lc);
      root -> updateH();
      return ret;
    } else {
      auto ret = root;
      root = root -> rc;
      return ret;
    }
  }
  bool remove(K const &k, Node<K, V>* &root) {
    if(root == nullptr) {
      return false;
    } else if(k < root -> k) {
      auto ret =  remove(k, root -> lc);
      if(ret == false)
        return ret;
      if(root -> getBF() == -2) {
        auto r = root -> rc;
        (getHeight(r -> lc) > getHeight(r -> rc)) ? rl(root) : rr(root);
      }
    } else if(root -> k < k) {
      auto ret = remove(k, root -> rc);
      if(ret == false)
        return ret;
      if(root -> getBF() == 2) {
        auto l = root -> lc;
        (getHeight(l -> lc) > getHeight(l -> rc)) ? ll(root) : lr(root);
      }
    } else {
      auto tmp = root,
           l = root -> lc,
           r = root -> rc;
      if(l && r) /*both left and right tree are not empty */{
        auto node = (l -> h > r -> h) ? removeMax(l) : removeMin(r);
        node -> lc = root -> lc;
        node -> rc = root -> rc;
        root = node;
      } else /* more than one subtree are empty */{
        root = l ? l : r;
      }
      this -> free(tmp);
    }
    if(root != nullptr)
      root -> updateH();
    return true;
  }
};

#endif