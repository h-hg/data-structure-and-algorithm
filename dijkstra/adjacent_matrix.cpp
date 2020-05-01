#include <climits>
#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> dijkstra(const std::vector<std::vector<int>> &e, int s) {
  int n = e.size();
  std::vector<bool> vis(n, false);
  // init the d
  std::vector<int> d(n, INT_MAX);
  d[s] = 0;
  for(int i = 0; i < n; ++i) {
    //find the u
    int u = -1;
    for(int j = 0, curMin = INT_MAX; j < n; ++j)
      if(vis[j] == false && d[j] < curMin) {
        u = j;
        curMin = d[j];
      }
    if(u == -1)
      return d;
    // mark u
    vis[u] = true;
    // update the d
    for(int v = 0; v < n; ++v) {
      if(vis[v] || e[u][v] == INT_MAX)
        continue;
      //Dijkstra equation
      d[v] = std::min(d[v], d[u] + e[u][v]);
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