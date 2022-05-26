# Car Pooling

- [Leetcode](https://leetcode.com/problems/car-pooling)
- [力扣中国](https://leetcode.cn/problems/car-pooling)

## Problem

[](desc.md ':include')

## Solution

$[numPassengers_i, from_i, to_i]$ 相当于给区间 $[from_i, to_i)$ 加上 $numPassengers_i$。
进而使用差分数组的方法。
最后判断所有区间是否都小于 `capactiy`。

[](solution.cpp ':include :type=code cpp')
