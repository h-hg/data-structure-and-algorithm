#ifndef _TOPOLOGICAL_SORT_DFS_H
#define _TOPOLOGICAL_SORT_DFS_H

#include "topological-sort-base.hpp"
#include <algorithm>

void topological_sort_dfs_helper(int v, std::vector<std::vector<int>> const &e,  std::vector<bool> &vis, std::vector<int> &vec) {
	if(vis[v])
		return;
	vis[v] = true;
	for(auto val: e[v])
		topological_sort_dfs_helper(val, e, vis, vec);
	vec.push_back(v);
}
std::vector<int> topological_sort_dfs(std::vector<std::vector<int>> const &e) {
  int n = e.size();
	std::vector<bool> vis(n, false);
	std::vector<int> ret;
  //init inedgree
  auto indegrees = getIndgrees(e);
	for(int v = 0; v < n; ++v)
		if(indegrees[v] == 0)
			topological_sort_dfs_helper(v, e, vis, ret);
	std::reverse(ret.begin(), ret.end());
  return ret;
}

//return true when there is a loop
bool topological_sort_dfs_loop_helper(int v, std::vector<std::vector<int>> const &e, std::vector<bool> &vis, std::vector<int> &vec, std::vector<bool> &curPath) {
	if(curPath[v])
		return true;
	if(vis[v])
		return false;
	//visit the vertex v
	curPath[v] = true;
	vis[v] = true;
	for(auto val: e[v])
		if(topological_sort_dfs_loop_helper(val, e, vis, vec, curPath))
			return true;
	//backtracing
	curPath[v] = false;
	vec.push_back(v);
	return false;
}
std::vector<int> topological_sort_dfs_loop(std::vector<std::vector<int>> const &e) {
  int n = e.size();
	std::vector<bool> vis(n, false), curPath(n, false);
	std::vector<int> ret;
  //init inedgree
  auto indegrees = getIndgrees(e);
	for(int v = 0; v < n; ++v)
		if(indegrees[v] == 0)
			if(topological_sort_dfs_loop_helper(v, e, vis, ret, curPath))
				return std::vector<int>();
	std::reverse(ret.begin(), ret.end());
  return ret;
}


#endif