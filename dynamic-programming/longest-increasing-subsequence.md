# 最长递增子序列

## 问题

给定一个无序的整数数组 $nums[i]$，找到其中最长上升子序列的长度。

原题链接：[leetcode - 300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)

## 动态规划求解

$dp[i]$ 表示以 $nums[i]$ 这个数结尾的最长递增子序列的长度。

$$
dp[i] = \underset{j < i, nums[j] < nums[i]}{\max} \{ dp[j] + 1 \}
$$

$ans$ 表示最后的结果

$$
ans = \max \{ dp[i] \}
$$

```cpp
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    if(n == 0)
      return 0;
    vector<int> dp(n, 1);
    int ans = 1;
    for(int i = 1; i < n; ++i) {
      for(int j = 0; j < i; ++j) {
        if(nums[i] > nums[j])
          dp[i] = max(dp[j] + 1, dp[i]);
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
```

时间复杂度：$\Theta(n^2)$

## 二分查找法

[动态规划设计之最长递增子序列](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484498&idx=1&sn=df58ef249c457dd50ea632f7c2e6e761&chksm=9bd7fa5aaca0734c29bcf7979146359f63f521e3060c2acbf57a4992c887aeebe2a9e4bd8a89&scene=21#wechat_redirect)