# Remove Duplicates from Sorted Array

- [Leetcode](https://leetcode.com/problems/remove-duplicates-from-sorted-array)
- [力扣中国](https://leetcode.cn/problems/remove-duplicates-from-sorted-array)

## Problem

[](desc.md ':include')

## Solution

因为 `nums` 是有序的，不考虑的原地修改的话，其基本思路如下。

新建一个新 `nums`，遍历 `nums` 的元素，判断元素是否与新 `nums` 末尾元素一样，不一样的则将该元素添加到新 `nums` 的末尾，一样的不采取操作。

但是题目要求原地操作，可以采用“双指针”法。
`slow` 指针指向“新 `nums`”的最后一个元素，`fast` 用于从头到尾遍历原 `nums`。

[](solution.cpp ':include :type=code cpp')
