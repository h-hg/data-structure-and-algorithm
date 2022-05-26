# 单调队列

单调队列是一种特俗的队列，队列内元素单调递减或单调递增的队列。

## 实现

假设队列内元素从栈头到栈尾严格单调递减，我们主要关注入队的实现，入队的实现与单调栈的压栈一样。

```cpp
template <typename T, typename container = deque<T>>
class MonotoneQueue: public queue<T, container>{
public:
  void push(T const &val) {
    while(!queue<T, container>::c.empty() && queue<T, container>::c.back() < val)
      queue<T, container>::c.pop_back();
    queue<T, container>::c.push_back(val);
  }
};
```

在这里，直接继承了`std::queue`，代码中的`c`是`std::queue`的`proctected`变量，即底层容器`containter`的实例。

## 与优先级队列的区别

有的读者可能觉得「单调队列」和「优先级队列」比较像，实际上差别很大的。

单调队列在添加元素的时候靠删除元素保持队列的单调性，相当于抽取出某个函数中单调递增（或递减）的部分；而优先级队列（二叉堆）相当于自动排序，差别大了去了。

## 题目

给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。返回每次滑动窗口中的最大值。

```
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

题目链接：[leetcode - 239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)

最暴力的想法很简单，对于每一段 [i, i + k) 的序列，逐个比较来找出最大值，时间复杂度约为 $\Theta(n \times k)$ 。很显然，这其中进行了大量重复工作，除了开头 k-1 个和结尾 k-1 个数之外，每个数都进行了 k 次比较。

我们使用单调队列来分析这道题，假设我们单调队列从队头到队尾单调递减。

由于我们总是需要求出滑动窗口内最大的元素值，而我们单调队列很容易求出最大值（也就是队头元素），因此我们可以用单调队列代替滑动窗口。

我们先看一下滑动窗口向右滑动一位的情况。此时我们需要将新元素 x 加入滑动窗口，将滑动窗口首元素 z 移出滑动窗口。

- 将新元素 x 加入滑动窗口，即将 x 入队，由于单调的性质可以知道，入队需要将队列中比 x 小的元素（不妨记为 y ）移出队列（滑动窗口）。由于 y 小于 x，且此后如果 y 在滑动窗口中 x 必然也在，所以滑动窗口内的最大值不可能是 y，将 y 不影响后面获得滑动窗口的最大值。
- 将滑动窗口首元素 z 移出滑动窗口，我们只需要判断队头是不是元素 z，如果是的话，则将其移除。因为 z 元素可能在 z 后一位元素到 x 之间的某个元素入队时被移出了。

AC 代码

```cpp
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    MonotoneQueue<int> window;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
      if (i < k - 1) { // fill the window with the first k-1 elements
        window.push(nums[i]);
      } else { // move the window
        window.push(nums[i]);
        res.push_back(window.front());
        if (!window.empty() && window.front() == nums[i - k + 1])
          window.pop();
      }
    }
    return res;
  }
};
```