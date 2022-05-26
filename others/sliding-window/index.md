# 滑动窗口

## 简介

滑动窗口的题目，就是维护一个窗口，不断滑动，然后更新答案。其解题框架大致如下

其实困扰大家的，不是算法的思路，而是各种细节问题。比如说如何向窗口中添加新元素，如何缩小窗口，在窗口滑动的哪个阶段更新结果。所以下面给出伪代码的模板

[参考资料](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485141&idx=1&sn=0e4583ad935e76e9a3f6793792e60734&chksm=9bd7f8ddaca071cbb7570b2433290e5e2628d20473022a5517271de6d6e50783961bebc3dd3b&scene=21#wechat_redirect)

```
function slidingWindow(array)
  l = 0, r = 0 // [l, r)
  while r < n:
    // enlarge the window
    add array[r] to window
    r <- r + 1

    // if you nedd debug
    // print l, r

    while(window needs shrink)
      // update the data of window
      // ...

      //shrink the window
      remove array[l] from window
      l <- l + 1
```

一般情况下，该算法的时间复杂度为 $\Theta(n)$。

`window`表示滑动窗口，具体的数据结构根据题目的要求灵活而定。


有时候，滑动窗口总是固定为 k，那么上面伪代码可以修改为

```
function slidingWindow(array, k)
  l = 0, r = 0 // [l, r)
  while r < n:
    // enlarge the window
    add array[r] to window
    r <- r + 1

    // if you nedd debug
    // print l, r

    if(r - l == k)
      // update the data of window
      // ...

      //shrink the window
      remove array[l] from window
      l <- l + 1
```

## 题目

为了更好地了解它的应用，还是从刷题开始最好。

### 最小覆盖字串

给你一个字符串 s、一个字符串 t 。请你设计一种算法，可以在 $O(n)$ 的时间复杂度内，从字符串 s 里面找出：包含 t 所有字符的最小子串。

题目链接：[leetcode - 76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)

步骤：

1. 我们在字符串 s 中使用双指针中的左右指针技巧，初始化`l = r = 0`，把索引左闭右开区间 $[l, r)$ 称为一个窗口。
2. 我们先不断地增加`r`指针扩大窗口 $[l, r)$，直到窗口中的字符串符合要求（包含了`t`中的所有字符）。
3. 此时，我们停止增加`r`，转而不断增加`l`指针缩小窗口 $[l, r)$，直到窗口中的字符串不再符合要求（不包含T中的所有字符了）。同时，每次增加`l`，我们都要更新一轮结果。
4. 重复第 2 和第 3 步，直到`r`到达字符串S的尽头。

步骤都知道了，那么就剩下如何表达窗口的数据结构了。

我们使用一个名为`need`的`map<int, int>`来表示`t`中字符与其相应的个数关系，而`window`（类型同样为`map<int, int>`）来表示窗口内字符（只限于存在于`t`中字符）与其相应的个数关系。同时，引入一个`valid_n`变量来表示窗口满足字符串`t`字符的个数，当`valid_n == need.size()`时则表示窗口的字符串符合要求了。具体的实现代码如下。

```cpp
class Solution {
public:
  int ans_n = INT_MAX, ans_l = 0; 
  string minWindow(string &s, string &t) {
    map<int, int> need, window;
    for(auto &c: t)
      ++need[c];
    int l = 0, r = 0, valid_n = 0;
    while(r < s.size()) {
      //enlarge the window
      char c1 = s[r++];
      if(need.count(c1) && ++window[c1] == need[c1])
        ++valid_n;
      
      while(valid_n == need.size()) {
        // whether the window is a smaller substring
        if(r - l < ans_n) {
          ans_l = l;
          ans_n = r - l;
        }
        // shrink the window
        char c2 = s[l++];
        if(need.count(c2) && window[c2]-- == need[c2])
          --valid_n;
      }
    }
    return ans_n == INT_MAX ? "" : s.substr(ans_l, ans_n);
  }
};
```

上面的代码使用`map`来表示窗口，由于`map`访问数据的时间并不是 $\Theta(1)$，严格上来说时间复杂度并不是$\Theta(n)$。

下面使用数组（`vector`）来表示窗口，使得运行效率加快。

- 对于`t`中的字符`c`，`window[c]`总是`< 0`
- 对于非`t`中的字符`c`，当 `window[c] <= 0`则表示当前窗口满足`t`中字符`c`的个数要求。

同时我们使用一个`remaining`来表示当前窗口还需要匹配`t`中的字符个数，当`remaining = 0`则表示当前窗口的字符已经满足要求了。

```cpp
class Solution {
public:
  int ans_n = numeric_limits<int>::max(), ans_l = 0;
  string minWindow(string &s, string &t) {
    vector<int> window(128, 0);
    for (char c : t)
      ++window[c];
    int remaining = t.size();
    int l = 0, r = 0;
    while (r < s.length()) {
      // enlarge the window
      if (--window[s[r++]] >= 0)
        --remaining;
      while (remaining == 0) {
        // whether the window is a smaller substring
        if (r - l < ans_n) {
          ans_n = r - l;
          ans_l = l;
        }
        // shrink the window
        if (++window[s[l++]] > 0)
          ++remaining;
      }
    }
    return ans_n == numeric_limits<int>::max() ? "" : s.substr(ans_l, ans_n);
  }
};
```

## 字符串排列

给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

题目链接：[leetcode - 567. Permutation in String](https://leetcode.com/problems/permutation-in-string/)

这道题便是滑动窗口大小固定为`s1.size()`的题目。

```cpp
class Solution {
public:
  bool checkInclusion(string &s1, string &s2) {
    vector<int> dict(128, 0);
    for (auto &c : s1)
      ++dict[c];
    int l = 0, r = 0, remaining = s1.size();
    while (r < s2.size()) {
      // enlarge the window
      if(--dict[s2[r++]] >= 0)
        --remaining;
      if(r - l == s1.size()) {
        if(remaining == 0)
          return true;
        //shrink the window
        if(++dict[s2[l++]] > 0)
          ++remaining;
      }
    }
    return false;
  }
};
```

## 字符串中字母异位词

题目链接：[438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

这道题与上面字符串排序的不同之出在于字符串排序只是要求存在与否，这道题改成输出全部。

```cpp
class Solution {
public:
  vector<int> findAnagrams(string &s, string &p) {
    vector<int> ans;
    vector<int> dict(128, 0);
    for (auto &c : p)
      ++dict[c];
    int l = 0, r = 0, remaining = p.size();
    while (r < s.size()) {
      // enlarge the window
      if(--dict[s[r++]] >= 0)
        --remaining;
      if(r - l == p.size()) {
        if(remaining == 0)
          ans.push_back(l);
        //shrink the window
        if(++dict[s[l++]] > 0)
          ++remaining;
      }
    }
    return ans;
  }
};
```

## 火星购物

[1044 Shopping in Mars](https://pintia.cn/problem-sets/994805342720868352/problems/994805439202443264)

```cpp
#include <iostream>
#include <map>
#include <vector>
#include <climits>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> d(n);
  for(int i = 0; i < n; ++i)
    cin >> d[i];
  //sliding windows
  int l = 0, r = 0, sum = 0; //[l, r)
  int minCost = INT_MAX;
  vector<pair<int, int>> ans;
  while(r < n) {
    //enlarge
    sum += d[r];
    ++r;
    while (sum >= m) {
      //update
      int cost = sum - m;
      if(cost < minCost) {
        ans.clear();
        minCost = cost;
        ans.push_back({l, r - 1});
      } else if(cost == minCost) {
        ans.push_back({l, r - 1});
      }
      //shrinkage
      sum -= d[l];
      ++l;
    }
  }
  //output
  for(auto &p : ans)
    cout << (p.first + 1) << '-' << (p.second + 1) << endl;
  return 0;
}
```