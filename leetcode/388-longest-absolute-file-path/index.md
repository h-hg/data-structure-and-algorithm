# Longest Absolute File Path

- [Leetcode](https://leetcode.com/problems/longest-absolute-file-path)
- [力扣中国](https://leetcode.cn/problems/longest-absolute-file-path)

## Problem

[](desc.md ':include')

## Solution

一道利用 stack 的题目。
思路：顺序扫描字符串，如果新的文件/目录是在下一层，则将新的文件/目录压栈，否则则弹栈直到符合的层（注意不止弹一次）。
从栈底到栈顶存放的就是就是当前扫描到的文件/目录的绝对路径。

[](solution.cpp ':include :type=code cpp')

注意点：

- 题目要求的是最大长度，所以栈里可以不用存储文件名（`string`），只需要要当前获得的最大长度。
- 使用 vector 去模拟 stack，可以简单使用 `resize` 来实现多次弹栈，提高速度。
- `input` 在尾部插入 `\n`，可以减少判断指针是否到达字符串末尾。
- 在栈底插入一个 `-1`，可以统一处理路径中 `/` 所增加的长度

如果不考虑速度（多了一些来回扫描）的话，使用 STL 来实现可以更加简洁。

[](stl.cpp ':include :type=code cpp')
