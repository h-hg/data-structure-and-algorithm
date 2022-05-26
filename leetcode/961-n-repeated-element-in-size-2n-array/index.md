# N-Repeated Element in Size 2N Array

- [Leetcode](https://leetcode.com/problems/n-repeated-element-in-size-2n-array)
- [力扣中国](https://leetcode.cn/problems/n-repeated-element-in-size-2n-array)

## Problem

[](desc.md ':include')

## Solution

### Hash

Hash 法，这个不多介绍了。

### Mathematical Analysis

我们可以考虑重复的元素 $x$ 在数组 `nums` 中出现的位置。

如果相邻的 $x$ 之间至少都隔了 222 个位置，那么数组的总长度至少为：

$$
n + 2(n − 1) = 3n − 2
$$

当 $n > 2$ 时，$3n − 2 > 2n$，不存在满足要求的数组。
因此一定存在两个相邻的 $x$，它们的位置是连续的，或者只隔了 1 个位置。

当 $n = 2$ 时，数组的长度最多为 $2n = 4$，因此最多只能隔 2 个位置。

这样一来，我们只需要遍历所有间隔 2 个位置及以内的下标对，判断对应的元素是否相等即可。
其实 $n = 2$ 可以看作一种特例，例如 `1 2 3 1`，对于这种需要间隔 2 两个位置的可以判断相隔 1 个位置是否有元素元素相同，没有的话，直接返回第一个元素。

[](math.cpp ':include :type=code cpp')

### Random

猴子排序的思路。
随机选出两个元素，判断这两个元素是否相同，相同的话，则得到答案。
两个元素相同的概率为 $\frac{n}{2n} \times \frac{n-1}{2n} \approx \frac{1}{4}$，所以最多进行四次。

[](random.cpp ':include :type=code cpp')
