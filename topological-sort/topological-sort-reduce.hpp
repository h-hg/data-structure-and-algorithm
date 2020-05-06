#ifndef _TOPOLOGICAL_SORT_REDUCE_H
#define _TOPOLOGICAL_SORT_REDUCE_H

#include "topological-sort-base.hpp"
#include <queue>

std::vector<int> topological_sort_reduce(std::vector<std::vector<int>> const &e) {
	int n = e.size();
	std::vector<bool> vis(n, false);
	std::vector<int> ret;
	auto indegrees = getIndgrees(e);
	
	std::queue<int> q;
	for(int v = 0; v < n; ++v)
		if(indegrees[v] == 0)
			q.push(v);
	while(q.size()) {
		auto v = q.front();
		q.pop();
		if(vis[v])
			continue;
		vis[v] = true;
		ret.push_back(v);
		for(auto val : e[v])
			if(--indegrees[val] == 0)
				q.push(val);
	}
	return ret;
}


std::vector<int> topological_sort_reduce_loop(std::vector<std::vector<int>> const &e) {
	int n = e.size();
	std::vector<bool> vis(n, false);
	std::vector<int> ret;
	auto indegrees = getIndgrees(e);
	
	std::queue<int> q;
	for(int v = 0; v < n; ++v)
		if(indegrees[v] == 0)
			q.push(v);
	while(q.size()) {
		auto v = q.front();
		q.pop();
		if(vis[v])
			continue;
		vis[v] = true;
		ret.push_back(v);
		for(auto val : e[v])
			if(--indegrees[val] == 0)
				q.push(val);
	}
	return ret.size() == n ? ret : std::vector<int>();
}

#endif