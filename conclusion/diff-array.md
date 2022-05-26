# 差分数组

差分数组主要的应用场景是频繁对原始数组的某个区间的元素进行增减。

例如，给定数组 `nums`，要求给区间 `[m1, n1]` 增加 1，然后给区间 `[m2, n2]` 减去 1，然后不断进行类似的操作，让你输出最后的 `nums`。

常规思路的模拟，使用 `for` 进行模拟，这种思路的时间复杂度开销比较大。
可以使用差分数据来进行优化。

$$
diff =
\begin{cases}
    nums[i] & i = 0 \\
    nums[i] - nums[i - 1] & i > 0
\end{cases}
$$

从 `nums` 到 `diff` 的转化，可以使用 `std::adjacent_difference`，其定义于 `<numeric>`。

```cpp
#include <numeric>
vector<int> nums2diff(vector<int> &nums) {
  auto diff = nums;
  std::adjacent_difference(nums.begin(), nums.end(), diff.begin());
  return diff;
}
```

从 `diff` 到 `nums` 的转化

```cpp
vector<int> diff2nums(vector<int> &diff) {
  auto nums = diff;
  nums[0] = diff[0];
  for(int i = 0; i < diff.size(); ++i)
    nums[i] = nums[i - 1] + diff[i];
  return nums;
}
```

这样对区间 `[m1, n1]` 加 1，等价于 `diff[m1] += 1` 和 `diff[n1] -= 1`。

这样对区间 `[m1, n1]` 减 1，等价于 `diff[m1] -= 1` 和 `diff[n1] += 1`。

从本质上来看，差分数组就是在区间的两个端点进行标记（区间的进入，区间退出），用这两个标记来表示整段区间的某个操作。
