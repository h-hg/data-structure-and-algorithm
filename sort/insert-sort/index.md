# 插入排序

要理解插入排序的话，比较贴合我们直观的便是打扑克牌。假设你现在有几张排序好的扑克牌，若现在在牌尾后面还有一张未排序的扑克牌，让这张未排序的扑克牌，从后往前一张张比对，找到适合它的位置后，再把这张牌插入到这个位置。

移动法的实现如下

```cpp
void insert_sort(vector<int> &v) {
  for(int i = 1, n = v.size(); i < n; ++i) {
    auto curVal = v[i];
    int j = i;
    for(; j > 0 && curVal < v[j-1]; --j)
      v[j] = v[j - 1]; // move
    v[j] = curVal; // insert
  }
}
```

交换法的实现如下

```cpp
void insert_sort(vector<int> &v) {
  for(int i = 1, n = v.size(); i < n; ++i)
    for(int j = i; j > 0 && v[j] < v[j-1]; --j)
      swap(v[j],v[j-1]); // move and insert
}
```