# Reverse Linked List II

- [Leetcode](https://leetcode.com/problems/reverse-linked-list-ii)
- [力扣中国](https://leetcode.cn/problems/reverse-linked-list-ii)

## Problem

[](desc.md ':include')

## Solution

[](solution.h ':include :type=code cpp')

## Converional method

常规方法：先把要反转的部分切分出来，使用 leetcode 206 的方法反转，最后再连接回去。

[](convention.cpp ':include :type=code cpp')

### vector

一个直接的方法就是把所有节点都存进 vector，然后在 vector 中进行部分反转。

这是一种典型的空间换取写代码的方便。

[](vector.cpp ':include :type=code cpp')

注意点：

1. 在 vector 多加了首尾两个节点，其中首节点指向第一个节点，最后一个节点指向尾节点（`nullptr`），这样减少了 `left` 为第一个节点、`right` 为最后一个节点这两种特殊情况的处理。

### Iterative Link Reversal

这是一种边迭代边反转的方案。

主要步骤如下：

1. 先找到反转第一个要反转的节点的前一个节点，记为 `prevLeft`
2. 令第一个要反转的节点为 `cur`
3. 不断把 `cur` 后面节点插到 `prevLeft` 后面，直到 `cur` 成为第 `right` 节点。

例如要反转的数据为

```
l = [1, 2, 3, 4, 5]
left = 2
right = 4
```

其反转过程如下所示

![](iterative-link-reversal.drawio.svg '反转示意图')

在步骤 2 中，不断后把节点插入在反转部分的头部，也被称为 “头插法”。

[](iterative-link-reversal.cpp ':include :type=code cpp')
