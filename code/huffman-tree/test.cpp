#include <iostream>
#include "huffman-tree.hpp"

template <typename T>
void levelVisit(Node<T> *root) {
  queue<Node<T> *> q;
  q.push(root);
  while(q.size()) {
    for(int i = 0, n = q.size(); i < n; ++i) {
      auto p = q.front();
      q.pop();
      cout << (p->w) << " ";
      auto p_cast = dynamic_cast<InnerNode<T>*>(p);
      if(p_cast != nullptr) {
        q.push(p_cast->lc);
        q.push(p_cast->rc);
      }
    }
    cout << endl;
  }
}
int main() {
  vector<int> v = {7, 19, 2, 6, 32, 3, 21, 10};
  auto root = build<int>(v);
  levelVisit<int>(root);
  return 0;
}