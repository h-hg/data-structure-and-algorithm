# iterator

## operation

### `std::next` `std::prev`

```cpp
string s = "123";
auto iter = s.begin();
auto next = std::next(iter);
cout << (*iter) << ' ' << (*next); // 1 2
```

不会改变传入的迭代器

### `std::advance`

让迭代器前进 / 后退 n 步。

注：会根据迭代器种类选择性“优化”（特化）。

```cpp
string s = "123";
auto iter = s.begin();
auto next = std::advance(iter, 2);
cout << (*iter); // 1 3
```

### `std::distance`

返回一个区间的距离（后者 - 前者）。

```cpp
string s = "123";
cout << (distance(s.begin(), s.end())); // 3
```
