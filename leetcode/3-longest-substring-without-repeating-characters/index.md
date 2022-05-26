# Longest Substring Without Repeating Characters

- [Leetcode](https://leetcode.com/problems/longest-substring-without-repeating-characters)
- [力扣中国](https://leetcode.cn/problems/longest-substring-without-repeating-characters)

## Problem

[](desc.md ':include')

## Solution

### sliding window

[](sliding-window.cpp ':include :type=code cpp')

在缩小窗口时，原理就是在窗内找到新加入字符在窗口内另一最后位置。

可以使用映射的技巧来优化缩小窗口的速度。

[](sliding-window-optimization.cpp ':include :type=code cpp')
