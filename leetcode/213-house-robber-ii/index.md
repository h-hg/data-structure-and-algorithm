# House Robber II

- [Leetcode](https://leetcode.com/problems/house-robber-ii)
- [力扣中国](https://leetcode.cn/problems/house-robber-ii)

## Problem

[](desc.md ':include')

## Solution

注意到当房屋数量不超过两间时，最多只能偷窃一间房屋，因此不需要考虑首尾相连的问题。如果房屋数量大于两间，就必须考虑首尾相连的问题，第一间房屋和最后一间房屋不能同时偷窃。

假设数组 $nums$ 的长度为 $n$。
如果不偷窃最后一间房屋，则偷窃房屋的下标范围是 $[0, n−1)$；
如果不偷窃第一间房屋，则偷窃房屋的下标范围是 $[1,n)$。
在确定偷窃房屋的下标范围之后，即可用 leetcode 198 题的方法解决。
对于两段下标范围分别计算可以偷窃到的最高总金额，其中的最大值即为在 $n$ 间房屋中可以偷窃到的最高总金额。

[](dp.cpp ':include :type=code cpp')
