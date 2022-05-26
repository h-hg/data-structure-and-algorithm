# ZigZag Conversion

- [Leetcode](https://leetcode.com/problems/zigzag-conversion)
- [力扣中国](https://leetcode.cn/problems/zigzag-conversion)

## Problem

[](desc.md ':include')

## Solution

### Simulation

模拟算法：从左到右读取每一个字符，然后按照 N 字形确定该字符所在的行，依次将字符放在输出的所在行。

[](simulation.cpp ':include :type=code cpp')

### 