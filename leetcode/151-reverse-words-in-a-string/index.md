# Reverse Words in a String

- [Leetcode](https://leetcode.com/problems/reverse-words-in-a-string)
- [力扣中国](https://leetcode.cn/problems/reverse-words-in-a-string)

## Problem

[](desc.md ':include')

## Solution

### Store Words

思路：把字符串分隔成多个 word 存储起来，再逆序拼接 word。

[](store-word.cpp ':include :type=code cpp')

### Stack

这种逆序的输出，可以使用 stack。
扫描字符串是从头到尾，而输出的单词是尾先头后，这跟 stack 和相近。
先扫描得到的 word 先压栈。

[](stack.cpp ':include :type=code cpp')

注意点

- 这里没有使用 `std::stringstream`，是为了跟上面体现差别
- `s.push_back(' ');` 的使用，可以减少当 `for` 结束后，还要 `if(word.size()) words.push(word);`

### Inplace

为了让空间复杂为 $\Theta(1)$，就必修在原地操作。
其步骤如下：

1. 删除多余空格，包含首尾空格以及中间重复空格
2. 反转全部字符
3. 挨个反转每一个 word

[](inplace.cpp ':include :type=code cpp')
