# Advantage Shuffle

- [Leetcode](https://leetcode.com/problems/advantage-shuffle)
- [力扣中国](https://leetcode.cn/problems/advantage-shuffle)

## Problem

[](desc.md ':include')

## Solution

贪心法，类似于田忌赛马。
基本思路，用 `nums1` 的最大者与 `nums2` 的最大者比较，若 `nums1` 的大，则匹对成功，否则用 `nums1` 的最小者与 `nums2` 的最大者匹配，不断循环此过程，直至匹配结束。

[](solution.cpp ':include :type=code cpp')
