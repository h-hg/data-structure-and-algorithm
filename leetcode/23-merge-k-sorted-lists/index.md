# Merge k Sorted Lists

- [Leetcode](https://leetcode.com/problems/merge-k-sorted-lists)
- [力扣中国](https://leetcode.cn/problems/merge-k-sorted-lists)

## Problem

[](desc.md ':include')

## Solution

[](solution.h ':include :type=code cpp')

### Merge Two

一种简单的方法，就是使用 LeetCode 21 的两两合并的策略。

[](merge-two.cpp ':include :type=code cpp')

注意点：

1. `ret = nullptr` 减少了许多 `if` 语句的使用。

### Brute Sort

暴力排序法，把所有元素都扔进 `vector`，再给 `vector` 排序，最后再形成有序列表。

[](sort.cpp ':include :type=code cpp')

注意点：

1. 由于节点不是重新 `new` 的，记得 `cur -> next = nullptr`

## Heap Sort

堆排法，基本思路，把每个 `list` 的首个元素都放在堆里，每次从堆拿出一个，再放入一个，放入的是拿出的节点的下一个节点，若没有下一个节点，则不放，不断重复，直到堆为空。

[](heap-sort.cpp ':include :type=code cpp')
