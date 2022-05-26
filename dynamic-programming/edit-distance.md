# 编辑距离

给你两个单词 s1 和 s2，请你计算出将 s1 转换成 s2 所使用的最少操作数 。

你可以对一个字符串进行如下三种操作：

1. 插入一个字符
2. 删除一个字符
3. 替换一个字符

原题链接：[leetcode - 72. edit distane](https://leetcode.com/problems/edit-distance)

## 动态规划解法

$dp[i][j]$ 表示将 s1[0..i-1] （长度为 i 的前缀）转换 s2[0...j-1] （长度为 j 的前缀）所使用的最少操作

$$
dp[i][j] = 
\begin{cases}
j & i = 0 \\
i & j = 0 \\
dp[i-1][j-1] & s1[i-1] = s2[j-1] \\
\min \{ dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1\} & s1[i-1] \neq s2[j-1]
\end{cases}
$$


```cpp
class Solution {
public:
  int minDistance(string &s1, string &s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for(int i = 0; i <= m; ++i)
      for(int j = 0; j <= n; ++j)
        if(i == 0)
          dp[i][j] = j;
        else if(j == 0)
          dp[i][j] = i;
        else if(s1[i-1] == s2[j-1])
          dp[i][j] = dp[i-1][j-1];
        else
          dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
    return dp.back().back();
  }
};
```