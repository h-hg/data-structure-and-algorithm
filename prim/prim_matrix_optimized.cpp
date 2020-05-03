#include <climits>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>

//e is adjacent matrix
int prim(const std::vector<std::vector<int>> &e) {
  int n = e.size(), ret = 0;
  //init
  std::vector<int> d(n, INT_MAX);
  std::vector<bool> vis(n, false);
  //select v0 as starting vertex
  d[0] = 0;
  using P = std::pair<int, int>;//node id, d[id]
  std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
  pq.push({0, 0});
  while(pq.empty() == false) {
    //find the u
    auto p = pq.top();
    pq.pop();
    int u = p.second;
    if(vis[u])
      continue;
    // mark u
    vis[u] = true;
    ret += d[u];
    // update the d
    for(int v = 0; v < n; ++v)
      if(vis[v] || e[u][v] == INT_MAX)
        continue;
      else if(e[u][v] < d[v]) {
        d[v] = e[u][v];
        pq.push({d[v], v});
      }
  }
  return ret;
}