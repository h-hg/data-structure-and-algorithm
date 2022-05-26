# 快速幂

先来看一个问题吧

> 给定三个整数$a$、$b$、$m$($a < 10^9, b < 10^9, 1 < m < 10^9$)，求$a^b % m$

## 蛮力法

简单粗暴的方法，就是一个`for`循环了。

```cpp
int brutal_force(int a, int b, int m) {
  int product = 1;
  for(int i = 0; i < b; ++i)
    product *= a;
  return product % m;
}
```

上面的实现用一个`product`来储存幂很容易造成数据溢出，我们可以采用取模运算法则$(a \times b)\%p = (a\%p \times b\%p) \%p$来避免溢出，同时使用`long long`来存储两个整数相乘的结果来避免溢出。

```cpp
int Brutal_force(long long a, long long b, long long m) {
  long long ret = 1;
  for(long long i = 0; i < b; ++i) {
    ret = ret * a % m;
  }
  return ret;
}
```

## 二分法

蛮力法的时间复杂度为$\Theta(b)$，我们可以使用减治法（减去因子）的思想来降低复杂度，使其时间复杂度为$\Theta(\log b)$。

核心公式

$$
a^b = \begin{cases}
(a^{\frac{b}{2}})^2  &\text{if b is even} \\
(a^{\frac{b-1}{2}})^2 \times a & \text{if b is odd}
\end{cases}
$$

也就是说我们得到$a^b$的递推公式，我们`power`函数可以这样子写。

```cpp
long long power(long long a, long long b) {
  if(b == 0)
    return 1;
  else if(b & 1) {
    long long part = power(a, (b - 1) / 2);
    return part * part * a;
  } else {
    long long part = power(a, b / 2);
    return part * part;
  }
}
```

再配合取模运算，我们可以得到如下的公式

$$
a^b \% p= \begin{cases}
(a^{\frac{b}{2}})^2 \%p &\text{if b is even} \\
(a^{\frac{b-1}{2}})^2 \times a \%p & \text{if b is odd}
\end{cases}
$$

实现如下

```cpp
long long binary_method(long long a, long long b, long long m) {
  if(b == 0)
    return 1;
  else if(b & 1) {
    long long part = power(a, (b - 1) / 2);
    return part * part * a % m;
  } else {
    long long part = power(a, b / 2);
    return part * part % m;
  }
}
```

## 快速幂

快速幂，又称为二进制取幂（Binary Exponentiation，也称平方法），是一个在$\Theta(\log b)$的时间内计算$a^b$的小技巧。

从二进制的表示上看，任何一个数$b$都可以表示为$b_n...b_i...b_0$，即$b = \sum_{i=0}^{n}b_i 2 ^ i, b_i \in \{0, 1\}, i \in N, n = \lfloor \log_2 b \rfloor$。那么$a^b = a ^ {\sum_{i=0}^n b_i 2^i} = \prod_{i=0}^n a^{b_i 2^i}$。

例如$13_{10} = 1101_2 = 1 \times 2^3 + 1 \times 2^2 + 0 \times 2^1 + 1 \times 2^0 = 2^3 + 2^2 + 2^0$，$a^{13} = a^{2^3} \times a^{2^2} \times a^{2^0}$

由于$b_i \in \{0, 1\}$，那么$a^b = \prod_{i=0}^n a^{b_i 2^i} = \prod_{i=0}^n b_i a^{2^i}$。我们很容易发现$a^{2^{i+1}} = (a^{2^i})^2$，由此可以引出下面快速幂的计算方式。

我们将结果`ret`设置为1，我们从$a^{2^0}$（即$a$）开始，若$b_0$等于1，则将`ret`乘以$a^{2^0}$，否则跳过这一步乘法，接着我们将$a^{2^0}$平方得到$a^{2^1}$，再继续判断$b_1$是否为1，若为1，将`ret`乘以$a^{2^1}$，一直重复这种操作，直到$a^{2^n}$。

具体实现如下：在具体的实现中，我们通过判断$b$的最低位是否为1来判断是否将`ret`乘以$a^{2^i}$，再右移一位，使得最低位总是最新的一位。

```cpp
long long quick_power(long long a, long long b) {
  long long ret = 1;
  while(b > 0) {
    if(b & 1) {
      ret = ret * a;
    }
    a = a * a;
    b >>= 1;
  }
  return ret;
}
```

最后结合取模运算，我们便可写出问题的快速幂解法了。

```cpp
long long quick_power(long long a, long long b, long long m) {
  long long ret = 1;
  while(b > 0) {
    if(b & 1) {
      ret = ret * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return ret;
}
```

## 参考资料

- [OI wiki - quick power](https://oi-wiki.org/math/quick-pow/)