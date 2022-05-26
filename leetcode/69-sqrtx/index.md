# Sqrt(x)

- [Leetcode](https://leetcode.com/problems/sqrtx)
- [力扣中国](https://leetcode.cn/problems/sqrtx)

## Problem

[](desc.md ':include')

## Solution

### Binary Search

二分查找法

[](binary-search.cpp ':include :type=code cpp')

### Newton's method

为了避免符号造成误解，把输入用 `c` 表示，即求 $\sqrt{c}$。

可以看作求 $f(x) = x^2 - c$ 的零点。

牛顿迭代法的原理如下：

由泰勒展开，近似可得 $f(x_{n+1}) \approx f(x_n) + f'(x_n)(x_{n+1} - x_n)$

令 $f(x_{n+1}) = 0$，即有 $x_{n+1} = x_n - f(x_n) / f'(x_n)$

代入 $f(x) = x^2 - a$，即可得到如下的迭代公式

$$
x_{n+1} = \frac{1}{2}(x_n + \frac{c}{x_n})
$$

从 $x_0 = c$ 开始迭代，当 $|x_{n+1} - x_{n}| < 10^{-7}$ 时停止迭代。
由于是从 $x_0 = c > \sqrt{c}$ 开始迭代，且 $f(x) = x^2 - c$ 单调递增，所以在迭代过程中，总满足 $x_{n+1} < x_n$（ $x_{n+1}$ 往负轴前进）。

[](newton-float.cpp ':include :type=code cpp')

由于 $x_{n+1} < x_{n}$，并且 $x_0 = c$，我们从另个一个角度出发，也就是一开始得到的 $x_{n+1}$ 总是满足 $x_{n+1} * x_{n+1} > c$。
并且答案要求的是 $\lfloor \sqrt{c} \rfloor$，所以可以将终止条件改为 $x_{n+1} * x_{n+1} - c > 0$。
基于上面的分析，可以使用 `long long` （防止 $x_{n+1} * x_{n+1}$ 溢出）来代替 `double`。

[](newton-int.cpp ':include :type=code cpp')
