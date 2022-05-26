# Move Zeroes

- [Leetcode](https://leetcode.com/problems/move-zeroes)
- [力扣中国](https://leetcode.cn/problems/move-zeroes)

## Problem

[](desc.md ':include')

## Solution

### Slow and Fast pointer

快慢指针法。
`fast`指针用于遍历整个 `nums`，`slow` 指针用于写 `fast` 指针遇到的 `non-zero`。
当 `fast` 遍历完后，就是已经把 `non-zero` 都写在 `nums` 前面，最后再由 `slow` 指针写 `zero` 部分。

[](slow-fast-pointers.cpp ':include :type=code cpp')

### Sliding Windos

保证窗口内的元素都是 `zero`。
当有新元素加入时（`r++`），若新元素为 `zero`，则直接加入（不操作），否则，则将窗口的第一个元素与新元素交换（`swap(nums[l], nums[r]`），同时将窗口长度缩小 1（`l++`）。

[](sliding-window.cpp ':include :type=code cpp')
