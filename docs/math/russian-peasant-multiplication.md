# 俄式乘法

## 简介

俄式乘法（multiplicationala russe）又被称为俄国农夫法（Russian peasant method），它是一种基于减治法（减去常因数）的思想，它在计算机中的应用并不多，主要是方便人们在实际生活中计算两个数字相乘。

核心公式如下：

$$
n \times m = \begin{cases}
m &\text{n = 1} \\
\cfrac{n}{2} \times 2m  &\text{if n is even} \\
\cfrac{n-1}{2} \times 2m + m & \text{if n is odd}
\end{cases}
$$


通过上面公式，我们成功将两个数的乘法转化为乘以2、除以2和加法，这样就方便不会“大数乘法”的“农夫”了。

## 实现

```cpp
int russian_multi(int n, int m) {
  if(n == 1)
    return n;
  else if(n & 1) //odd
    return russian_multi((n - 1) / 2, m) + m;
  else //even
    return russian_multi(n / 2, m * 2) + m;
}
```

当然这种实现比计算机直接将两个数相乘慢得多。