# Count of Smaller Numbers After Self

- [Leetcode](https://leetcode.com/problems/count-of-smaller-numbers-after-self)
- [力扣中国](https://leetcode.cn/problems/count-of-smaller-numbers-after-self)

## Problem

[](desc.md ':include')

## Solution

### Insertion Sort

从倒数第二个 `num`，开始往前遍历，使用类似插入排序的思路。
如果这个 `num` 比后面的数字大，则交换两者的位置，直到无法交换，交换的次数为这个 `num` 对应的 `count`。

[](insertion-sort.cpp ':include :type=code cpp')

时间复杂度为 $\Theta(n^2)$，结果 timeout.

### Merge Sort

