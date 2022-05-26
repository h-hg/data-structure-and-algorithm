#include <vector>
#include <climits>
#include <iostream>

//e is adjacent matrix
//return the sum of the smallest edge weight, return -1 when the graph is not the connected graph
int prim(std::vector<std::vector<int>> const &e) {
  int n = e.size(), ret = 0;
  //init
  std::vector<int> d(n, INT_MAX);
  std::vector<bool> vis(n, false);
  //select v0 as starting vertex
  d[0] = 0;
  for(int i = 0; i < n; ++i) {
    int u = -1;
    for(int j = 0, curMin = INT_MAX; j < n; ++j)
      if(vis[j] == false && d[j] < curMin) {
        u = j;
        curMin = d[j];
      }
    if(u == -1)
      return -1;
    vis[u] = true;
    ret += d[u];
    for(int v = 0; v < n; ++v)
      if(vis[v] || e[u][v] == INT_MAX)
        continue;
      else if(e[u][v] < d[v])
        d[v] = e[u][v];
  }
  std::cout << std::endl;
  return ret;
}