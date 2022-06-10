#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<bool>> graph;
  vector<bool> visited;
  void dfs(int n) {
    if(visited[n])
      return;
    visited[n] = true;
    auto &neighbors = graph[n];
    for(int i = 0; i < neighbors.size(); ++i)
      if(neighbors[i])
        dfs(i);
  }
  int countComponents(int n, vector<vector<int>>& edges) {
    // build the graph
    graph = vector<vector<bool>>(n, vector<bool>(n ,false));
    for(auto &edge : edges)
      graph[edge[0]][edge[1]] = graph[edge[1]][edge[0]] = true;
    // count
    visited = vector<bool>(n ,false);
    int ans = 0;
    for(int i = 0; i < n; ++i)
      if(!visited[i]) {
        ++ans;
        dfs(i);
      }
    return ans;
  }
};