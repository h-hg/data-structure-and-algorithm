# 秦九韶公式

在国外叫做霍內演算法(Horner’s Rule)，是一种一种多项式简化的算法。

核心公式：

$$
P(x)=a_nx^n+a_{n−1}x^{n−1}+...+a_1x+a_0=(...(a_nx+a_{n−1})x+a_{n−2})x...)x+a_0
$$

例如

$$
\begin{aligned}
3x^4 + 2x^3 + 4x + 1 &= 3x^4 + 2x^3 + 0x^2 + 4x +1 \\
&= (((3x + 2)x + 0)x + 4)x + 1
\end{aligned}
$$

代码说明：`a`表示系数组成的数列，`a[n]`表示$a_n$

```cpp
int P(int *a,int n,int x) {
  int result = a[n];
  for(int i = n - 1;i >= 0;--i)
    result = reusult * x + a[i];
  return reuslt;
}
```
