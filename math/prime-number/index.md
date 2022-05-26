# 素数问题

这是一篇关于素数如何利用数学知识进行求解的详细介绍，若存在错误，还请指出。

## 如何判断一个数是否为素数

### 暴力方法

判断一个数n是否为素数，只需在(1,n)看是否存在它的因子
```cpp
bool IsPrime(int n) {
  if(n < 2)
    return false;
  else if(n == 2)
    return true;
  else{
    for(int i = 2;i < n;++i)
      if(n % i == 0)
        return false;
    return true;
  }
}
```

### 优化版1
**定理**：如果n是合数，在$(1,\sqrt{n}]$必定存在它的因子
证明：设$n=ab$
假设a,b都小于$\sqrt{n}$，那么$ab<\sqrt{n}\sqrt{n}=n$，矛盾
假设a,b都大于$\sqrt{n}$，那么$ab>\sqrt{n}\sqrt{n}=n$，矛盾

因此我们可以得知，只需在$(1,\sqrt{n}]$中看是否存在它的因子即可，再者可先判断n是否为偶数（2除外），不是偶数的话，只需在$(1,\sqrt{n}]$中的奇数看是否存在它的因子即可
```cpp
bool IsPrime(int n) {
  if(n < 2)
    return false;
  else if(n == 2)
    return true;
  else if(!(n&1))//n是偶数
    return false;
  else {
    int num = sqrt(n);
    for(int i = 3;i <= num;i += 2)
      if(n % i == 0)
        return false;
    return true;
  }
}
```

### 优化版2
**定理**：任何一个合数=若干个素数的积
证明：
合数的因子只有素数，那么定理成立，如果因子有合数，合数又可以分解，不断分解，最终分解出素数，由于素数是分解出的，所以肯定可以整除最初的合数

这样的话，我们只需在$(1,\sqrt{n})$中的素数看是否存在它的因子即可，表明如果知道$(1,\sqrt{n}]$所有质数,判断n是否为质数将变得很快

假设primes[i]是递增的素数序列: 2, 3, 5, 7, ...,更准确地说primes[i]序列包含$(1,\sqrt{n}]$范围内的所有素数
```cpp
bool IsPrime(vecter<int> primes, int n) {
  if(n < 2)
    return false;
  const int limit = sqrt(n);
  for(int i = 0;primes[i] <= limit;++i)
      if(n%primes[i] == 0)
      return false;
  return true;
}
```
**这样的话，我们只需找出$(1,\sqrt{n}]$所有素数**
## 构造素数列
### 原始方法
我们在构造的时候完全可以利用已经被构造的素数序列，假设我们已经得到素数序列: $p_1, p_2, .. p_n$
现在要判断$p_{n+1}$是否是素数, 则需要$(1, \sqrt{p_{n+1}}]$范围内的所有素数序列,$p_{n+1}$为素数,$p_{n+1} \% p_i == 0,(pi < \sqrt{p_{n+1}})$

**不超过maxn的所有质数**

```cpp
vector<int> Makeprimes(const int maxn) {
  if(maxn < 2)
    return vector<int>();
  else if(maxn == 2)
    return vector<int>{2};
  else if(maxn < 5)
        return vector<int>{2,3};
  //下面作为已知的素数列
  vector<int> primes = {2,3};
  for(int current = 5;current < maxn;++current) {
    bool flag = true;
    int n = sqrt(current);
    for(int i = 0;primes[i] <= n;++i)
      if(current % primes[i] == 0) {
        flag = false;
        break;
      }
    if(flag)
      primes.push_back(current);
  }
  return primes;
}
```

### sieve of Eratosthenes(埃拉托斯特尼筛法)
#### 简介
给出要筛数值的范围max，找出max以内的素数$p_1,p_2,p_3,..,p_k$。
具体做法是：
* 列出2以后的所有序列：
    2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 ...
* 标出序列中的第一个质数，也就是2(加粗)，序列变成：
    **2** 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 ...
* 将剩下序列中，划掉2的倍数，序列变成：
     3 5 7 9 11 13 15 17 19 21 23 25 ...
* 如果现在最大的素数$>\sqrt{max}$，那么剩下的序列中所有的数都是质数，否则用下一个素数，也就是3筛，把3留下，把3的倍数剔除掉。再判断，再循环...

**原理**:保证每次得到的素数不会是前面数的倍数，也就是它的因子只有1和它本身

**步骤解疑**
* 为什么要判断最大素数>$\sqrt{max}$
    因为如果数字i > $\sqrt{max}$且i是合数,则在$[2,\sqrt{i}]$必有它的因子，它的因子会将i标记，而i的最大值是max，所以判断最大素数>$\sqrt{max}$，这样会加快筛选
* 为什么不将合数的倍数标记
    因为合数的倍数也是它的因子的倍数，它的因子肯定有素数，在前面已经将倍数标记了

#### 代码
```cpp
vector<int> Makeprimes(const int maxn) {
  if(maxn < 2)
    return vector<int>();
    vector<bool> flags(maxn+1, true);

  flags[0] = flags[1] = false;
  flags[2] = true;
  const int limits = sqrt(maxn);
  for(int i = 2;i <= limits;i++)
    if(flags[i])
      for(int j = i + i;j <= maxn;j += i)
        flags[j] = false;
    vector<int> primes;
  for(int i = 2;i <= maxn;i++)
    if(flags[i])
      primes.push_back(i);
  return primes;
}
```

### Eratosthenes改进

将上面`从最大素数后面开始划掉素数的倍数`改成`从最大素数的平方后面开始划掉素数的倍数`，也就是`int j = i + i`改成`int j = i×i`

假设i是目前已知的最大素数，那么[2,i * i]之间的合数的因子必定在[2,i]之间，故已经被i前面的质数标记了，所以无需划掉
```cpp
vector<int> Makeprimes(const int maxn) {
  if(maxn < 2)
    return vector<int>();
    vector<bool> flags(maxn+1, true);
  flags[0] = flags[1] = false;
  flags[2] = true;
  const int limits = sqrt(maxn);
  for(int i = 2;i <= limits;i++)
    if(flags[i])
      for(int j = i * i;j <= maxn;j += i)
        flags[j] = false;
    vector<int> primes;
  for(int i = 2;i <= maxn;i++)
    if(flags[i])
      primes.push_back(i);
  return primes;
}
```
### Sieve of Euler(欧拉筛法)
#### 简介
欧拉筛法（Sieve of Euler）是埃拉托斯特尼筛法的一种改进。有人称其为快速线性筛法。回顾经典的埃拉托斯特尼筛法，它可能对同一个素数筛去多次，故时间复杂度为O(n log logn)。如果用某种方法使得每个合数只被筛去一次就变成是线性的了。不妨规定每个合数只用其最小的一个质因数去筛，这便是欧拉筛了，时间复杂度 O(n).
#### 代码
```cpp
vector<int> Makeprimes(const int maxn) {
  vector<int> primes;
  if(maxn < 2)
    return primes;
  vector<bool> flags(maxn+1, true);
  for(int i = 2;i < maxn;++i) {
    if(flags[i])
      primes.push_back(i);
      for(int j = 0;j < primes.size() && i*primes[j] < maxn;++j) {
        flags[i*primes[j]] = false;
        if(!(i % primes[j]))//if(i%primes[j]==0)
            break;
      }
    }
  return primes;
}
```
#### 代码解读与证明
每个合数n都可以化成这样的形式：$n=a_1^{k_1}a_2^{k_2}...a_n^{k_n}$其中$a_1,a_2,..,a_n$是素数，且$a_1<a_2<..<a_n$。而欧拉筛选正是利用合数最小的素数因子去划掉它本身。
证明需要从两方面去证，1.每个合数都会被划掉（正确性）；2.每个合数只会被划掉一次，也就是达到O(n)（复杂度）。
```cpp
for(int j = 0;j < primes.size() && i*primes[j] < maxn;++j) {
  flags[i*primes[j]] = false;
  if(!(i % primes[j]))//if(i%primes[j]==0)
      break;
}
```
在代码中，对于每个属于(1,n]的数i，都会划掉它×小于等于它本身的素数，保证了正确性。
1. 如果i本身是素数，那么数n=i×primes[j]只有这种分解形式，且primes[j]≤i（先只看<，不看=），那么这用这种划法是唯一的（不重复）。
2. 如果i本身是合数，先看i不是primes[j]倍数的时候，那么它的所有素数(primes[j])倍数都会被划掉，而这些素数恰好是这些数n=i×primes[j]的最小因子。
3. `if(i%prime[j]==0)break;`这行代码神奇地保证了每个合数只会被它的最小素因子筛掉，就把复杂度降到了O(N)。这代码让合数n=i×Prime[j+1]以及后面i×primes\[j+k](其中k是正整数)不被划掉。
由`i%primes[j]==0`，可设n=i×primes[j+1]=t×primes[j]×primes\[j+1](其中t为正整数)，可知n会被当i=t×primes[j+1]被前面primes[j]划掉了,后面的数同理。
4. `flags[i*primes[j]] = false;if(i % primes[j] == 0)break;`不可颠倒。假设$n=a_1^{k_1}a_2^{k_2}...a_n^{k_n},k_1>1$，根据上面说明，n是由$a_1^{k_1-1}a_2^{k_2}...a_n^{k_n}$划掉，颠倒后，直接break，无法划掉，同样$a_1^{k_1-1}a_2^{k_2}...a_n^{k_n}$无法被$a_1^{k_1-12}a_2^{k_2}...a_n^{k_n}$划掉……这样就导致$a_1a_2^{k_2}...a_n^{k_n}$的所有倍数无法划掉。归纳来说就是合数的最小素数的幂次>1的数都被当作素数。

#### 缺陷
虽然欧拉筛法的复杂度为O(n)，但里面的`modulo`操作却会花费较多的时间。