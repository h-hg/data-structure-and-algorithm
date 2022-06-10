# Number of Longest Increasing Subsequence

- [Leetcode](https://leetcode.com/problems/number-of-longest-increasing-subsequence)
- [力扣中国](https://leetcode.cn/problems/number-of-longest-increasing-subsequence)

## Problem

[](desc.md ':include')

## Solution

leetcode 300 的变体。

$dp$ 除了需要记录长度之外，还需要记录该长度对应的数量。

[](solution.cpp ':include :type=code cpp')

在上述代码中，

- $dp[i].first$ 表示以 $nums[i]$ 结尾的最长子序列的长度
- $dp[i].second$ 表示以 $nums[i]$ 结尾的最长子序列的数量
