# Palindrome Number

- [Leetcode](https://leetcode.com/problems/palindrome-number)
- [力扣中国](https://leetcode.cn/problems/palindrome-number)

## Problem

[](desc.md ':include')

## Solution

这道题最简单的想法便是将整个数字进行反转，然后比较反转后的数字是否跟原来的一样即可。为了避免反转后的数字溢出的话，我们应该使用 `long long` 来存储反转后的数字。

更为简单的是，可以只反转一半的数字，例如 1221，反转一半变成 12**12**，然后比较反转的一半与没有反转的一半是否相同即可。

**具体步骤：**

首先，考虑一些临界情况，对于负数和个位为零的非零正数应该返回 `false`。

执行流程，大致为不断从原来的数字 `x` 中溢出最后一位数字 `d`，同时将该数字追加到反转的一半 `reverseNumber` 后，直到反转的数字达到一半。

现在的问题是，我们如何知道反转数字的位数已经达到原始数字位数的一半？当 `x < reverseNumber` 不成立的时候，就意味着我们已经处理了一半位数的数字了。

值得注意的是，上面的停止条件，对于数字个数为奇数的数字（如 12321），我们需要用 `x == reverseNumber / 10` 来判断其原来的数字是否为回文数。

[](solution.cpp ':include :type=code cpp')