#include <vector>
#include <string>
#include <array>
using namespace std;
struct Node {
  //array<Node*, 26> children;
   vector<Node*> children;
  bool isEnd = false;
  Node() : children(26, nullptr){}
};

class Solution {
  Node * root;
  void insert(string const &str) {
    auto node = root;
    for(auto c : str) {
      int idx = c - 'a';
      if(! node -> children[idx])
        node -> children[idx] = new Node();
      node = node -> children[idx];
    }
    node -> isEnd = true;
  }
  string getShortestRoot(string const &word) {
    auto node = root;
    for(int i = 0; i < word.size(); ++i) {
      int idx = word[i] - 'a';
      if(!node -> children[idx])
        return word;
      node = node -> children[idx];
      if(node -> isEnd)
        return word.substr(0, i + 1);
    }
    return word;
  }
public:
  string replaceWords(vector<string>& dictionary, string sentence) {
    root = new Node();
    // insert the root
    for(auto &root : dictionary)
      insert(root);
    // split sentence and find the shortest root
    string ans, word;
    for(auto c : sentence)
      if(c == ' ') {
        if(word.size()) {
          ans += getShortestRoot(word);
          word.clear();
        }
        ans.push_back(' ');
      } else {
        word.push_back(c);
      }
    if(word.size())
      ans += getShortestRoot(word);
    return ans;
  }
};