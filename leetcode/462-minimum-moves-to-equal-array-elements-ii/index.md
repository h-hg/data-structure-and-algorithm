# Minimum Moves to Equal Array Elements II

- [Leetcode](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii)
- [力扣中国](https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-ii)

## Problem

[](desc.md ':include')

## Solution

### Math Proof

记 $a$ 为数组（为了阐述方便，下标从 1 开始），$n$ 为数组 $a$ 的长度，经调整后所有元素都为 $x$。

当 $n = 2k$ 为偶数时，有

$$
\begin{aligned}
    \sum_{i=1}^n |a_i - x|
    &= |x - a_1| + ... + |x - a_k| + |x - a_{k+1}| + ... + |x - a_{2k}| \\
    &= |x - a_1| + ... + |x - a_k| + |a_{k+1} - x| + ... + |a_{2k} - x| \\
    &\ge |x - a_1 + ... + x - a_k + a_{k+1} - x + ... + a_{2k} - x| \\
    &= |-a_1 - ... - a_k + a_{k+1} + ... + a_{2k}|
\end{aligned}
$$

当如下等式成立时，不等式取等号。

$$
\begin{cases}
    x - a_1 & \ge 0 \\
    & \vdots \\
    x - a_k & \ge 0 \\
    a_{k+1} - x & \ge 0 \\
    & \vdots \\
    a_{2k} - x & \ge 0
\end{cases}
\iff
\begin{cases}
    a_1 & \le x \\
    & \vdots \\
    a_k & \le x \\
    x & \le a_{k+1} \\
    & \vdots \\
    x & \le a_{2k}
\end{cases}
$$

$x$ 需要大于等于数组中一半的数且小于等于数组中另一半的数，也就是说 $x$ 可以取两个中位数之间的任意值。

当 $n = 2k + 1$ 为奇数时，有

$$
\begin{aligned}
    \sum_{i=1}^n |a_i - x|
    &= |x - a_1| + ... + |x - a_k| + |x - a_{k+1}| + |x - a_{k+2}|... + |x - a_{2k+1}| \\
    &= \cfrac{1}{2} (2|x - a_1| + ... + 2|x - a_k| + |a_{k+1} - x| + |x - a_{k+1}| + 2|a_{k+2} - x| ... + 2|a_{2k+1} - x| \\
    &= \cfrac{1}{2} (|2x - 2a_1| + ... + |2x - 2a_k| + |a_{k+1} - x| + |x - a_{k+1}| + |2a_{k+2} - 2x| ... + |2a_{2k+1} - 2x| \\
    &\ge \cfrac{1}{2}|2x - 2a_1 + ... + x - a_k + x - a_{k+1} + x + 2a_{k+1} - 2x + ... + 2a_{2k} - 2x| \\
    &= \cfrac{1}{2}|-2a_1 - ... - a_k + 0 + 2a_{k+2} + ... + a_{2k+1}|
\end{aligned}
$$

当如下等式成立时，不等式取等号。

$$
\begin{cases}
    x - a_1 & \ge 0 \\
    & \vdots \\
    x - a_k & \ge 0 \\
    a_{k+1} - x & \ge 0 \\
    x - a_{k+1} & \ge 0 \\
    x - a_{k+2} & \ge 0 \\
    & \vdots \\
    a_{2k+1} - x & \ge 0
\end{cases}
\iff
\begin{cases}
    a_1 & \le x \\
    & \vdots \\
    a_k & \le x \\
    x = a_{k+1} \\
    x & \le a_{k+2} \\
    & \vdots \\
    x & \le a_{2k+1}
\end{cases}
$$

$x$ 需要大于等于数组中一半的数且小于等于数组中另一半的数，并且 $x = a_{k+1}$。
若通过交换，使得 $a_{k+1}$ 为 $a$ 的中位数，上述条件均可成立，不等式取等号。

综上所属，$x$ 就是数组 $a$ 的中位数。

### Axis

从数轴的角度进行理解，这道题可以把数组的每一个元素看成一维数轴上的一点，而答案就是从数组上找一点 $x$，使得 $x$ 到各个点的距离和最小。

到两个点的距离之和最小的点肯定在这两个点形成的线段之间。

如果 $n = 2k$ 的话，那么 $x$ 在最中间两个点之间。

[](even-axis.drawio.svg)

如果 $n = 2k+1$ 的话，那么 $x$ 在最中间那个点。

### STL

[](stl.cpp ':include :type=code cpp')
