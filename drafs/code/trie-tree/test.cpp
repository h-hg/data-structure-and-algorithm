//#define _TRIE_TREE_FIXED_NODE_SIZE_H
#define _TRIE_TREE_CHILD_BROTHER_H
//#define _TRIE_TREE_HASH_TREE_H
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
        
        #ifdef _TRIE_TREE_FIXED_NODE_SIZE_H
        for(auto first = p->children, last = p->children + Node<T>::MAX_CHILD_CNT; first != last; ++first)
          if(*first != nullptr)
            q.push(*first);
        #endif

        #ifdef _TRIE_TREE_CHILD_BROTHER_H        
        for(auto child = p -> child; child != nullptr; child = child -> bro)
          q.push(child);
        #endif

        #ifdef _TRIE_TREE_HASH_TREE_H
        for(auto &val : p -> children)
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
  return 0;
}

