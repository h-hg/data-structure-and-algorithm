# Maximum Product Subarray

- [Leetcode](https://leetcode.com/problems/maximum-product-subarray)
- [力扣中国](https://leetcode.cn/problems/maximum-product-subarray)

## Problem

[](desc.md ':include')

## Solution

### Dymanic Programming

leetcode 53 的变体

由于乘法要考虑负负得正的情况，所以要考虑连续最小数组乘积和。

记 $dpMax[i]$ 为以 $nums[i]$ 结尾的最大连续子数组乘积和，$dpMin[i]$ 为以 $nums[i]$ 结尾的最小连续子数组乘积和。

$$
dpMax[i] = \max \{ nums[i], dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i] \} \\
dpMin[i] = \min { nums[i], dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i] \}
$$

那么 $ans = \max\limits_i dpMax[i]$

[](solution.cpp ':include :type=code cpp')
