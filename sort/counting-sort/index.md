# 计数排序

## 简介

> 计数排序是一个非基于比较的排序算法，该算法于1954年由 Harold H. Seward 提出。它的优势在于在对一定范围内的整数排序时，它的复杂度为$\Theta(n+k)$（其中$k$是元素的取值范围），快于任何比较排序算法。当然这是一种牺牲空间换取时间的做法，而且当$\Theta(k)>\Theta(n*log(n))$的时候其效率反而不如基于比较的排序。

## 实现

上面的引用说了这么这么多还是没有说明具体怎么实现，简单的是我们算出各个元素的个数，然后将这些元素从小到大输出，即可得到我们需要的有序数列。

具体步骤如下：
1. 用$\Theta(n)$的时间遍历序列$a$，得出最小值`minVal`和最大值`maxVal`。
2. 申请`k = maxVal - minVal + 1`的空间`ret`用来存放元素的个数，例如`ret[i - minVal]`表示元素`i`的个数。
3. 用$\Theta(n)$的时间遍历序列$k$，完成序列$k$的初始化
4. 用$\Theta(k)$的时间遍历序列$k$，获得有序的输出序列

```cpp
#include <algorithm>
#include <vector>
using namespace std;

vector<int> counting_sort(vector<int> const &a) {
  //find the minVal and maxVal
  auto p = minmax_element(a.begin(), a.end());
  auto minVal = *p.first, maxVal = *p.second, k = maxVal - minVal + 1;
  //count
  vector<int> val2cnt(k, 0);
  for(int i = 0; i < a.size(); ++i)
    ++val2cnt[a[i] - minVal];
  //output
  vector<int> ret;
  ret.reserve(a.size());
  for(int i = 0; i < k; ++i)
    for(int j = 0; j < val2cnt[i]; ++j)
      ret.push_back(i + minVal);
  return ret;
}
```