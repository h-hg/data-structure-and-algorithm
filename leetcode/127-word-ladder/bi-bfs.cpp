#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;
class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    wordList.push_back(beginWord);
    int n = wordList.size();
    // map string to position
    unordered_map<string, int> val2pos;
    for(int i = 0; i < n; ++i)
      val2pos[wordList[i]] = i;
    // judge whether endWord is in the wordList
    if(!val2pos.count(endWord))
      return 0;
    // bi-bfs
    int src = n - 1, dst = val2pos[endWord];
    vector<bool> visited(n, false);
    unordered_set<int> beginSet{src}, endSet{dst};
    visited[src] = visited[dst] = true;
    for(int step = 1; beginSet.size() && endSet.size(); ++step) {
      // gready: choose the set with less nodes
      if(beginSet.size() > endSet.size())
        swap(beginSet, endSet);
      unordered_set<int> nextSet;
      for(auto v : beginSet) {
        auto &word = wordList[v];
        // search word
        for(auto &c : word) {
          auto origin = c;
          for(char newC = 'a'; newC <= 'z'; ++newC) {
            if(origin == newC)
              continue;
            c = newC;
            if(auto iter = val2pos.find(word); iter == val2pos.end())
              continue;
            else if(auto u = iter -> second; endSet.count(u))
              return step + 1;
            else if(!visited[u]) {
              nextSet.insert(u);
              visited[u] = true;
            }
          }
          // restore
          c = origin;
        }
      }
      swap(beginSet, nextSet);
    }
    return 0;
  }
};