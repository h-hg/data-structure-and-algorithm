#include "../union-find-set/union-find-set.hpp"
#include <climits>
#include <algorithm>
#include <iostream>
struct Edge {
  int u, v;// edge from u to v (or v to u)
  int w;//weight
  Edge(int i, int j, int weight):u(i), v(j), w(weight) {}
  bool operator<(Edge const&e) const {return w < e.w;}
};

//e is adjacent matrix
//return the sum of the smallest edge weight, return -1 when the graph is not the connected graph
int kruskal(std::vector<std::vector<int>> const &e) {
  int n = e.size(), ret = 0;
  //init the edge
  std::vector<Edge> edges;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < i; ++j)
      if(e[i][j] != INT_MAX)
        edges.push_back(Edge(i, j, e[i][j]));
  //sort the edge
  std::sort(edges.begin(), edges.end());
  //init the union find set
  UFSB ufs(n);
  for(auto &e : edges) {
    int faU = ufs.findRoot(e.u), faV = ufs.findRoot(e.v);
    if(faU == faV)
      continue;
    ufs.merge(faU, faV);
    ret += e.w;
    if(--n == 1)
      break;
  }
  return n == 1 ? -1 : ret;
}