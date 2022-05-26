# 最大公约数

这是一篇关于最大公约数如何利用数学知识进行求解的详细介绍，若证明存在错误，还请指出。

## 暴力求解法
```cpp
int gcd(int x,int y) {
  if(!x)
    return y;
  if(!y)
    return x;
  int result = x > y ? y : x;
  while(x%result != 0 || y%result != 0)
    --result;
  return result;
}
```

## 辗转相除法

### 简介

又称欧几里得算法(Euclid's Algorithm)

### 公式

$$
gcd(x,y)=
\begin{cases}
x& y=0 \\
gcd(y,x \% y)& y>0
\end{cases}
$$

### 证明

**符号说明**
> $gcd(x,y)$：x和y的最大公约数
> $cd(x,y)$：x和y所有公约数的集合
> $d(x)$：x所有公约数的集合

下面，我们证明$gcd(x,y) = gcd(y,x\% y)$
1. 当$x=y$时，$lhs= y = gcd(y,0) =rhs$
2. 当$x<y$时，$lhs= gcd(x,y) = gcd(y,x) =rhs$
3. 当$x>y$时，不妨设$x = ky + r(k,r\in N^+)$，则$r=x\%y$
  * $\forall t\in cd(x,y)$，设$m=\frac{x-ky}{t}=\frac{x}{t}-k\frac{y}{t}$，易得$m\in N^+$。由$m=\frac{x-ky}{t}=\frac{r}{t}$，可知$t\in d(r)$，又$t\in d(y)$，所以$t\in cd(y,r) = cd(y,x\%y)$，所以$cd(x,y) \subseteq cd(y,x\%y)$
  * $\forall t \in cd(y,x\%y)$，设$m=\frac{ky+r}{t}=k\frac{y}{t}+\frac{r}{t}=k\frac{y}{t}+\frac{x\%y}{t}$，易得$m\in N^+$。由$m = \frac{ky+r}{t}=\frac{x}{t}$可知$t \in d(x)$。又$t \in d(y)$，所以$t \in cd(x,y)$，所以$cd(y,x\%y) \subseteq cd(x,y)$
  * 综上，$cd(x,y) = cd(y,x\%y)$，故$gcd(x,y) = gcd(y,x\%y)$

**第三步的另一种证法**

设$t=gcd(x,y),x=mt,y=nt$，则$r=x-ky=mt-knt=(m-kn)t$，故$t \in c(r)$

下证$m-kn$与$n$互质

反证法：若$m-kn$与$n$不互质，则存在因子$w$，使得$m-kn=aw,n=bw$，由$\begin{cases}x=mt=(aw+kn)t=(aw+kbw)t=(a+kb)tw\\y=nt=bwt\end{cases}$得$gcd(x,y)=tw$，矛盾

又$\begin{cases}r=(m-kn)t\\y=nt\end{cases}$，故$t=gcd(y,r)$
综上$gcd(x,y) = gcd(y,r) = gcd(y,x\%y)$

### c++代码

#### 递归版

```cpp
int Euclid(int x,int y) {
  if(y)
    return Euclid(y,x % y);
  else
    return x;
}
```

#### 非递归版

通过上面的式子和证明可以知道，$gcd(x,y)$不断保证$x>=y$

```cpp
int gcd(int x,int y) {
  int r;
  if(x < y) {
    //swap x y
    r = x;
    x = y;
    y = r;
  }
  do {
    r = x % y;
    x = y;
    y = r;
  }while(r);
  return x;
}
```

### 缺陷

>欧几里德算法是计算两个数最大公约数的传统算法，无论从理论还是从实际效率上都是很好的。但是却有一个致命的缺陷，这个缺陷在素数比较小的时候一般是感觉不到的，只有在大素数时才会显现出来。
>一般实际应用中的整数很少会超过64位（当然现在已经允许128位了），对于这样的整数，计算两个数之间的模是很简单的。对于字长为32位的平台，计算两个不超过32位的整数的模，只需要一个指令周期，而计算64位以下的整数模，也不过几个周期而已。但是对于更大的素数，这样的计算过程就不得不由用户来设计，为了计算两个超过64位的整数的模，用户也许不得不采用类似于多位数除法手算过程中的试商法，这个过程不但复杂，而且消耗了很多CPU时间。对于现代密码算法，要求计算128位以上的素数的情况比比皆是，设计这样的程序迫切希望能够抛弃除法和取模。

## 更相减损术

### 简介

来源于《九章算术》

>可半者半之，不可半者，副置分母、子之数，以少减多，更相减损，求其等也。以等数约之。

**白话文**
第一步：任意给定两个正整数；判断它们是否都是偶数。若是，则用2约简；若不是则执行第二步。
第二步：以较大的数减较小的数，接着把所得的差与较小的数比较，并以大数减小数。继续这个操作，直到所得的减数和差相等为止。
则第一步中约掉的若干个2与第二步中等数的乘积就是所求的最大公约数。
其中所说的“等数”，就是最大公约数。求“等数”的办法是“更相减损”法。

### 公式

**不考虑第一步，即x,y不都为偶数**

$$
gcd(x,y)=
\begin{cases}
x& x = y \\
gcd(y,x - y)& x > y \\
gcd(y,x)& x < y
\end{cases}
$$

### 证明

假设$x > y$

#### 方法1
$\forall t\in cd(x,y)$，设$h = x - y$，两边$\div t$,得$\frac{h}{t}=\frac{x}{t}-k\frac{y}{t} = m$，易得$m\in N^+$，所以$t\in c(x-y)$，又$t\in c(y)$，所以$t\in cd(y,x-y)$,所以$cd(x,y) \subseteq cd(y,x-y)$

$\forall t \in cd(y,x-y)$，对$x = y + h$，两边÷t,得$\frac{x}{t}=k\frac{y}{t}+k\frac{h}{t} = m$，易得$m\in N^+$，所以$t \in c(x)$，又$t \in c(y)$，所以$t \in cd(x,y)$,所以$cd(y,x-y) \subseteq cd(x,y)$

综上，$cd(x,y) = cd(y,x-y)$，故$gcd(x,y) = gcd(y,x\%y)$

#### 方法2
设$t=gcd(x,y),x=mt,y=nt$，则$r=x-y=mt-nt=(m-n)t$，故$t \in c(x-y)$

下证$m-n \text{与} n \text{互质}$
反证法：
若$m-n \text{与} n \text{不互质}$，则存在因子w，使得$m-n=aw,n=bw$，由$\begin{cases}x=mt=(aw+n)t=(aw+bw)t=(a+b)tw\\y=nt=bwt\end{cases}$得$gcd(x,y)=tw$，矛盾
又$\begin{cases}x-y=(m-n)t\\y=nt\end{cases}$，故$t=gcd(y,r)$

综上$gcd(x,y) = gcd(y,x-y)$

### c++代码

```cpp
int gcd(int x, int b) {
    int times = 0;
    while(!(x&1) && !(y&1))
    {
        ++times;
        x >>= 1;
        y >>= 1;
    }
    while(x != y)
        if(x > y)
            x -= y;
        else
            y -= x;
    return x<<times;
}
```
### 缺陷
>更相减损术和辗转相除法的主要区别在于前者所使用的运算是“减”，后者是“除”。从算法思想上看，两者并没有本质上的区别，但是在计算过程中，如果遇到一个数很大，另一个数比较小的情况，可能要进行很多次减法才能达到一次除法的效果，从而使得算法的时间复杂度退化为O(N)，其中N是原先的两个数中较大的一个。相比之下，辗转相除法的时间复杂度稳定于O(logN)
## Stein算法
### 简介
与更相减损术相似，差别在于:
在更相减损法中，若两个是偶数则同除以2，结果乘以2。如果增加一个判断，若为一奇一偶则偶数除以2，结果不变，若为两个奇数才相减，这样就变成了目前计算大整数最大公约数的非常好的一个算法。
### 证明
若能证明当$k$与$b$互为质数，$gcd(kx,y)=gcd(x,y)$，便可推出一般情况，即当$k=2$时，计算一个偶数和一个奇数的最大公约数时，可以先将偶数除以2。
设$t=gcd(x,y),kx=mt,y=nt,x=\frac{mt}{k}$
下证$\frac{m}{k}$与$n$互质
反证法：设$\frac{m}{k}=pw,n=qw$，由$\begin{cases}kx=kpwt\\y=qwt\end{cases}$，得$gcd(x,y)=wt$，矛盾
由$\begin{cases}x=\frac{m}{k}t\\y=nt\end{cases}$，得$t=gcd(x,y)$
所以$gcd(kx,y)=gcd(x,y)$

### 代码实现
```cpp
int gcd(int x, int y)
{
    if(!x)
        return y;
    if(!y)
        return x;
    int times = 0;
    while(!(x&1) && !(y&1))
    {
        ++times;
        x >>= 1;
        y >>= 1;
    }
    while(!(x&1))
        x >>= 1;
    while(!(y&1))
        y >>= 1;
    while(x != y)
    {
        if(x > y)
            x -= y;
        else
            y -= x;
    }
    return x<<times;
}
```
优化版：优化的根据，两个奇数的差又是偶数，可以再除以2
```cpp
void divide2(int &n)
{
    while(!(n&1))
        n >>= 1;
}
int gcd(int x, int y)
{
    if(!x)
        return y;
    if(!y)
        return x;
    int times = 0;
    while(!(x&1) && !(y&1))
    {
        ++times;
        x >>= 1;
        y >>= 1;
    }
    divide2(x);
    divide2(y);
    while(x != y)
        if(x > y)
        {
            x -= y;
            divide2(x);
        }
        else
        {
            y -= x;
            divide2(y);
        }
    return x<<times;
}
```