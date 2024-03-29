# 归并排序

归并排序可以理解为“分块排序 + 合并”两个操作。

归并排序有一个特点，就是可以知道一个元素 `nums[i]` 后面有多少个元素比 `nums[i]` 小的。

例如 `nums` 如下

```text
? ? ? i ? ? ? ? j ? ? ?
```

如果 `nums[i] < nums[j]` 的话，在某个合并调用中，`i` 和 `j` 会处于两个不同的块（一前一后）。
此时 `nums[i]` 会跟 `nums[j]` 比较大小，使得 `nums[i]` 会比 `nums[j]` 先放入数组。

是否可以理解为 `nums[i]` 大于 `nums[j]`，那么 `nums[i]` 会跟 `nums[j]` 进行比较。
那这样的话，跟我一开始写的插入排序有什么区别，不是比较的次数是一样的。

这种理解是错的，例如

```text
7 8 1 2
```

就不会发生 `8` 跟 `2` 比较。

