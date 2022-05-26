#ifndef _TOPOLOGICAL_SORT_BASE_H
#define _TOPOLOGICAL_SORT_BASE_H

#include <vector>
//e is adjacent list
std::vector<int> getIndgrees(std::vector<std::vector<int>> const &e) {
  int n = e.size();
  std::vector<int> indegrees(n, 0);
  for(auto &vec: e)
    for(auto v: vec)
      ++indegrees[v];
  return indegrees;
}

#endif