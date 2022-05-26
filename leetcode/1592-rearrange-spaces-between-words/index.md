# Rearrange Spaces Between Words

- [Leetcode](https://leetcode.com/problems/rearrange-spaces-between-words)
- [力扣中国](https://leetcode.cn/problems/rearrange-spaces-between-words)

## Problem

[](desc.md ':include')

## Solution

### Extra Space

一个简单的方法就是用额外的空间来存储分隔出来的 word，然后计算两种 space 的数量，最后再把 word 和 space 拼接回去。

[](store-words.cpp ':include :type=code cpp')

注意点：

- 这里并没有计算多余的空格，而且利用 `text.size()` 和 `ans.size()` 的关系。

但是如果想要调库的话，可以写得更加简洁，但是理论上会了几次遍历。

[](store-words-2.cpp ':include :type=code cpp')

### Double Iteration

下面是另一个种方法，它不需要额外的空间来存储 word，但是需要额外遍历 `text` 一次。

[](optimal-space.cpp ':include :type=code cpp')

由于这道题 word 之间的 space 数量不定，暂时没有想到 inplace 的方法。
