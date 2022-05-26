# Minimum Window Substring

- [Leetcode](https://leetcode.com/problems/minimum-window-substring)
- [力扣中国](https://leetcode.cn/problems/minimum-window-substring)

## Problem

[](desc.md ':include')

## Solution

使用滑动窗口求解时，最常见的思路是维护一个窗口，记录窗口内的字符与字符窗 `t` 的关系。
若窗口内的字符满足要求，则更新答案，直到滑动窗口滑到尾端。

[](solution-1.cpp ':include :type=code cpp')

使用 `need` 来表示字符串 `t`，`window` 来表示滑动窗口，利用 `valid` 和 `need.size()` 的关系来判断是否满足要求。

实际上，`window` 是多余的，反过来看的话，如果滑动窗口加入属于 `t` 的字符，则让 `need` 所对应的字符的数量减 1，若减到 0，则说明该字符得到了 `valid`。
因此，可以改进为下面的代码。

[](solution-2.cpp ':include :type=code cpp')

上面 `valid` 表示 `t` 中已被满足的字符种类数。
如果 `valid` 改成 `t` 中还需要被满足的字符数。
则可改进为如下的代码。

[](solution.cpp ':include :type=code cpp')

- 代码利用了柱状图（`hist`）的特点，某个字符在柱状图大于 0，则表示该字符是字符串 `t` 的字符，但在滑动窗口中没有匹配完。

- 在缩小窗口时，如果 `s[l++]` 不是 `t`中的字符串，为什么可以执行 `++hist[s[l++]] > 0`，不怕 `++hist[s[l++]]` 超过 0 ？原因在若 `s[l++]` 不是 `t` 的字符，一开始为 `0`，在增加窗口时被减为负数，所在收缩时，由于移除的字符肯定小于等于加入字符，所以不能出现大于 0 的情况。

- 使用大于 0 这种表示形式可以减少判断字符是否存在于字符串 `t` 中，统一处理字符串 `s` 的字符，减少代码逻辑。
