#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
  unordered_map<string, int> val2pos;
  vector<vector<bool>> buildGraph(vector<string> &wordList) { 
    int n = wordList.size();   
    vector<vector<bool>> graph(n, vector<bool>(n, 0));
    for(int i = 0; i < n; ++i) {
      auto &word = wordList[i];
      for(auto &c : word) {
        auto origin = c;
        // change the letter of word
        for(char newChar = 'a'; newChar <= 'z'; ++newChar) {
          if(newChar == origin)
            continue;
          c = newChar;
          if(auto iter = val2pos.find(word); iter != val2pos.end())
            graph[i][iter -> second] = graph[iter -> second][i] = true;
        }
        // restore the letter
        c = origin;
      }
    }
    return graph;
  }
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    wordList.push_back(beginWord);
    int n = wordList.size();
    // map string to position
    for(int i = 0; i < n; ++i)
      val2pos[wordList[i]] = i;
    // judge whether endWord is in the wordList
    if(!val2pos.count(endWord))
        return 0;
    // build the graph
    auto graph = buildGraph(wordList);
    // bfs
    int src = n - 1, dst = val2pos[endWord];
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    for(int ans = 1; q.size(); ++ans)
      for(int i = 0, t = q.size(); i < t; ++i) {
        auto v = q.front();
        q.pop();
        if(v == dst)
          return ans;
        for(int u = 0; u < n; ++u)
          if(graph[v][u] && !visited[u]) {
            q.push(u);
            visited[u] = true;
          }  
      }
    return 0;
  }
};