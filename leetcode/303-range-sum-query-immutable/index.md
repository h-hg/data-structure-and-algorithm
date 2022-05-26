# Range Sum Query - Immutable

- [Leetcode](https://leetcode.com/problems/range-sum-query-immutable)
- [力扣中国](https://leetcode.cn/problems/range-sum-query-immutable)

## Problem

[](desc.md ':include')

## Solution

一道简单的前缀和的应用。

题目给的 `left` 和 `right` 都是从 0 开始，为了表达的方便，令其从 1 开始。

$$
preSums[i] =
\begin{cases}
    \sum_{k=1}^{i} nums[k] & i > 0 \\
    0 & i = 0
\end{cases}
$$

$$
\sum_{k=i}^j nums[k] = preSums[j] - preSums[i - 1]
$$

其实也可以从动态规划的角度进行理解，毕竟递推公式都有了。

递推公式为

$$
sumRange(i, j)= sumRange(0, j) - sumRange(0, i - 1)
$$

即

$$
dp[i][j] = dp[0][j] - dp[0][i - 1]
$$

式子右边，第一个参数都是 0，可以降维，没必要使用二维 `dp` 数组。

$$
sumRange(i, j) = dp[j] - dp[i - 1]
$$

[](solution.cpp ':include :type=code cpp')
