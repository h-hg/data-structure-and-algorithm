#include <climits>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>
std::vector<int> dijkstra(const std::vector<std::vector<int>> &e, int s) {
  int n = e.size();
  std::vector<bool> vis(n, false);
  // init
  std::vector<int> d(n, INT_MAX);
  d[s] = 0;
  using P = std::pair<int, int>;//node id, d[id]
  std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
  pq.push({0, s});
  while(pq.empty() == false) {
    //find the u
    auto p = pq.top();
    pq.pop();
    int u = p.second;
    if(vis[u])
      continue;
    // mark u
    vis[u] = true;
    // update the d
    for(int v = 0; v < n; ++v) {
      if(vis[v] || e[u][v] == INT_MAX)
        continue;
      //Dijkstra equation
      if(d[u] + e[u][v] < d[v]) {
        d[v] = d[u] + e[u][v];
        pq.push({d[v], v});
      }
    }
  }
  return d;
}

int main() {
  using namespace std;
  vector<vector<int>> graph = {
    {0, INT_MAX, 10, INT_MAX, 30, 100},
    {INT_MAX, 0, 5, INT_MAX, INT_MAX, INT_MAX},
    {INT_MAX, INT_MAX, 0, 50, INT_MAX, INT_MAX},
    {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 10},
    {INT_MAX, INT_MAX, INT_MAX, 20, 0, 60},
    {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}
  };
  for(auto val: dijkstra(graph, 0))
    if(val == INT_MAX)
      cout << "oo ";
    else
      cout << val << ' ';
  cout << endl;
  return 0;
}