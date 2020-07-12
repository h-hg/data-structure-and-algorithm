#ifndef _TRIE_TREE_H
#define _TRIE_TREE_H
#include <vector>
#ifdef _TRIE_TREE_FIXED_NODE_SIZE_H
//fixed node size
#include <algorithm>
template <typename T>
struct Node {
  static const int MAX_CHILD_CNT = 256;
  T c;
  Node<T>* children[MAX_CHILD_CNT];
  bool finish;
  Node(T const &ch, bool finished = false):c(ch), finish(finished) {
    std::fill_n(children, MAX_CHILD_CNT, nullptr);
  }
  inline Node<T>* getChild(T const &ch) const {
    return children[ch];
  }
  inline Node<T>* insertChild(T const &ch) {
    return children[ch] ? children[ch] : (children[ch] = new Node<T>(ch));
  }
  void destroy() {
    for(auto first = children, last = children + MAX_CHILD_CNT; first != last; ++first)
      destroy(*first);
  }
  void destroy(Node<T> *root) {
    if(root == nullptr)
      return;
    for(auto first = root -> children, last = root -> children + MAX_CHILD_CNT; first != last; ++first)
      destroy(*first);
    delete root;
  }

};
#endif

#ifdef _TRIE_TREE_CHILD_BROTHER_H
//child-brother
template <typename T>
struct Node {
  T c;
  Node<T> *child, *bro; //child, brother
  bool finish;
  Node(T const &ch, bool finished = false, Node<T> *son = nullptr, Node<T> *brother = nullptr): c(ch), child(son), bro(brother), finish(finished) {}
  
  Node<T>* getChild(T const &ch) const {
    auto p = child;
    while(p && ch != p -> c)
      p = p -> bro;
    return p;
  }
  Node<T>* insertChild(T const &ch) {
    for(Node<T> **p = &child; true; p = &((*p) -> bro) ) {
      if(*p == nullptr)
        return *p = new Node<T>(ch);
      else if((*p) -> c == ch)
        return *p;
    }
    return nullptr;//redubant, for robustness
  }
  void destroy() {
    destroy(child);
    destroy(bro);
  }
  void destroy(Node<T> *root) {
    if(root == nullptr)
      return;
    destroy(root -> child);
    destroy(root -> bro);
    delete root;
  }
};
#endif

#ifdef _TRIE_TREE_HASH_TREE_H
//hash tree
#include <map>
template <typename T>
struct Node {
  T c;
  std::map<T, Node<T>*> children;
  bool finish;
  Node(T const &ch, bool finished = false):c(ch), finish(finished){}
  Node<T>* getChild(T const &ch) const {
    auto res = children.find(ch);
    return res == children.end() ? nullptr : res -> second;
  }
  Node<T>* insertChild(T const &ch) {
    auto res = children.insert(std::pair<T, Node<T>*>{ch, nullptr});
    return res.second ? res.first -> second = new Node<T>(ch) : res.first -> second;
  }
  void destroy() {
    for(auto &val: children)
      destroy(val.second);
  }
  void destroy(Node<T> *root) {
    if(root == nullptr)
      return;
    for(auto &val : root -> children)
      destroy(val.second);
    delete root;
  }
};
#endif

template <typename T>
class TrieTree {
public:
  TrieTree() {
    _root = new Node<T>(T());
  }
  bool search(const std::vector<T> &word) const {
    Node<T> *p = _root;
    for(auto &c: word) {
      p = p -> getChild(c);
      if(p == nullptr)
        return false;
    }
    return p -> finish;
  }
  void insert(const std::vector<T> &word) {
    Node<T> *p = _root;
    for(auto &c: word) {
      p = p -> insertChild(c);
    }
    p -> finish = true;
  }
  ~TrieTree() {
    _root -> destroy();
    delete _root;
  }
protected:
  Node<T> *_root;
};

#endif