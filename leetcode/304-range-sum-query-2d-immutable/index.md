# Range Sum Query 2D - Immutable

- [Leetcode](https://leetcode.com/problems/range-sum-query-2d-immutable)
- [力扣中国](https://leetcode.cn/problems/range-sum-query-2d-immutable)

## Problem

[](desc.md ':include')

## Solution

动态规划的解法

题目给的坐标都是从 0 开始的，为了方便表示，另其从 1 开始。

定义 `dp` 表达

$$
dp[i][j] =
\begin{cases}
    0 & i = 0 \text{ or } j = 0 \\
    \sum_{k=1}^i\sum_{l=1}^j matrix[k][l] & \text{other}
\end{cases}
$$

推导 `dp` 的递推公式

$$
dp[i][j-1] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + matrix[i][j]
$$

求解问题跟 `dp` 的联系

$$
sumRegion(row1, col1, row2, col2) = dp[row2][col2] - dp[row2][col1 - 1] - dp[row1 - 1][col2] + dp[row1 - 1][col1 - 1]
$$

[](solution.cpp ':include :type=code cpp')
