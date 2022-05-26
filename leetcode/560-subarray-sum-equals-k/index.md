# Subarray Sum Equals K

- [Leetcode](https://leetcode.com/problems/subarray-sum-equals-k)
- [力扣中国](https://leetcode.cn/problems/subarray-sum-equals-k)

## Problem

[](desc.md ':include')

## Solution

### Dynamic Programming

利用前缀和

[](dp.cpp ':include :type=code cpp')

空间进一步优化为 $\Theta(1)$

[](space-1.cpp ':include :type=code cpp')

但是上述两者都是超时。

### Hash

[](hash.cpp ':include :type=code cpp')
