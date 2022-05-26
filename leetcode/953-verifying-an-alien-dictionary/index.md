# Verifying an Alien Dictionary

- [Leetcode](https://leetcode.com/problems/verifying-an-alien-dictionary)
- [力扣中国](https://leetcode.cn/problems/verifying-an-alien-dictionary)

## Problem

[](desc.md ':include')

## Solution

Hash 的题目。

一个简单的思路，就是给外星词典每一个字母一个权重（等级）。
例如 `order = "hlabcdefgijkmnopqrstuvwxyz"`，`h` 的权重就是 1，而 `l` 就是 `2`。
然后再自己重写一个比较字符串的函数。

[](hash1.cpp ':include :type=code cpp')

另一个思路，就是可以把外星单词转化为我们的字符顺序。
例如 `order = "hlabcdefgijkmnopqrstuvwxyz"`，那么我们就将外星单词的 `h` 转化为 `a`，`l` 转化为 `b`。
这样的好处就是不用自己重写比较字符串的函数，坏处就是多了一遍遍历。

[](hash2.cpp ':include :type=code cpp')
