# unique

`std::unique` 的作用是从输入序列中“删除”所有相邻的重复元素。
它并不真正删除重复的重复的序列，只是把没重复的元素往前移动了。

其基本思路如下

```cpp
template <class ForwardIterator>
  ForwardIterator unique (ForwardIterator first, ForwardIterator last);
template <class ForwardIterator, class BinaryPredicate>
  ForwardIterator unique (ForwardIterator first, ForwardIterator last,
                          BinaryPredicate pred);

template <class ForwardIterator>
  ForwardIterator unique (ForwardIterator first, ForwardIterator last)
{
  if (first==last) return last;

  ForwardIterator result = first;
  while (++first != last)
  {
    if (!(*result == *first))  // or: if (!pred(*result,*first)) for version (2)
      *(++result)=*first;
  }
  return ++result;
}
```

例子

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  string s = "ab   abcef";
  cout << s << endl;                              // ab   abcef
  auto end = unique(s.begin(), s.end());
  cout << s << endl;                              // ab abcefef
  for(auto iter = s.begin(); iter != end; ++iter)
    cout << (*iter);
  cout << endl;                                   // ab abcef
  return 0;
}
```

上面的相邻重复的元素只有空格，那么 unique 的作用就是把多个连续空格变成一个空格。

如果重复的元素有字母的话，字母也会被“移除”，如果只想要移除空格的话，应该自定义 `pred`

```cpp
string s = "abb  ab";
auto end = unique(s.begin(), s.end(), [](char slow, char fast) {
  return slow == fast && fast == ' ';
})
```
