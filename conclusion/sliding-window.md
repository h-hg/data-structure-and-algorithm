# 滑动窗口

## 题目列表

- [Leetcode - 76. Minimum Window Substring](/leetcode/76-minimum-window-substring/index.md)
- [Leetcode 567. Permutation in String](/leetcode/567-permutation-in-string/index.md)
- [Leetcode 438. Find All Anagrams in a String](/leetcode/438-find-all-anagrams-in-a-string/index.md)
- [Leetcode - 3. Longest Substring Without Repeating Characters](/leetcode/3-longest-substring-without-repeating-characters/index.md)
- [Leetcode - 283. Move Zeroes](/leetcode/283-move-zeroes/index.md)

## 框架

```cpp
// v is list, n is the size of v
int l = 0, r = 0;
while(r < n) {
  // enlarge the window
  window.add(v[r++]);

  // shrink the window
  while(/* need shrinking */) {
    windows.remove(v[l++]);
    // other operation
  }
}
```

滑动窗口还有一种特殊的形式，即窗口的大小是固定的。
例如 leetcode 1297，看看别人这种窗口固定都是怎么写的。
还有一个问题就是这个 update answser 应该写在 shrink the window 的 while 里面，还是 while 的下面。

https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/discuss/1972518/C%2B%2B-38ms

```cpp
int l = 0, r = 0;
// init the window
while(r < nWindow)
  window.add(v[r++]);
// move window by one step
while(r <= n) {
  // update the answer
  // move the window
  // 1. enlarge the window
  window.add(v[r++]);
  // 2. shrink the window
  window.remove(v[l++]);
}
```

我上面那个模板有问题，就是当 r == n 后，进入循环后，update answer 是没问题的，但是 enlarge the window 是有问题的，因为 r 越界了。