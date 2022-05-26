#include <vector>
#include <algorithm>
// fixed node size
const int ROOT_IDX = 0;
template <typename T>
struct Node {
  static const int MAX_CHILD_CNT = 1 << (sizeof(T) * 8);
  T c;
  int children[MAX_CHILD_CNT];
  int cnt = 1; // count of prefixion
  Node(T const &ch):c(c) {
    std::fill_n(children, MAX_CHILD_CNT, ROOT_IDX);
  }
};

template <typename T>
class StaticTrieTree {
public:
  StaticTrieTree() {
    _tree.push_back(Node<T>(T())); //insert the root node
  }
  void insert(std::vector<T> const &word) {
    int idx = 0;
    for(int i = 1; i <= word.size(); ++i) {
      auto c = word[i-1];
      //insert the character c
      if(_tree[idx].children[c] == ROOT_IDX) {
        _tree.push_back(Node<T>(c));
        idx = _tree[idx].children[c] = _tree.size() - 1;
      } else {
        idx = _tree[idx].children[c];
        ++ _tree[idx].cnt;
      }
      //update the answer
      ans = std::max(ans, _tree[idx].cnt * i);
    }
  }
  int getAns() {
    return ans;
  }
protected:
  int ans = 0;
  std::vector<Node<T>> _tree;
};

#include <string>
#include <iostream>
int test() {
  using namespace std;
  vector<string> foo = {"Jora de Sus", "Orhei", "Jora de Mijloc", "Joreni", "Jora de Jos", "Japca", "Orheiul Vechi"};
  vector<vector<char>> data;
  for(auto &val : foo)
    data.push_back(vector<char>(val.begin(), val.end()));
  StaticTrieTree<char> t;
  for(auto &val :data)
    t.insert(val);
  cout << t.getAns();
  return 0;
}
int main() {
  test();
  return 0;
}