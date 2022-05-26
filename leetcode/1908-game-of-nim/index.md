# Car Pooling

- [Leetcode](https://leetcode.com/problems/car-pooling)
- [力扣中国](https://leetcode.cn/problems/car-pooling)

## Problem

[](desc.md ':include')

## Solution

### Dynamic Programming

直接暴力动态规划

[](dp-force.cpp ':include :type=code cpp')

注意点：

- `dp` 加入一个初始状态，也就是所有石头堆的石头都是 $0$，那么 Alice 肯定是输。
- 两层 `for` 用来寻找是**否存**在 `Alice` 赢的情况。

考虑到 `piles.size()` 和 `piles[i]` 的值都比较小，所以可以给状态编码。

- 由于 `1 <= piles[i] <= 7`，所以可以使用 $3$ 个二进制位（$7 \le 2^3$）来表示一堆石头
- 由于 `1 <= piles.size() <= 7`，最多需要 $7 \times 3 = 21 < 31$ 个二进制位，可以使用一个 `int` 来表示。

[](dp-code.cpp ':include :type=code cpp')

### Game Stategy

[](solution.cpp ':include :type=code cpp')
