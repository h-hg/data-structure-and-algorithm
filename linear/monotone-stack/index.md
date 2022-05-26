# 单调栈

单调栈是特殊的栈，栈内元素（栈底到栈顶）都是（严格）单调递增或者单调递减的。它常被可以用来解决一些ACM/ICPC和OI的题目。

## 实现

假设栈内元素从栈底到栈顶严格单调递减，我们主要关注入栈的实现，因为如果有新的元素入栈，栈调整过程中会将所有破坏单调性的栈顶元素出栈，并且出栈的元素不会再次入栈。具体实现代码如下

```cpp
template <typename T, typename sequence = deque<T>>
class MonotoneStack:public stack<T, sequence> {
public:
  void push(T const & val) {
    while(!stack<T, sequence>::empty() && stack<T, sequence>::top() <= val)
      stack<T, sequence>::pop();
    stack<T, sequence>::push(val);
  }
};
```

由于每个元素只有一次入栈和出栈的操作，所以单调栈的维护时间复杂度是 $\Theta(n)$。

## 理解

当然我们关注的不是其数据结构实现，而是该数据结构在解题的时候具有什么意义。

为了方便描述，我们假设单调栈内元素从栈底到栈顶是严格单调递减的，栈使用数据进行实现，栈底元素在栈顶元素的左边。

从上面压栈的实现中，我们可以发现，如果一个数组顺序压栈（从第一个元素开始顺序依次压入单调栈）的话，当第 i 个元素被压栈后，便会如下特点。

- 栈底元素是数组 [0...i] 中最大的元素。这是因为没有比它更大的元素压入，使得该元素被弹出。
- 栈内某一个元素 x，其左邻居（接近栈底一侧）元素是其在原数组中左边元素中，最接近它并且大于它的元素。这是因为它在原数组左边的元素肯定比它先压入，在栈内只能在它的左边，它在原数组左边比它小的元素在它压栈的时候都被弹出了，所以栈内左邻居只能是在原数组中左边最接近它并且大于它的元素。
- 栈内某一个元素 x，其右邻居（接近栈顶一侧）元素是其在原数组中右边元素中，最接近它并且小于它的元素。这是因为它在原数组右边的元素肯定比它先压入，在栈内只能在它的右边，它在原数组右边比它大的元素在压栈时，会将它弹出，所以栈内右邻居只能是在原数组中左边最接近它并且小于它的元素。

同样，当数组逆序压栈（从最后一个元素逆序逆序依次压栈）的话，当索引为 i 的元素被压栈后

- 栈底元素是数组 [i...n-1] 中最大的元素。
- 栈内某一个元素 x，其左邻居（接近栈底一侧）元素是其在原数组中右边元素中，最接近它并且大于它的元素。
- 栈内某一个元素 x，其右邻居（接近栈顶一侧）元素是其在原数组中左边元素中，最接近它并且小于它的元素。

## 题目

### 下一个更大的数 - 基础

为了更好地理解单调栈，我们先使用一个简单的例子来说明一下。该例子是[leetcode - 496. Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)的简化版。

给你一个数组，返回一个等长的数组，对应索引存储着下一个更大元素，如果没有更大的元素，就存 -1。

例如：给你一个数组 [2,1,2,4,3]，你返回数组 [4,2,4,-1,-1]。

解释：第一个 2 后面比 2 大的数是 4; 1 后面比 1 大的数是 2；第二个 2 后面比 2 大的数是 4; 4 后面没有比 4 大的数，填 -1；3 后面没有比 3 大的数，填 -1。

思路：使用严格递增的单调栈，如果对数组元素进行逆序压栈的话，当我们要压入元素 x 时，我们需要先弹出栈顶元素中比 x 小的元素，然后进行压栈，压入元素之前，我们可以发现此时的栈顶元素就是元素 x 在原数组中右边比它大且刚好最接近它的元素，这恰好是我们需要的答案。

实现代码：

```cpp
vector<int> nextGreaterElement(vector<int>& nums) {
  vector<int> ans(nums.size());
  stack<int> s;
  for (int i = nums.size() - 1; i >= 0; i--) {
    while (!s.empty() && s.top() <= nums[i]) {
      s.pop();
    }
    ans[i] = s.empty() ? -1 : s.top();
    s.push(nums[i]);
  }
  return ans;
}
```

其实我们可以发现，原题只是比我们上面的题目多一个映射关系，具体实现如下，细节就不讲了。

```cpp
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> val2pos;
    for(int i = 0, n = nums1.size(); i < n; ++i)
      val2pos[nums1[i]] = i;
    vector<int> ans(nums1.size());
    stack<int> st;
    for(int i = nums2.size() - 1; i >= 0; --i) {
      while(!st.empty() && st.top() <= nums2[i]) {
        st.pop();
      }
      auto it = val2pos.find(nums2[i]);
      if(it != val2pos.end()) {
        ans[it->second] = st.empty() ? -1 : st.top();
      }
      st.push(nums2[i]);
    }
    return ans;
  }
};
```

### 每日温度

给你一个数组 T = [73, 74, 75, 71, 69, 72, 76, 73]，这个数组存放的是近几天的天气气温（单位华氏度）。你返回一个数组，计算：对于每一天，你还要至少等多少天才能等到一个更暖和的气温；如果等不到那一天，填 0 。

例子：给你 T = [73, 74, 75, 71, 69, 72, 76, 73]，你返回 [1, 1, 4, 2, 1, 1, 0, 0]。

解释：第一天 73 华氏度，第二天 74 华氏度，比 73 大，所以对于第一天，只要等一天就能等到一个更暖和的气温。后面的同理。

完整的题目链接：[leetcode - 739. Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)

思路：这个问题本质上也是找下一个更大的数，只不过现在不是问你数字是多少，而是问你当前距离下一个更大的数的距离而已。我们只需要将压入元素，改成压入索引即可。

```cpp
class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> ans(T.size());
    stack<int> s;
    for (int i = T.size() - 1; i >= 0; i--) {
      while (!s.empty() && T[s.top()] <= T[i]) {
        s.pop();
      }
      ans[i] = s.empty() ? 0 : (s.top() - i);
      s.push(i);
    }
    return ans;
  }
};
```

### 下一个更大的数 - 基础

给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

题目链接：[503. Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/)

思考：我们看到该题与前面的主要区别就是加入循环数组的概念。首先，计算机的内存都是线性的，没有真正意义上的环形数组，但是我们可以模拟出环形数组的效果，一般是通过取模运算符求模（余数），获得环形特效。实际上，我们只需要将原来的数据扩展为原来的两倍——将原始数组“翻倍”，就是在后面再接一个原始数组，这样的话，原数组的每一个元素都有右边的元素了。但是，我们可以不用构造新数组，而是利用循环数组的技巧来模拟。直接看代码吧：

```cpp
class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    stack<int> s;
    for (int i = 2 * n - 1; i >= 0; i--) {
      while (!s.empty() && s.top() <= nums[i % n])
        s.pop();
      res[i % n] = s.empty() ? -1 : s.top();
      s.push(nums[i % n]);
    }
    return res;
  }
};
```

### 其他题目

- [42. Trapping Rain Water](https://leetcode-cn.com/problems/trapping-rain-water/)

## 总结

通过上面的例子，我们可以得知单调栈可以在 $\Theta(1)$ 的时间得知某个位置左右两侧比他大（或小）的数的位置。当我们需要高效率获取某个位置左右两侧比他大（或小）的数的位置的时候，可以考虑是否可以使用单调栈。