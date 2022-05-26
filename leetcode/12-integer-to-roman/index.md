# Integer to Roman

- [Leetcode](https://leetcode.com/problems/integer-to-roman)
- [力扣中国](https://leetcode.cn/problems/integer-to-roman)

## Problem

[](desc.md ':include')

## Solution

### Greedy

罗马数字由 7 个单字母符号组成，每个符号都有自己的价值。此外，减法规则（如问题描述中所述）给出了额外的 6 个符号。这给了我们总共 13 个独特的符号（每个符号由 1 个字母或 2 个字母组成）。

从例子中可以看出，从左往右，都是价值大的符号排在价值小的前面。这让我们想到了贪心算法。

[](greedy.cpp ':include :type=code cpp')


### Reverse Representation

在下面的实现中，从个位依次向高位考虑，得到反转的罗马数字，最后再反转即可得到答案。

[](reverse-representation.cpp ':include :type=code cpp')