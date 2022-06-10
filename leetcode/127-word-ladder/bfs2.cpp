#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
  unordered_map<string, int> val2pos;
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    wordList.push_back(beginWord);
    int n = wordList.size();
    // map string to position
    for(int i = 0; i < n; ++i)
      val2pos[wordList[i]] = i;
    // judge whether endWord is in the wordList
    if(!val2pos.count(endWord))
        return 0;
    // bfs
    int src = n - 1, dst = val2pos[endWord];
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    for(int ans = 1; q.size(); ++ans)
      for(int i = 0, t = q.size(); i < t; ++i) {
        auto v = q.front();
        auto &word = wordList[v];
        q.pop();
        if(v == dst)
          return ans;
        // build the edge
        for(auto &c : word) {
          auto origin = c;
          for(char newC = 'a'; newC <= 'z'; ++newC) {
            if(newC == origin)
              continue;
            c = newC;
            if(auto iter = val2pos.find(word); iter == val2pos.end())
              continue;
            else if(auto u = iter -> second; !visited[u]) {
              q.push(u);
              visited[u] = true;
            }
          }
          // restore
          c = origin;
        }
      }
    return 0;
  }
};