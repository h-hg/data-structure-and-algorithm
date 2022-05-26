# Populating Next Right Pointers in Each Node

- [Leetcode](https://leetcode.com/problems/populating-next-right-pointers-in-each-node)
- [力扣中国](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node)

## Problem

[](desc.md ':include')

## Solution

### Level Visit

[](level-visit.cpp ':include :type=code cpp')

### Iterative

迭代式方法，空间 $\Theta(1)$。

出发点：利用 `next` 连接的两个节点有一个共同的父节点。

[](space-o1.cpp ':include :type=code cpp')
