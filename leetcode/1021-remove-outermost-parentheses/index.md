# Remove Outermost Parentheses

- [Leetcode](https://leetcode.com/problems/remove-outermost-parentheses)
- [力扣中国](https://leetcode.cn/problems/remove-outermost-parentheses)

## Problem

[](desc.md ':include')

## Solution

### Stack

遍历 `s`，并用一个栈来表示括号的深度。遇到 `(` 则将字符入栈，遇到 `)` 则将栈顶字符出栈。
栈从空到下一次空的过程，则是扫描了一个原语的过程。
一个原语中，首字符和尾字符应该舍去，其他字符需放入结果字符串中

[](stack1.cpp ':include :type=code cpp')

在上面的实现中，将符号与位置关联成了一个 `std::pair`，并一起放入栈中。
但实际上并不需要。

重点在于判断 `(` 和 `)` 是不是最外层的。
如果遇到的是 `(`，如果当前栈的大小为不空，则说明该 `(` 不是最外层的 `(`。
如果遇到的是 `）`，当弹栈后，栈的大小为不空，则说明该 `)` 不是最外层的 `)`。

[](stack2.cpp ':include :type=code cpp')

从上面的代码可以看出，如果符号是 `(`，则判断 `st.size()` 则放到 `st.push` 前面；而如果符号是 `)`，则判断 `st.size()` 则放到 `st.push` 后面，我们可以进一步简化判断流程。

[](stack3.cpp ':include :type=code cpp')

### Count

从上面可以看出，栈的内容，我们并不关系，这需要判断栈的大小而已。
所以，可以将压栈改成将栈计数器 + 1，弹栈改成将栈计数器 - 1。

[](count.cpp ':include :type=code cpp')
