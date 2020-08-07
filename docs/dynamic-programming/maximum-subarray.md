# 最大子数组和

给定一个整数数组 $nums$ ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

原题链接：[leetcode - 53. maximum subarray](https://leetcode.com/problems/maximum-subarray/)

## 动态规划解法

$dp[i]$ 表示以 $nums[i]$ 结尾的最大子数组和

$$
dp[i] = \max \{ nums[i], dp[i - 1] + nums[i] \}
$$

$ans$ 表示最后的结果

$$
ans = \max \{ dp[i] \}
$$

```cpp
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.size());
    int ans = dp.front() = nums.front();
    for(int i = 1;i < nums.size();++i) {
      dp[i] = max(nums[i],nums[i]+dp[i-1]);
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
```

优化一下空间

```cpp
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int dp = nums.front(), ans = dp;
    for(int i = 1;i < nums.size();++i) {
      dp = max(nums[i],nums[i]+dp);
      ans = max(ans, dp);
    }
    return ans;
  }
};
```

## 滑动窗口解法

