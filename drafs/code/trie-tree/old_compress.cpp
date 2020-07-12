//不考虑删除的情况下，节点只会出现分裂，不会出现合并
#include <vector>
template <typename T>
struct Node {
  std::map<T, int> children;
  bool finish;
  int st, ed; //start and end, [st, ed) of buffer
  Node(bool finished = false, int start = 0, int end = 0): c(ch), finish(finished), st(start), ed(end) {}
};
template <typename T>
class CompressTrieTree {
public:
  void insert(std::vector<T> const &word) {
    insert(word, 0, _tree.front());
  }
  CompressTrieTree() {
    _tree.push_back(Node<T>());
  }
protected:
  std::vector<Node<T>> _tree;
  std::vector<T> _buff; //buffer, storing words
  int common_prefix_cnt(std::vector<T> const &word, int st, Node<T> const &node) {
    int i = 0,
        n = std::min(word.size() - st, node.ed - node.st);
    while(word[st + i] == _buff[node.st + i] && i < n)
      ++i;
    return i;
  }
  void split(Node<T> &node, int new_st) {
    
  }
  //insert word [st, word.size()) into node
  void insert(std::vector<T> const &word, int st, Node<T> &node) {
    auto cnt = common_prefix_cnt(word, st, node);
    if(cnt < node.ed - node.st) /* determine if split is needed */{
      node.ed = node.st + cnt; //update the ed
      int new_ed = node.st + cnt;
      node.finish = false;
      
      for(auto &p : node.children)
        split(_tree[p.second], ed);
    }
    
    if(st + cnt == word.size()){
      node.finish = true;
    } else {
      // insert the rest
      int st = _buff.size();
      _buff.insert(_buff.end(), word.begin() + st + cnt, word.end());
      _tree.push_back(Node<T>(true, st, _buff.size()));
      node.children[word[st + cnt]] = _tree.size() - 1;
    }

  }
};

#include <iostream>