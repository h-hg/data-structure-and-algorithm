# 二分搜索

## 简介

二分查找也称为折半查找，其时间复杂度为$\Theta(\log n)$，它要求数据满足：
1. 元素有序排列
2. 元素可随机访问

其大致模板是
```cpp
int binarySearch(vector<int> &nums, int target) {
  int l = 0, r = /* ... */;
  while( /* condition */) {
    int mid = l +  (r - l) / 2;
    if(nums[mid] < target) {
      /* ... */
    } else if(nums[mid] == target) {
      l = /* ... */;
    } else if(nums[mid] > target) {
      r = /* ... */;
    }
  }
  return /* ... */;
}
```

代码说明：
1. 注释部分是我们需要填充的代码
2. 为了避免整数溢出，使用`mid = l + (r - l) / 2`，而不是`mid = (l + r) / 2`
3. 为了判断条件更为明显，最后一个分支使用`else if`，而不是`else`

为了简化说明，我们默认元素都是升序排列。

## 指定值搜素

题目描述：给顶指定值，在升序数组中查找该值的位置，若不存在则返回-1

如果看过其他祥光的教程的话，我们可以不假思索地写下如下代码

```cpp
int binarySearch(vector<int> &nums, int target) {
  int l = 0, r = nums.size() - 1;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    if(nums[mid] < target) {
      l = mid + 1;
    } else if(nums[mid] == target) {
      return mid;
    } else if(nums[mid] > target) {
      r = mid - 1;
    }
  }
  return -1;
}
```

几个注意点：
1. `r = nums.size() - 1`
2. 为什么是`while(l <= r)`
3. 如何设置`l`和`r`的更新

为了解决这几个注意点，我们从二分查找的思想出发，二分查找本质上就是将搜索区间在排除已搜索过的值后将其划分为两个区间。

在上面代码中`r = nums.size() - 1`，可以知道我们的搜索区间是$[l, r]$，所以当搜索区间为空的时候，也就是`l = r + 1`，也就是我们上面`while(l <= r)`刚好不成立的时候。我们将搜索区间$[l, r]$划分为$[l, mid - 1]$和$[mid + 1, r]，$当`mid < target`的时候，说明我们要查找的值在`mid`的左边，也就是$[l, mid - 1]$，反之，我们的搜索区间就是$[mid + 1, r]$。

那我可以不可以将初始搜索空间设置$[0, nums.size())$，这当然是可以，但是需要变更一些代码，变更后的代码如下

```cpp
int binarySearch(vector<int> &nums, int target) {
  int l = 0, r = nums.size(); // attention
  while(l < r) {
    int mid = l + (r - l) / 2;
    if(nums[mid] < target) { // attention
      l = mid + 1;
    } else if(nums[mid] == target) {
      return mid;
    } else if(nums[mid] > target) {
      r = mid; // attemtion
    }
  }
  return -1;
}
```

代码说明：
1. `while(l < r)`：由于我们的搜索区间是$[l, r)$，当搜索区间为空的时候，也就是`l == r`，即`while(l < r)`刚好不成立的时候
2. `l = mid + 1`和`r = mid`：正如我们在上面说到的，二分查找本质上是将搜索区间划分为两个，我们将$[l, r)$划分为$[l, mid)$和$[mid + 1, r)$。在`nums[mid] > target`说明要搜索的值在`mid`右边，所以我们将`l`更新为`mid`

## 左边界搜索

我们似乎将说完了二分查找，其实为之过早。上面的指定值查找的数组元素都是唯一的，那么如果要查找的元素的个数有多个呢？我们先看看下面的问题。

给定一个含有重复元素的升序数组以及一个元素，你如何找到该元素第一次出现的位置，例如`array = {0, 0, 1, 2, 2, 2, 2, 3, 4}`和`target = 2`，正确答案便是`3`。

为了方便说明这个问题是如何实现，我们将问题改为如下：

给定一个含有重复元素的升序数组以及一个元素，找到第一个元素小于或等于该元素的位置。例如`array = {0, 0, 1, 2, 2, 2, 2, 3, 4}`和`target = 2`，正确答案便是`3`，`3`位置上的元素是`2`，是第一个小于或等于`target`的位置。例如我将


```cpp
int binarySearchLeft(vector<int> &nums, int target) {
  int l = 0, r = nums.size() - 1;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    if(nums[mid] < target) {
      l = mid + 1;
    } else if(nums[mid] == target) {
      r = mid - 1; // attention
    } else if(nums[mid] > target ) {
      r = mid - 1;
    }
  }
  return l >= nums.size() || nums[l] != target ? -1 : l; //attention
}
```

我们将搜索区间$[l, r]$分成为$[l, mid - 1]$和$[mid + 1, r]$

代码说明

1. `nums[mid] == target`后的`r = mid -1`：因为我们要查找左边界，在我们找到`target`后，我们还要确定`mid`左边是否还有`target`，所以我们将`r`更新为`mid - 1`，搜索区间$[l, mid - 1]$
2. `l >= nums.size() || nums[l] != target ? -1 : l`：

将搜索区间设置为$[l, r)$，代码如下

```cpp
int left_bound(vector<int> &nums, int target) {
  if (nums.size() == 0)
    return -1;
  int l = 0, r = nums.size(); // attention
  while (l < r) { // attention
    int mid = (l + r) / 2;
    if (nums[mid] < target) {
      l = mid + 1;
    } else if (nums[mid] == target) {
      r = mid; //attention
    } else if (nums[mid] > target) {
      r = mid; // attention
    }
  }
  return l;
}
```

## 右边界搜素

```cpp
int binarySearchRight(vector<int> &nums, target) {
  int l = 0, r = nums.size() - 1;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    if(nums[mid] < target) {
      l = mid + 1;
    } else if(nums[mid] == target) {
      l = mid + 1;
    } else if(nums[mid] > target) {
      r = mid - 1;
    }
  }
  return r < 0 || nums[r] != target ? - 1: r;
}
```

将搜索区间设置为$[l, r])$

## 代码总结

最后，总结并简化一下代码把


### [l, r]区间

定值搜索

```cpp
```

左边界搜索

```cpp
```

右边界搜素

```cpp
```

### [l, r)区间

定值搜索

```cpp
```

左边界搜索

```cpp
```

右边界搜索

```cpp

```

## 参考资料
- [二分查找详解](https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/er-fen-cha-zhao-xiang-jie)