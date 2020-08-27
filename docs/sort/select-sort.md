# 选择排序

选择排序是一种最符合人类直观感觉的排序算法。例如，给你一堆大小不一且乱七八糟的盒子，让你给这堆盒子按从小到大排序，最简单的方法便是从这一堆乱七八糟的盒子堆里挑选出一个最小的盒子摆放在别处，再挑选出第二小的盒子摆放在最小盒子后面，直至所有盒子都摆放好。

```cpp
void select_sort(vector<int> &v) {
  for(int i = 0, n = v.size(); i < n; ++i) {
    int minIdx = i;
    for(int j = i + 1; j < n; ++j)
      if(v[j] < v[minIdx]) {
        minIdx = j;
      }
    swap(v[minIdx], v[i]);
  }
}
```

迭代器版本实现

```cpp
template <typename OutputIterator>
void select_sort(OutputIterator first, OutputIterator last) {
  for(;first != last; ++first) {
    auto minIter = first, curIter = first;
    for(++curIter; curIter != last; ++curIter)
      if(*curIter < *minIter)
        minIter = curIter;
    swap(*minIter, *first);
  }
}
```

