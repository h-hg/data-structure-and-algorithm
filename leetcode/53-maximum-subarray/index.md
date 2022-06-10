# Maximum Subarray

- [Leetcode](https://leetcode.com/problems/maximum-subarray)
- [力扣中国](https://leetcode.cn/problems/maximum-subarray)

## Problem

[](desc.md ':include')

## Solution

### Dynamic Programming

$dp[i]$ 表示以 $nums[i]$ 结尾的最大连续子数组和，即有
$$
dp[i] = \max \{nums[i], dp[i-1] + nums[i]\}
$$

$ans$ 表示最后的结果，那么
$$
ans = \max \{ dp[i] \}
$$

[](dp1.cpp ':include :type=code cpp')

注意：上面的代码使用了引用（别名，`&`），减少了空间的使用。

但实际上，若不能修改 $nums$ 的话，可以则需要重新申请一个 $\Theta(n)$（$n$ 为 $nums$ 的大小）。
从上面的可以，$dp[i]$ 的计算只依赖于 $dp[i-1]$，所以可以对 $dp$ 进行压缩为一个元素。

[](dp2.cpp ':include :type=code cpp')

### Sliding Window

这道题使用滑动窗口做的难点，在于滑动窗口什么时候缩写以及什么时候更新目标值（最大的子数组和）。
一个错误的想法就是保持窗口内的元素都是正的。
举个例子，`[5, -1, 6]`，在该例子中，最大子数组和为整个数组，包含了一个负数。

解释，见 [最长子序和（滑动窗口）](https://leetcode.cn/problems/maximum-subarray/solution/zui-chang-zi-xu-he-hua-dong-chuang-kou-b-cw0h/)

[](sliding-window.cpp ':include :type=code cpp')
