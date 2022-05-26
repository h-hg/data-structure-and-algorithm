# Missing Number

- [Leetcode](https://leetcode.com/problems/missing-number)
- [力扣中国](https://leetcode.cn/problems/missing-number)

## Problem

[](desc.md ':include')

## Solution

### Sum

由 $1 \le n \le 10^4$，可知 $(1 + 10^4) / 2  < 2^31 - 1$。
直接对 `nums` 求和，利用和来看是哪个数确了。

[](sum.cpp ':include :type=code cpp')

### XOR

根据 leetcode 136，可以把 `[0, n]` 以及 `nums` 所有数字都使用 XOR 连接起来，结果就是缺少的数字。

这样的好处就是不用考虑求和溢出。

[](xor.cpp ':include :type=code cpp')