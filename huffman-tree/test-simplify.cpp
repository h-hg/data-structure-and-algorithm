#include <iostream>
#include "huffman-tree-simplify.hpp"
template <typename T>
void levelVisit(Node<T> *root) {
  queue<Node<T> *> q;
  q.push(root);
  while(q.size()) {
    for(int i = 0, n = q.size(); i < n; ++i) {
      auto p = q.front();
      q.pop();
      cout << (p->w) << " ";
      if(p->lc != nullptr)
        q.push(p->lc);
      if(p->rc != nullptr)
        q.push(p->rc);
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