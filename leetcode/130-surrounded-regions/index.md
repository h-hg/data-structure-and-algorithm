# Surrounded Regions

- [Leetcode](https://leetcode.com/problems/surrounded-regions)
- [力扣中国](https://leetcode.cn/problems/surrounded-regions)

## Problem

[](desc.md ':include')

## Solution

广度优先搜索。
从四个边缘的 `O` 进行多源 BFS 搜索，标记与这些 `O` 相接的 `O`，那么剩余的 `O` 就是需要被改成 `X`。

[](solution.cpp ':include :type=code cpp')
