//不考虑删除的情况下，节点只会出现分裂，不会出现合并
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
template <typename T>
struct Node {
  map<T, int> children;
  bool finish;
  int st, ed; //start and end, [st, ed) of buffer
  Node(bool finished = false, int start = 0, int end = 0): finish(finished), st(start), ed(end) {}
};

template <typename T>
class CompressTrieTree {
public:
  CompressTrieTree() {
    _tree.push_back(Node<T>());
  }
  void insert(vector<T> const &word) {
    insert(word, 0, 0);
  }
  bool search(vector<T> &word) const;
protected:
  vector<Node<T>> _tree;
  vector<T> _buff; //buffer, storing words

  //return length of word [st, word.size()) and _buff [node.st, node.ed)
  int common_prefix_len(vector<T> const &word, int st, Node<T> const &node);
  
  void split(Node<T> &node, int cpl);
  
  //insert word [st, word.size()) into node
  void insert(vector<T> const &word, int st, int node_idx);
};

template <typename T>
bool CompressTrieTree<T>::search(vector<T> &word) const {
  for(int st = 0, idx = 0; st < word.size();) {
    auto res = _tree[idx].children.find(word[st]);
    if(res == _tree[idx].children.end())
      return false;
    idx = res -> second;  
    auto &node = _tree[idx];
    auto l1 = node.ed - node.st,
         l2 = word.size() - st;
    if(l1 > l2)
      return false;
    //compare _buff[node.st, node.ed) with word[st, st + l1)
    for(int i = 0; i < l1; ++i)
      if(_buff[node.st + i] != word[st++])
        return false;
    if(st == word.size())
      return node.finish;
  }
  return true;
}

template <typename T>
int CompressTrieTree<T>::common_prefix_len(vector<T> const &word, int st, Node<T> const &node) {
  int i = 0;
  for(int n = min(int(word.size() - st), node.ed - node.st); i < n && word[st + i] == _buff[node.st + i]; ++i);
  return i; 
}

template <typename T>
void CompressTrieTree<T>::split(Node<T> &node, int cpl) {
  int old_ed = node.ed;
  node.ed = node.st + cpl;
  Node<T> child(node.finish, node.ed, old_ed);
  node.finish = false;
  //reset the children
  swap(node.children, child.children);
  node.children[_buff[node.ed]] = _tree.size();
  //insert a new node
  _tree.push_back(child);
}

template <typename T>
void CompressTrieTree<T>::insert(vector<T> const &word, int st, int node_idx) {
  
  auto cpl = common_prefix_len(word, st, _tree[node_idx]); //cpl is common prefix length 
  // determine if split is needed, `cpl != node.ed - node.st` is equivalent to `cpl < node.ed - node.st`, for cpl <= node.ed - node.st
  if(cpl != _tree[node_idx].ed - _tree[node_idx].st)
    split(_tree[node_idx], cpl);
  
  st += cpl;
  if(st == word.size()) /* the word has been inserted completely */{
    _tree[node_idx].finish = true;
  } else {
    auto res = _tree[node_idx].children.find(word[st]);
    if(res != _tree[node_idx].children.end()) {
      insert(word, st, res -> second); // insert recursively
    } else {
      //insert a new node
      _tree.push_back(Node<T>(true, _buff.size(), _buff.size() + word.size() - st));
      _tree[node_idx].children[word[st]] = _tree.size() - 1;
      // push the remaining characters into the _buff
      _buff.insert(_buff.end(), word.begin() + st, word.end());
    }
  }
}


//template <typename T>
//void CompressTrieTree<T>::insert(vector<T> const &word, int st, Node<T> &node) {
//  auto cpl = common_prefix_len(word, st, node); //cpl is common prefix length 
//  // determine if split is needed, `cpl != node.ed - node.st` is equivalent to `cpl < node.ed - node.st`, for cpl <= node.ed - node.st
//  if(cpl != node.ed - node.st)
//    split(node, cpl);
//  
//  st += cpl;
//  if(st == word.size()) /* the word has been inserted completely */{
//    node.finish = true;
//  } else {
//    auto res = node.children.find(word[st]);
//    if(res != node.children.end()) {
//      insert(word, st, _tree[res -> second]); // insert recursively
//    } else {
//      //insert a new node
//      _tree.push_back(Node<T>(true, _buff.size(), _buff.size() + word.size() - st));
//      node.children[word[st]] = _tree.size() - 1;
//      // push the remaining characters into the _buff
//      _buff.insert(_buff.end(), word.begin() + st, word.end());
//    }
//  }
//}