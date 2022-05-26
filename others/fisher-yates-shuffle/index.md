# 洗牌算法

讲的大概就是如何给一组长度有限的序列打乱，并使得每个元素在每个位置上出现的概率是一样的。

方法描述：长度为 n 序列（索引从 0 开始）。

1. 产生[0, n) 之间的随机数字k
2. 将索引为 k 的元素拿出并放在新序列的末尾，并将 n 减 1
3. 如果 n = 1，直接将序列元素拿出并放在新序列的末尾，否则跳转到步骤 1

解释为什么每个元素在每个位置上出现的概率是一样的。
从高中组合排列的角度思考问题，将元素拿出并放在新序列的末尾这个操作，如果将新序列末尾看成是人的动作，元素看成签，该操作就是人抽签的问题了，我们很容易知道先抽后抽，得奖（获得某个元素）的概率都是一样的，这就说明了每个元素在每个位置上出现的概率是一样的。

空间上的小优化。
步骤 2 中，需要一个新的序列，我们可以将“将索引为 k 的元素拿出并放在新序列的末尾”改成将“索引 k 的元素与 索引 n-1 的元素进行交换”，这样就节省了空间。

实现。

```cpp
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
static auto _ = []() {
  srand(time(0));
};

// return random number in [minVal, maxVal]
int random(int minVal, int maxVal) {
  return rand() % (maxVal - minVal + 1) + minVal;
}

//range [begin, end)
template <typename RAIter>
void shuffle(RAIter begin, RAIter end) {
  for(--end; end != begin; --end) {
    int k = random(0, end - begin);
    swap(*(begin + k), *end);
  }
}
```

参考资料

- [wiki Fisher–Yates shuffle](https://en.wikipedia.org/wiki/Fisher–Yates_shuffle)