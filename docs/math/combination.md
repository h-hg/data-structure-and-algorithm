# 组合

## 幂集

输出n个元素的所有子集，如{a,b,c}的子集为{}，{a}，{b}，{c}，{a,b}，{a,c}，{b,c}，{a,b,c}

[leetcode](https://leetcode.com/problems/subsets/)
[leetcode 2](https://leetcode.com/problems/subsets-ii/)

### 位图法 - 二进制数

如果每个元素都是用一位来对应的话，0 表示该元素被选择，1 表示该元素没有被选择。那么上面的幂集为 000，001，010，100，110，101，011，111。

```cpp
template <typename T>
void power_set(vector<T> const &v) {
  for(int bitmap = 0, len = v.size(), n = 1 << len; bitmap < n; ++bitmap) {
    //output
    for(int bit = 1, i = 0; i < len; ++i) {
      if(bitmap & bit) // get the state of v[i]
        cout << v[i] << ' ';
      bit <<= 1;
    }
    cout << endl;
  }
}
```

### 位图法 - 向量

位图法虽然运算效率快，但法无法解决元素数大于`sizeof(int)`的，因此我们可以利用一个`bool`的数组结合递归和回溯实现元素的选择。

```cpp
template <typename T>
void power_set_helper(vector<T> const &v, vector<bool> &bitmap, int cur) {
  if(cur == v.size()) {
    //output
    for(int i = 0, n = v.size(); i < n; ++i)
      if(bitmap[i])
        cout << v[i] << ' ';
    cout << endl;
    return;
  }
  bitmap[cur] = false; // don't choose the element v[cur]
  power_set_helper(v, bitmap, cur + 1);
  bitmap[cur] = true; // backtracing, choose the element v[cur]
  power_set_helper(v, bitmap, cur + 1);
}

template <typename T>
void power_set2(vector<T> const &v) {
  vector<bool> bitmap(v.size(), false);
  power_set_helper(v, bitmap, 0);
}
```

### 增量构造法

### 递归

```cpp
template <typename T>
void combination2_helper(vector<T> const &v, int m, int cur, vector<T> &cur_v) {
  if(cur_v.size() == m) {
    //ouput
    for(auto &val : cur_v)
      cout << val << ' ';
    cout << endl;
    return;
  }
  if(cur == v.size())
    return;
  cur_v.push_back(v[cur]);
  combination2_helper(v, m, cur + 1, cur_v);
  cur_v.pop_back();
  combination2_helper(v, m, cur + 1, cur_v);
}

template <typename T>
void combination2(vector<T> const &v, int m) {
  vector<T> cur_v;
  cur_v.reserve(m);
  combination2_helper(v, m, 0, cur_v);
}
```

这种实现类似于全排列的递归实现

```cpp
template <typename T>
void combination3_help(vector<T> const &v, int cur, vector<T> &output, int output_cnt) {
  if(output_cnt == output.size()) {
    //ouput
    for(auto &val : output)
      cout << val << ' ';
    cout << endl;
    return;
  }
  for(int i = cur; i < v.size(); ++i) {
    output[output_cnt] = v[i];
    combination3_help(v, i + 1, output, output_cnt + 1);
  }
}
template <typename T>
void combination3(vector<T> const &v, int m) {
  vector<T> output(m);
  combination3_help(v, 0, output, 0);
}
```

## 组合

输出n个元素的幂集中含有m个元素的子集，如{a,b,c}，m = 2，输出{a,b}，{a,c}，{b,c}

### 下一个排列法

我们可以使用位图法结合下一个排列，在实现输出所有的组合，代码如下

```cpp
template <typename T>
void combination(vector<T> const &v, int m) {
  vector<int> bitmap(v.size(), 0);
  fill(bitmap.end() - m, bitmap.end(), 1);
  do {
    //output
    for(int i = 0, n = v.size(); i < n; ++i)
      if(bitmap[i])
        cout << v[i] << ' ';
    cout << endl;
  }while(next_permutation(bitmap.begin(), bitmap.end()));
}
```

### 01转换法

