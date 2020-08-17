# 大整数乘法优化

## 简介

如果使用经典的算法（手动模拟）来计算两个 n 位大整数惊醒乘法运算的话，第一个数中的 n 个数字都要被第二个数中的 n 个数字相乘，这样一共就要 $n^2$ 次位乘。

下面介绍一种基于分治法的大整数乘法，它使得两个 n 位数的乘法的时间复杂度为 $\Theta(n ^ {\log_2 3})$。

## 原理

为了展示该算法的基本思想，我们先看看整数表示。

为了方便，我们假设我们进制系统为十进制。一个 n 位整数 $a$，低 $\frac{n}{2}$ 位的值为$a_0$，高 $\frac{n}{2}$ 的值为 $a_1$，即 $a = a_1 a_0 = a_1 \times 10^{\frac{n}{2}} + a_0$。例如 $n = 2, a = 58$，那么 $a_1 = 5, a_0 = 8, a = 5 \times 10^1 + 8$。同样的，另一个 n 位整数 $b = b_1 b_0 = b_1 \times 10^{\frac{n}{2}} + b_0$。那么

$$
\begin{aligned}
a \times b &= (a_1 \times 10^{\frac{n}{2}} + a_0) \times (b_1 \times 10^{\frac{n}{2}} + b_0) \\
&= (a_1 \times b_1) \times 10^n + (a_1 \times b_0 + a_0 \times b_1) \times 10^{\frac{n}{2}} + (a_0 \times b_0) \\
&= (a_1 \times b_1) \times 10^n + \left[ (a_1 + a_0) \times (b_0 + b_1) - (a_1 \times b_1 + a_0 \times b_0) \right] \times 10^{\frac{n}{2}} + (a_0 \times b_0) \\
\end{aligned}
$$

令 $c_2 = a_1 \times b_1, c_0 = a_0 \times b_0, c_1 = (a_1 + a_0) \times (b_0 + b_1) - (a_1 \times b_1 + a_0 \times b_0) = (a_1 + a_0) \times (b_0 + b_1) - (c_2 + c_0)$，则 $a \times b = c2 \times 10^n + c_1 \times 10^{\frac{n}{2}} + c_0$。

从 $c_i$ 中计算中，我们可以发现，两个 n 位数相乘只需要 3 次 $\frac{n}{2}$ 相乘和 4 次 n 位数加法和 1 次 n 位数减法。

如果设 $T_n$ 为两个 n 位数字相乘的复杂度的话，不考虑加减法产生的复杂度（加减法复杂度小于乘法）的话，则有 

$$
T_n = 
\begin{cases}
3 T_{\frac{n}{2}} & n \neq 1\\
1 & n = 1
\end{cases}
$$

通过递归公式可以得出 $T_n = 3^{\log_2 n} = n^{\log_2 3}$。

## 参考资料

- Anany Levitin - *Introduction to the Design and Analysis 3rd*