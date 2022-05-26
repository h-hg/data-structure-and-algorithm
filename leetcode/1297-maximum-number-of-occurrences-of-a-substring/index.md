# Maximum Number of Occurrences of a Substring

- [Leetcode](https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring)
- [力扣中国](https://leetcode.cn/problems/maximum-number-of-occurrences-of-a-substring)

## Problem

[](desc.md ':include')

## Solution

滑动窗口。

思路：如果一个字符子串 `ss` 的长度满足 `minSize <= subs.size() <= maxSize`，且它的出现的次数最多，那么 `ss` 的字串 `sss`（`sss = ss[:minSize]`） 出现的次数也是最多，两者次数一样。
这暗示字符子串的长度限制只看 `minSize` 就行，因为题目只要求输出次数即可。

[](solution.cpp ':include :type=code cpp')
