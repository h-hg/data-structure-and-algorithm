# Palindrome Linked List

- [Leetcode](https://leetcode.com/problems/palindrome-linked-list)
- [力扣中国](https://leetcode.cn/problems/palindrome-linked-list)

## Problem

[](desc.md ':include')

## Solution

[](solution.h ':include :type=code cpp')

### vector

把所有的节点都扔进 vector，再从左右端遍历判断。

典型的空间换写代码的方便。

[](vector.cpp ':include :type=code cpp')

### stack

上面将节点扔进 vector，就是为了方便遍历。
这种逆序的遍历，可以使用 stack。
先把所有节点扔进 stack，再弹栈，得到的顺序就是逆序。

[](stack.cpp ':include :type=code cpp')

递归版本如下

[](recursion.cpp ':include :type=code cpp')

递归版主要利用全局变量来保存尾端的数据。

## Two pointers

1. 使用快慢指针找到中间节点（若有两个，则是第二个），参考 leetcode 876
2. 反转后部分，参考 leetcode 206
3. 从两端判断是否为回文串

[](two-pointers.cpp 'include :type=code cpp')
