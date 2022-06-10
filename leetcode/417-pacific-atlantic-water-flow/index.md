# Pacific Atlantic Water Flow

- [Leetcode](https://leetcode.com/problems/pacific-atlantic-water-flow)
- [力扣中国](https://leetcode.cn/problems/pacific-atlantic-water-flow)

## Problem

[](desc.md ':include')

## Solution

容易产生一个错误的想法，就是使用动态规划。
假定 $dp[i][j]$ 为布尔值，表示位置 $(i, j)$ 是否可以流入太平洋以及大西洋，那么
$$
dp[i][j] = dp[i-1][j] | dp[i+1][j] | dp[i][j-1] | dp[i][j+1]
$$

错误的原因在于，$(i, j)$ 可以通过 $(x_1, y_2)$ 达到太平洋，而通过 $(x_2, y_2)$ 达到大西洋，不一定要通过同一个地方达到两大洋。

我们可以倒着来，从低往高走。
左侧的位置一定流入进入太平洋，那么从这些点进行多源 BFS，即可得出哪些点可以流入太平洋。
类似的，右侧的位置一定可以流入大西洋，那么从这些点进行多源 BFS，即可得出哪些点可以流入大西洋。
对上面两个集合取个交集，就可以知道哪些点可以流入太平洋以及大西洋。

[](mutl-bfs.cpp ':include :type=code cpp')
