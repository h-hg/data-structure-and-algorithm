# Strassen 矩阵乘法

## 简介

与大整数乘法相似的，这也是一种基于分治思想的算法。它巧妙地构造了矩阵的分块，然后利用矩阵的分块乘法来降低复杂度。

## 原理

为了计算 $C = A \times B$，我们这三个矩阵先进行分块。假设 n 是 2 的乘方，$A$ 和 $B$ 是两个 $n \times n$ 的矩阵（如果 n 不是 2 的乘方，矩阵可以用为 0 的行或列来填充）。我们可以把 $A,B，C$ 分别划分为 4 个 $\frac{n}{2} \times \frac{n}{2}$ 的子矩阵。

$$
C =
\begin{bmatrix}
C_{00} & C_{01} \\
C_{10} & C_{11}
\end{bmatrix},
A =
\begin{bmatrix}
A_{00} & A_{01} \\
A_{10} & A_{11}
\end{bmatrix},
B =
\begin{bmatrix}
B_{00} & B_{01} \\
B_{10} & B_{11}
\end{bmatrix}
$$

令

$$
\begin{aligned}
M_1 &= (A_{00} + A_{01}) \times (B_{00} + B_{11}) \\
M_2 &= (A_{10} + A_{11}) \times B_{00} \\
M_3 &= A_{00} \times (B_{01} - B_{11}) \\
M_4 &= A_{11} \times (B_{10} - B_{00}) \\
M_5 &= (A_{00} + A_{01}) \times B_{11} \\
M_6 &= (A_{10} - A_{00}) \times (B_{00} + B_{11}) \\
M_7 &= (A_{01} - A_{11}) \times (B_{10} + B_{11})
\end{aligned}
$$

则

$$
C =
\begin{bmatrix}
C_{00} & C_{01} \\
C_{10} & C_{11}
\end{bmatrix}
=
\begin{bmatrix}
M_1 + M_4 - M_5 + M_7 & M_3 + M_5 \\
M_2 + M_4 & M_1 + M_3 - M_2 + M_6
\end{bmatrix}
$$

我们可以看到计算两个 $n \times n$ 的矩阵乘法，需要计算 7 次 $\frac{n}{2} \times \frac{n}{2}$ 矩阵的乘法和 18 次 $n \times n$ 的矩阵加减法。

设 $T_n$ 为 $n \times n$ 矩阵乘法的复杂度，则

$$
T_n =
\begin{cases}
7T_{\frac{n}{2}} + 18n & n \neq 1 \\
1 & n = 1
\end{cases}
$$
根据递推公式，我们容易得出 $T_n \in \Theta(n^{\log_2 7})$。

