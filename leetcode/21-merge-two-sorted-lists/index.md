# Merge Two Sorted Lists

- [Leetcode](https://leetcode.com/problems/merge-two-sorted-lists)
- [力扣中国](https://leetcode.cn/problems/merge-two-sorted-lists)

## Problem

[](desc.md ':include')

## Solution

[](solution.cpp ':include :type=code cpp')

上面有两个地方比较值得注意

1. 使用一个空节点来表示头节点，避免了循环前还要判断。
2. 使用 `ListNode * &` 来减少 `if else` 语句。
