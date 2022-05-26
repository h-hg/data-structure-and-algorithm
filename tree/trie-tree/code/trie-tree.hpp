#ifndef _TRIE_TREE_H
#define _TRIE_TREE_H
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
template <typename T>
class Node {
public:
  T c;
  bool finish = false;
  Node(T const &ch, bool finished = false): c(ch), finish(finished) {}
  virtual Node<T>* getChild(T const &ch) const = 0;
  virtual Node<T>* insertChild(T const &ch) =0;
  virtual void destroy() =0;
  virtual ~Node(){};
};

//fixed node size
template <typename T>
class FixedSizeNode: public Node<T> {
protected:
  static const int MAX_CHILD_CNT = 256;
  vector< FixedSizeNode<T>* > children;
public:
  FixedSizeNode(T const &ch, bool finished = false):Node<T>(ch, finished), children(MAX_CHILD_CNT, nullptr) {}
  FixedSizeNode<T>* getChild(T const &ch) const {
    return children[ch];
  }
  FixedSizeNode<T>* insertChild(T const &ch) {
    return children[ch] ? children[ch] : (children[ch] = new FixedSizeNode<T>(ch));
  }
  void destroy() {
    for(auto &pnode: children)
      destroy(pnode);
  }
  void destroy(FixedSizeNode<T> *root) {
    if(root == nullptr)
      return;
    for(auto &pnode : root -> children)
      destroy(pnode);
    delete root;
  }
};

//child-brother
template <typename T>
class ChildBrotherNode: public Node<T> {
protected:
  ChildBrotherNode<T> *child = nullptr, *bro = nullptr; //child, brother
public:
  ChildBrotherNode(T const &ch, bool finished = false): Node<T>(ch, finished) {}
  ChildBrotherNode<T>* getChild(T const &ch) const {
    auto p = child;
    while(p && ch != p -> c)
      p = p -> bro;
    return p;
  }
  ChildBrotherNode<T>* insertChild(T const &ch) {
    for(ChildBrotherNode<T> **p = &child; true; p = &((*p) -> bro) ) {
      if(*p == nullptr)
        return *p = new ChildBrotherNode<T>(ch);
      else if((*p) -> c == ch)
        return *p;
    }
    return nullptr;//redubant, for robustness
  }
  void destroy() {
    destroy(child);
    destroy(bro);
  }
  void destroy(ChildBrotherNode<T> *root) {
    if(root == nullptr)
      return;
    destroy(root -> child);
    destroy(root -> bro);
    delete root;
  }
};

//hash tree
template <typename T>
class KVNode: public Node<T> {
protected:
  map<T, KVNode<T>*> children;
public:
  KVNode(T const &ch, bool finished = false):Node<T>(ch, finished) {}
  KVNode<T>* getChild(T const &ch) const {
    auto res = children.find(ch);
    return res == children.end() ? nullptr : res -> second;
  }
  KVNode<T>* insertChild(T const &ch) {
    auto res = children.insert(pair<T, KVNode<T>*>{ch, nullptr});
    return res.second ? res.first -> second = new KVNode<T>(ch) : res.first -> second;
  }
  void destroy() {
    for(auto &val: children)
      destroy(val.second);
  }
  void destroy(KVNode<T> *root) {
    if(root == nullptr)
      return;
    for(auto &val : root -> children)
      destroy(val.second);
    delete root;
  }
};


//#define _TRIE_TREE_FIXED_SIZE_NODE_H
//#define _TRIE_TREE_CHILD_BROTHER_NODE_H
//#define _TRIE_TREE_KV_NODE_H

template <typename T>
class TrieTree {
public:
  TrieTree() {
#ifdef _TRIE_TREE_FIXED_SIZE_NODE_H
    _root = new FixedSizeNode<T>(T());
#endif
#ifdef _TRIE_TREE_CHILD_BROTHER_NODE_H
    _root = new ChildBrotherNode<T>(T());
#endif
#ifdef _TRIE_TREE_KV_NODE_H
    _root = new KVNode<T>(T());
#endif
  }
  ~TrieTree() {
    _root -> destroy();
    delete _root;
  }
  bool search(const vector<T> &word) const;
  void insert(const vector<T> &word);
protected:
  Node<T> *_root;
};

template <typename T>
bool TrieTree<T>::search(const vector<T> &word) const {
  Node<T> *p = _root;
  for(auto &c: word) {
    p = p -> getChild(c);
    if(p == nullptr)
      return false;
  }
  return p -> finish;
}

template <typename T>
void TrieTree<T>::insert(const vector<T> &word) {
  Node<T> *p = _root;
  for(auto &c: word) {
    p = p -> insertChild(c);
  }
  p -> finish = true;
}

#endif