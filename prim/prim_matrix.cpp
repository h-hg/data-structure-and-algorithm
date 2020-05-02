#include <vector>
#include <climits>
#include <iostream>
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


using namespace std;
int main() {
  vector<vector<int>> graph = {
    {0, 6, 1, 5, INT_MAX, INT_MAX},
    {6, 0, 5, INT_MAX, 3, INT_MAX},
    {1, 5, 0, 5, 6, 4},
    {5, INT_MAX, 5, 0, INT_MAX, 2},
    {INT_MAX, 3, 6, INT_MAX, 0, 6},
    {INT_MAX, INT_MAX, 4, 2, 6, 0}
  };
  cout << prim(graph) << endl;
  return 0;
}