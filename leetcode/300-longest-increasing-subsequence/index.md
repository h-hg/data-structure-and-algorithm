# Longest Increasing Subsequence

- [Leetcode](https://leetcode.com/problems/longest-increasing-subsequence)
- [力扣中国](https://leetcode.cn/problems/longest-increasing-subsequence)

## Problem

[](desc.md ':include')

## Solution

动态规划。

记 $dp[i]$ 为以 $nums[i]$ 结尾的最长递增子序列的长度，那么答案为
$$
ans = \max\limts_{i} dp[i]
$$

$dp[i]$ 的递推关系如下
$$
dp[i] = \max\limits_{j < i \text{ and } nums[j] < nums[i]} dp[j] + 1
$$

自顶向下的实现

[](top-2-down.cpp ':include :type=code cpp')

自底向上的实现

[](down-2-top.cpp ':include :type=code cpp')
