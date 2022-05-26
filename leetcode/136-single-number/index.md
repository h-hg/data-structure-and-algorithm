# Single Number

- [Leetcode](https://leetcode.com/problems/single-number)
- [力扣中国](https://leetcode.cn/problems/single-number)

## Problem

[](desc.md ':include')

## Solution

异或运算

1. $a \oplus a = 0$
2. $a \oplus b = b \oplus a$
3. $a \oplus b \oplus c = a \oplus (b \oplus c) = (a \oplus b) \oplus c$
4. $a \oplus 0 = a$

由 3 和 4 可以推导出 $a \oplus b \oplus a = a \oplus (b \oplus a) = a \oplus (a \oplus b) = (a \oplus a) \oplus b = b$

上面的推论可以理解为 $\oplus$ 跟乘法一样，可以随意交换位置，不影响结果。

如果把题目中所有 `num` 都使用 $\oplus$ 连接起来，即 `ans = nums[1] ^ ... ^ nums[n-1]`。
由于只有一个数字只出现一次，不妨另该数为 a，那么 `ans = a ^ (b ^ b) ^ (c ^ c) ^ ... ^ (z ^ z) = a`

[](solution.cpp ':include :type=code cpp')
