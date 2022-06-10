# Russian Doll Envelopes

- [Leetcode](https://leetcode.com/problems/russian-doll-envelopes)
- [力扣中国](https://leetcode.cn/problems/russian-doll-envelopes)

## Problem

[](desc.md ':include')

## Solution

### Dyamic Programming

如果给信封定义一个比较函数，让信封从小到大排序，那么题目就就可以转化为找出最长的（严格）递增子序列。
这跟 leetocde 300 是一样的。

[](dp1.cpp ':include :type=code cpp')

这道题可以简化一些逻辑。
在排序的时候，当宽度一样的时候，让高度大的信封排在前面。
这样在后面比较的时候，只需要比较高度即可。
因为宽度已经是（非严格）递增排序，而宽度相同的情况下，前面的总不能装下后面的。

[](dp2.cpp ':include :type=code cpp')

但还是超时

[](solution.cpp ':include :type=code cpp')
