# Search Insert Position

- [Leetcode](https://leetcode.com/problems/search-insert-position)
- [力扣中国](https://leetcode.cn/problems/search-insert-position)

## Problem

[](desc.md ':include')

## Solution

二分查找。

方法一，利用 `mid` 的值，有如下三种情况。

1. 如果 `target` 小于 `nums` 任何数字，那么最后 `mid = 0`，直接 `return mid`。（满足 `nums[mid] > target`）
2. 如果 `target` 大于 `nums` 任何数字，那么最后 `mid = nums.size() - 1`，那么 `return mid + 1`。（满足 `nums[mid] < target`）
3. 如果 `target` 介于 `nums`，最后肯定满足 `nums[mid - 1] < target < nums[mid + 1]`，而 `nums[mid]` 跟 `target` 的关系是未知。只需要根据 `target` 跟 `nums[mid]` 的关系，与上面情况 1 和 2 一样，来决定返回 `mid` 还是 `mid + 1`。

[](bs.cpp ':include :type=code cpp')

