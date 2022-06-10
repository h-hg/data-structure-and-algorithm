# Shortest Bridge

- [Leetcode](https://leetcode.com/problems/shortest-bridge)
- [力扣中国](https://leetcode.cn/problems/shortest-bridge)

## Problem

[](desc.md ':include')

## Solution

思路，先找到一个岛的一个点，标记该点，然后使用 BFS 标志整个岛。
再将整座岛的点看作 BFS 的源头，使用 BFS 计算到另一个岛的最短距离。

[](bfs.cpp ':include :type=code cpp')
