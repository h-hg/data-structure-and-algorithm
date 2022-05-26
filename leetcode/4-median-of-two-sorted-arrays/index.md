# Median of Two Sorted Arrays

- [Leetcode](https://leetcode.com/problems/median-of-two-sorted-arrays)
- [力扣中国](https://leetcode.cn/problems/median-of-two-sorted-arrays)

## Problem

[](desc.md ':include')

## Solution

### Merge

[](merge.cpp ':include :type=code cpp')

### Binary Search

假设两个有序数组分别是 $A$ 和 $B$，其数组长度分别为 $m$ 和 $n$。

根据中位数的定义，当 $m+n$ 是奇数时，中位数是两个有序数组中的第 $(m+n)/2$ 个元素，当 $m+n$ 是偶数时，中位数是两个有序数组中的第 $(m+n)/2$ 个元素和第 $(m+n)/2+1$ 个元素的平均值。因此，这道题可以转化成寻找两个有序数组中的第 $k$ 小的数，其中 $k$ 为 $(m+n)/2$ 或 $(m+n)/2+1$。

要找到第 $k$ 个元素，我们可以比较比较 $A$ 第 $k/2$ 个元素（$A[k/2-1]$） 和 $B$ 第 $k/2$ 个元素（$B[k/2-1]$），其中 $/$ 是整数除法。

- 如果 $A[k/2-1] < B[k/2-1]$，那么小于等于 $A[k/2-1]$ 的元素最多只有 $A[k/2-1]$ 及其前面的元素和 $B[k/2-1]$ 前面的元素，也就是多只有 $(k/2)+(k/2-1) = 2*(k/2)-1 < k $ 个元素，所以我们可以肯定 $A[0...(k/2-1)]$（一共 $k/2$ 个元素） 这部分元素没有我们想要的第 $k$ 个元素，将这部分舍去，在 $A[(k/2-1)...m]$ 和 $B[0...n]$ 中搜索第 $k-k/2$ 个元素，达到二分的效果。
- 如果 $A[k/2−1] > B[k/2−1]$，则可以排除 $B[0]$ 到 $B[k/2−1]$
- 如果 $A[k/2−1]=B[k/2−1]$，则可以归入第一种情况处理。

如果某一个数组的长度小于 $k/2$，我们就取最后一个元素“作为”第 $k/2$ 个元素，这样的话，最坏情况只会让我们舍去的元素少于 $k/2$。

[](binary-search.cpp ':include :type=code cpp')

还有一种实现，当某一个数组的长度小于 $k/2$，我们就取 `INT_MAX` “作为”第 $k/2$ 个元素

[](binary-search-2.cpp ':include :type=code cpp')

非递归的实现

[](binary-search-2-non-recursion.cpp ':include :type=code cpp')
