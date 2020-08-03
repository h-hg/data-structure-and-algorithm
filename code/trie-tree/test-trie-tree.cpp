//#define _TRIE_TREE_FIXED_SIZE_NODE_H
#define _TRIE_TREE_CHILD_BROTHER_NODE_H
//#define _TRIE_TREE_KV_NODE_H
#include "trie-tree.hpp"

#include <queue>
#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Tester: public TrieTree<T> {
public:
  using TrieTree<T>::TrieTree;
  void print() const {
    queue<Node<T>*> q;
    q.push(TrieTree<T>::_root);
    while(q.size()) {
      for(int i = 0, n = q.size(); i < n; ++i) {
        auto p = q.front();
        q.pop();
        if(p != TrieTree<T>::_root)
          cout << (p->c) << "<" << (p->finish) << ">" << " ";
        
        #ifdef _TRIE_TREE_FIXED_SIZE_NODE_H
        auto ptr = dynamic_cast<FixedSizeNode<T>*>(p);
        //for(auto first = ptr->children, last = ptr->children + FixedSizeNode<T>::MAX_CHILD_CNT; first != last; ++first)
        for(auto &pnode: ptr->children)
          if(pnode != nullptr)
            q.push(pnode);
        #endif

        #ifdef _TRIE_TREE_CHILD_BROTHER_NODE_H
        auto ptr = dynamic_cast<ChildBrotherNode<T>*>(p);
        for(auto child = ptr -> child; child != nullptr; child = child -> bro)
          q.push(child);
        #endif

        #ifdef _TRIE_TREE_KV_NODE_H
        auto ptr = dynamic_cast<KVNode<T>*>(p);
        for(auto &val : ptr -> children)
          q.push(val.second);
        #endif
      }
      cout << endl;
    }
  }

};
int main() {
  Tester<char> t;
  
  //`APPLE`、`ASCEND`、`ASCII`和`BAN`
  t.insert({'A', 'P', 'P', 'L', 'E'});
  t.insert({'A', 'S', 'C', 'E', 'N', 'D'});
  t.insert({'A', 'S', 'C', 'I', 'I'});
  t.insert({'B', 'A', 'N'});
  t.print();
  vector<int*> a(256, nullptr);
  return 0;
}

