## 二叉堆

最近复习了一下堆，顺便写写笔记吧！

堆是一种完全二叉树，按照父子之间的关系可以分成两种类型，即最大堆和最小堆。
- 最大堆：父元素大于等于子节点
- 最小堆：父元素小于等于子节点

## 实现
常见的实现结构是数组。下图是数组下标在堆中的位置。

{% mermaid graph TB %}
  0((0))
  1((1))
  2((2))
  3((3))
  4((4))
  5((5))
  6((6))
  7((7))
  8((8))
  9((9))

  0 --> 1
  0 --> 2
  1 --> 3
  1 --> 4
  2 --> 5
  2 --> 6
  3 --> 7
  3 --> 8
  4 --> 9
{% endmermaid %}

从图中，我们可以看出几个规律：设$n$为堆中节点个数（上图中节点个数是10，不是9），$i$为其中某一个节点（在数组中的下标）。

- $i$的左孩子：$2i + 1, 2i + 1 < n$
- $i$的右孩子：$2i + 2, 2i + 2 < n$
- $i$的父节点（$i \not= 0$）
  - $i$为偶数：$\lfloor \frac{i - 1}{2} \rfloor$
  - $i$为奇数：$\lfloor \frac{i}{2} \rfloor$
- 最后一个非叶子节点（内部节点）：$\lfloor \frac{n}{2} - 1\rfloor$
- 叶子下标满足：$[\lfloor \frac{n}{2} \rfloor, n)$

## 建堆
为了方便起见，我用最小堆为例，最大堆类比一下即可。
现在有一个数组`vector<int> arr = {7, 10, 4, 9, 12, 15, 8, 16, 6}`，也就是未初始化的堆，它的值在堆中节点分布如下。

{% mermaid graph TB %}
  0((7))
  1((10))
  2((4))
  3((3))
  4((9))
  5((12))
  6((15))
  7((8))
  8((16))
  9((6))

  0 --> 1
  0 --> 2
  1 --> 3
  1 --> 4
  2 --> 5
  2 --> 6
  3 --> 7
  3 --> 8
  4 --> 9
{% endmermaid %}

我们从下标最大的非叶子节点开始（也就是上面提到的$\lfloor \cfrac{n}{2} - 1\rfloor$），依次“向下拉”，拉到最底层或者满足条件为止。也就是从图中值为9的节点开始。

首先，9和它的子节点不满足最小堆的定义，因为9比6大。所以我们将9和6交换，也就是“向下拉”。

{% mermaid graph TB %}
  0((7))
  1((10))
  2((4))
  3((3))
  4((6))
  5((12))
  6((15))
  7((8))
  8((16))
  9((9))

  0 --> 1
  0 --> 2
  1 --> 3
  1 --> 4
  2 --> 5
  2 --> 6
  3 --> 7
  3 --> 8
  4 --> 9
{% endmermaid %}
现在9已经到达最底层了，所以这个节点已经完成了。

接着，我们考虑下标值第二大的非叶子节点，也就是值为3的节点，发现3和它的孩子节点（8和16）满足条件（3小于等于8或16），所以不用“向下啦”。

接着，我们考虑值为4的节点，跟3一样，不用向下了。

接着，我们考虑值为10的节点，发现10不满足条件（10小于等于3或9），所以将10与3交换，因为我们要满足父节点同时小于等于孩子节点，所以必须选孩子节点中最小的那一个。

{% mermaid graph TB %}
  0((7))
  1((3))
  2((4))
  3((10))
  4((6))
  5((12))
  6((15))
  7((8))
  8((16))
  9((9))

  0 --> 1
  0 --> 2
  1 --> 3
  1 --> 4
  2 --> 5
  2 --> 6
  3 --> 7
  3 --> 8
  4 --> 9
{% endmermaid %}
此时10依旧不满足条件，还需要将10与8交换。
{% mermaid graph TB %}
  0((7))
  1((3))
  2((4))
  3((8))
  4((6))
  5((12))
  6((15))
  7((10))
  8((16))
  9((9))

  0 --> 1
  0 --> 2
  1 --> 3
  1 --> 4
  2 --> 5
  2 --> 6
  3 --> 7
  3 --> 8
  4 --> 9
{% endmermaid %}

此时10已经到达最小面了，所以停止了。

现在只剩下最后一个节点了，也就是7。首先7不满足条件。将7与3交换。
{% mermaid graph TB %}
  0((3))
  1((7))
  2((4))
  3((8))
  4((6))
  5((12))
  6((15))
  7((10))
  8((16))
  9((9))

  0 --> 1
  0 --> 2
  1 --> 3
  1 --> 4
  2 --> 5
  2 --> 6
  3 --> 7
  3 --> 8
  4 --> 9
{% endmermaid %}

交换后，7依旧不满足条件，将7与6交换。
{% mermaid graph TB %}
  0((3))
  1((6))
  2((4))
  3((8))
  4((7))
  5((12))
  6((15))
  7((10))
  8((16))
  9((9))

  0 --> 1
  0 --> 2
  1 --> 3
  1 --> 4
  2 --> 5
  2 --> 6
  3 --> 7
  3 --> 8
  4 --> 9
{% endmermaid %}

此时7比9小，满足条件，不用再“向下拉”了。

至此，最小堆建立完成。下面给出“向下拉”和建堆的代码。
```cpp
template <typename T, typename Compare>
void siftDown(vector<T> &arr, int x, Compare &cmp) {
  int n = arr.size();
  while(!(n/2 <= x && x < n)) /* judge whether x is a leaf*/{
    //get the max/min child
    int lc = x * 2 + 1, rc = lc + 1; //lc is left child, lr is right child
    if(rc < n && cmp(arr[rc], arr[lc]))
      lc = rc;
    //compare with parent node
    if(cmp(arr[x], arr[lc]))//meet the condition
      break;
    //sift down
    swap(arr[x], arr[lc]);
    x = lc;
  }
}
template<typename T, typename Compare>
void build(vector<T> &arr, Compare &cmp) {
  for(int x = arr.size() / 2 - 1; x >= 0; --x)
    siftDown<T, Compare>(arr, x, cmp);
}
```

将上面的数据测试一下
```cpp
int main() {
  vector<int> arr = {7, 10, 4, 3, 9, 12, 15, 8, 16, 6};
  less_equal<int> cmp;
  build<int, less_equal<int>>(arr, cmp);
  for(auto v: arr)
    cout << v << ' ';
  return 0;
}
```
```
3 6 4 8 7 12 15 10 16 9
```

## 删除
堆中每次都只能删除第1个元素，也就是下标为0的元素。

为了便于重建堆，实际上的操作是将最后一个元素与第一个元素进行交换，然后删除堆中最后一个元素，然后将第一个元素“向下拉”。

以上面建好的堆为例。
交换：
{% mermaid graph TB %}
  0((9))
  1((6))
  2((4))
  3((8))
  4((7))
  5((12))
  6((15))
  7((10))
  8((16))
  9((3))

  0 --> 1
  0 --> 2
  1 --> 3
  1 --> 4
  2 --> 5
  2 --> 6
  3 --> 7
  3 --> 8
  4 --> 9
{% endmermaid %}

删去最后最后一个元素
{% mermaid graph TB %}
  0((9))
  1((6))
  2((4))
  3((8))
  4((7))
  5((12))
  6((15))
  7((10))
  8((16))

  0 --> 1
  0 --> 2
  1 --> 3
  1 --> 4
  2 --> 5
  2 --> 6
  3 --> 7
  3 --> 8
{% endmermaid %}

将第一个元素“向下拉”
{% mermaid graph TB %}
  0((4))
  1((6))
  2((9))
  3((8))
  4((7))
  5((12))
  6((15))
  7((10))
  8((16))

  0 --> 1
  0 --> 2
  1 --> 3
  1 --> 4
  2 --> 5
  2 --> 6
  3 --> 7
  3 --> 8
{% endmermaid %}

实现代码
```cpp
template<typename T, typename Compare>
void rmFirst(vector<T> &arr, Compare &cmp) {
  swap(arr.front(), arr.back());
  arr.pop_back();
  if(arr.size())
    siftDown<T, Compare>(arr, 0, cmp);
}
```

## 插入
例如现在我们要插入一个值5的元素，首先，我们把这个元素放置在数组的末尾，然后采取与“向下拉”相反的操作，即“向上拉”。一直向上直到根部或者改元素与其父元素满足堆的定义。

以上面建好的堆为例。

插入值为5的元素
{% mermaid graph TB %}
  0((3))
  1((6))
  2((4))
  3((8))
  4((7))
  5((12))
  6((15))
  7((10))
  8((16))
  9((9))
  10((5))

  0 --> 1
  0 --> 2
  1 --> 3
  1 --> 4
  2 --> 5
  2 --> 6
  3 --> 7
  3 --> 8
  4 --> 9
  4 --> 10
{% endmermaid %}

由于5与7的大小关系不满足最小堆定义，所以将与7交换位置
{% mermaid graph TB %}
  0((3))
  1((6))
  2((4))
  3((8))
  4((5))
  5((12))
  6((15))
  7((10))
  8((16))
  9((9))
  10((7))

  0 --> 1
  0 --> 2
  1 --> 3
  1 --> 4
  2 --> 5
  2 --> 6
  3 --> 7
  3 --> 8
  4 --> 9
  4 --> 10
{% endmermaid %}

由于5和6不满足最小堆定义，5和6交换位置。
{% mermaid graph TB %}
  0((3))
  1((5))
  2((4))
  3((8))
  4((6))
  5((12))
  6((15))
  7((10))
  8((16))
  9((9))
  10((7))

  0 --> 1
  0 --> 2
  1 --> 3
  1 --> 4
  2 --> 5
  2 --> 6
  3 --> 7
  3 --> 8
  4 --> 9
  4 --> 10
{% endmermaid %}

5和3满足最小堆定义，“向上拉”操作完成。

```cpp
template<typename T, typename Compare>
void siftUp(vector<T> &arr, int x, Compare &cmp) {
  while(x > 0) {
    int p = (x & 1) ? x / 2 : (x - 1) / 2;
    if(cmp(arr[p], arr[x]))
      break;
    swap(arr[p], arr[x]);
    x = p;
  }
}

template<typename T, typename Compare>
void insert(vector<T> &arr, T const &val, Compare &cmp) {
  arr.push_back(val);
  siftUp<T>(arr, arr.size() - 1, cmp);
}
```

## 堆排序
写到这里，堆排序就很容易了。

从上面的删除中，我们可以看到，最小堆每次删除的元素就是剩下的元素中最小的哪一个，如果我们把每次删除的元素依次放进一个新的数组，当我们删掉堆中所有元素的时候，那么新数组就是堆中原来元素的从小到大排列了。

```cpp
template<typename T, typename Compare>
vector<T> heapSort(vector<T> &arr, Compare &cmp) {
  build(arr, cmp);
  vector<T> new_arr;
  while(arr.size()) {
    new_arr.push_back(arr.front());//push the first element into the new array
    rmFirst(arr, cmp);
  }
  return new_arr;
}
```

测试一下
```cpp
int main()
{
  vector<int> arr = {7, 10, 4, 3, 9, 12, 15, 8, 16, 6};
  less_equal<int> cmp;
  for(auto v: heapSort<int, less_equal<int>>(arr, cmp))
    cout << v << ' ';
  cout << endl;
  return 0;
}
```

```
3 4 6 7 8 9 10 12 15 16
```

附上最后的代码：

```cpp
template <typename T, typename Compare>
void siftDown(vector<T> &arr, int x, Compare &cmp) {
  int n = arr.size();
  while(!(n/2 <= x && x < n)) /* judge whether x is a leaf*/{
    //get the max/min child
    int lc = x * 2 + 1, rc = lc + 1; //lc is left child, lr is right child
    if(rc < n && cmp(arr[rc], arr[lc]))
      lc = rc;
    //compare with parent node
    if(cmp(arr[x], arr[lc]))//meet the condition
      break;
    //sift down
    swap(arr[x], arr[lc]);
    x = lc;
  }
}
template<typename T, typename Compare>
void build(vector<T> &arr, Compare &cmp) {
  for(int x = arr.size() / 2 - 1; x >= 0; --x)
    siftDown<T, Compare>(arr, x, cmp);
}
template<typename T, typename Compare>
void rmFirst(vector<T> &arr, Compare &cmp) {
  swap(arr.front(), arr.back());
  arr.pop_back();
  if(arr.size())
    siftDown<T, Compare>(arr, 0, cmp);
}
template<typename T, typename Compare>
vector<T> heapSort(vector<T> &arr, Compare &cmp) {
  build(arr, cmp);
  vector<T> new_arr;
  while(arr.size()) {
    new_arr.push_back(arr.front());//push the first element into the new array
    rmFirst(arr, cmp);
  }
  return new_arr;
}
```

## 优化空间
上面的堆排序的空间复杂度是O(n)，我们可以将其优化为$O(1)$。

实现的方法很简单，就是假装删除，我们把首尾元素交换后，并不删除最后一个元素，维护一个变量n来记录堆的大小，这样的话，我们得到的堆在数组中就是从大到小排列了，只需将其逆序即可。

```cpp
template <typename T, typename Compare>
void siftDown(vector<T> &arr, int n, int x, Compare &cmp) {
  while(!(n/2 <= x && x < n)) /* judge whether x is a leaf*/{
    //get the max/min child
    int lc = x * 2 + 1, rc = lc + 1; //lc is left child, lr is right child
    if(rc < n && cmp(arr[rc], arr[lc]))
      lc = rc;
    //compare with parent node
    if(cmp(arr[x], arr[lc]))//meet the condition
      break;
    //sift down
    swap(arr[x], arr[lc]);
    x = lc;
  }
}

template<typename T, typename Compare>
void build(vector<T> &arr, Compare &cmp) {
  int n = arr.size();
  for(int x = n / 2 - 1; x >= 0; --x)
    siftDown<T, Compare>(arr, n, x,cmp);
}

template<typename T, typename Compare>
void rmFirst(vector<T> &arr, int n, Compare &cmp) {
  --n;
  swap(arr.front(), arr[n]);
  siftDown<T, Compare>(arr, n, 0,cmp);
}

template<typename T, typename Compare>
vector<T> heapSort(vector<T> &arr, Compare &cmp) {
  build(arr, cmp);
  for(int n = arr.size(); n > 1;--n) /* (n-1) times */
    rmFirst(arr, n, cmp);
  reverse(arr.begin(), arr.end());
  return arr;
}
```