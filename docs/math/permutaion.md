# 排列

## 全排列

给你 n 个元素，请输出这 n 个元素的全排列。

最常见的方法便是使用递归的方式。

```cpp
//permutaion for [frist, last)
template <typename RandomIterator>
void permutaion(RandomIterator first, RandomIterator last, RandomIterator cur) {
  if(cur == last) {
    //print
    for(auto it = first; it != last; ++it)
      cout << (*it) << ' ';
    cout << endl;
    return;
  }
  for(auto it = cur; it != last; ++it) {
    //select an element from [cur, last) as current position
    swap(*cur, *it);
    //goto next element
    permutaion(first, last, cur + 1);
    //backtracing
    swap(*cur, *it);
  }
}
```

原理：n 个元素的全排列等于依次将这 n 个元素作为排列的第一个元素，然后进行 n-1 个元素的全排列。

1. `swap(*cur, *it);`：从 n 个元素中选择一个元素作为排列的第一个元素
2. `permutaion(first, last, it + 1);`：进行 n-1 个元素的全排列
3. `swap(*cur, *it);`：回溯

上面的实现，没有考虑给的序列存在相同的元素，如果序列中存在相同的元素，则会产生多个相同的序列。

例如，对{1，2，2}，第一个数1与第二个数2交换得到212，然后考虑第一个数1与第三个数2交换，得到212，我们发现该序列在前面已经出现过了，这是由于第三个数2在它与第一个数之间右一个等于它的数，也就是第二个数字2。

所以我们只需要在交换前判断前面（或者后面）是否有相同的数字，若有的话，就停止本次交换，就可以避免将相同的元素多次换到当前位置（`cur`）。

```cpp
template <typename RandomIterator>
void permutaion(RandomIterator first, RandomIterator last, RandomIterator cur) {
  if(cur == last) {
    //print
    for(auto it = first; it != last; ++it)
      cout << (*it) << ' ';
    cout << endl;
    return;
  }
  for(auto it = cur; it != last; ++it) {
    //if(cur != it && find(cur, it, *it) != it) // judge before
    if(find(it + 1, last, *it) != last) // judege behind
      continue;
    //select an element from [cur, last) as current position
    swap(*cur, *it);
    //goto next element
    permutaion(first, last, cur + 1);
    //backtracing
    swap(*cur, *it);
  }
}
```

## 下一个排列

给定一个 n 个元素的排列，输出在字典序上比该排列大的最小字典序排列。；例如 123，输出 132，而不是 213、231、312 和 321。

记 n 个元素的范围为 [0 ,n)

1. 从后往前找，找到第一个比其下一个元素小的元素 A。
2. 若不存在元素 A，表明该序列是递降序列，即字典序最大，不存在下一个排列，直接反转这个序列，得到字典序最小的序列。否则下面的步骤。
3. 记元素 A 的位置为i，在 [i, n) 从后往前找，找到第一个大于等于 A 的元素 B，记其位置为 j
4. 交换元素 A 和 B，反转 [i + 1, n)里面的元素。

```cpp
bool nextPermutation(vector<int>& nums) {
  if(nums.size() < 2)
    return false;
  int i = nums.size() - 2;
  while(i >= 0 && nums[i+1] <= nums[i])
    --i;
  if(i > 0 || (i == 0 && nums[0] < nums[1])) {
    int j = nums.size() - 1;
    while(j > i && nums[j] <= nums[i])
      --j;
    swap(nums[i],nums[j]);
    reverse(nums.begin() + (i + 1),nums.end());
    return true;
  } else {
    reverse(nums.begin(),nums.end());
    return false;
  }
}
```

参考`std::next_permutaion`的实现

```cpp
template <typename BidirectionalIterator>
bool nextPermutation(BidirectionalIterator first, BidirectionalIterator last) {
  if(first == last) // empty interval
    return false;
  BidirectionalIterator i = first;
  ++i;
  if(i == last) // only an element
    return false;
  i = last;
  --i;
  while(1) {
    BidirectionalIterator ii = i;
    --i; // i + 1 == ii
    
    if(*i < *ii) { // get the first element which is smaller than its next element
      BidirectionalIterator j = last;
      while(!(*i < *--j)); // find the element which is greater or equal to *i
      swap(*i, *j);
      reverse(ii, last);
      return true;
    }
    if(i == first) { // no such element
      reverse(first, last);
      return false;
    }
  }
}
```

在有了下一个排列后，我们就可以实现全排序了。

```cpp
template <typename RandomIterator>
void permutaion(RandomIterator first, RandomIterator last) {
  sort(first, last);
  do {
    for(auto it = first; it != last; ++it) {
      cout << (*it) << ' ';
    }
    cout << endl;
  }while(nextPermutation(first, last));
}
```