# 最长公共子序列

## 题目

给定两个字符串 s1 和 s2，返回这两个字符串的最长公共子序列的长度。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。

原题链接：[leetcode - 1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)

## 动态规划解法

$dp[i][j]$ 表示将 s1[0..i-1] （长度为 i 的前缀）转换 s2[0...j-1] （长度为 j 的前缀）的最长公共子序列的长度

$$
dp[i][j] = 
\begin{cases}
0 & i = 0 \ or \ j = 0\\
dp[i-1][j-1] + 1 & s1[i-1] = s2[j-1] \\
\max \{ dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + 1\} & s1[i-1] \neq s2[j-1]
\end{cases}
$$

```cpp
class Solution {
public:
  int longestCommonSubsequence(string &s1, string &s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= m; ++i)
      for(int j = 1; j <= n; ++j)
        if(s1[i-1] == s2[j-1])
          dp[i][j] = dp[i-1][j-1] + 1;
        else
          dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
    return dp.back().back();
  }
};
```