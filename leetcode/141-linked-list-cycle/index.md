# Linked List Cycle

- [Leetcode](https://leetcode.com/problems/linked-list-cycle)
- [力扣中国](https://leetcode.cn/problems/linked-list-cycle)

## Problem

[](desc.md ':include')

## Solution

[](solution.h ':include :type=code cpp')

快慢指针法，`fast` 指针每次都走两步，`slow` 指针每次走一步。
如果 `fast` 和 `slow` 相遇，则说明，有环；
反之，`fast` 到达末尾（`nullptr`），则说明没环。

证明：由于快指针走得比慢指针快，如果存在环的话，快指针总会走到慢指针后面，并且快指针每次走两步，慢指针每次走一步，说明它们之间的距离不断减一，所以在有环的情况下，它们终会相遇。

[](solution.cpp ':include :type=code cpp')
