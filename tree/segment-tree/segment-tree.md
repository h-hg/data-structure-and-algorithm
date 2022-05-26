# 线段树

笔记主要来自《高级数据结构》（林厚从）。

## 背景
实在不知道怎么引入线段树，从背景开始介绍吧。

在OJ上，可能会遇到一类这样的问题，它们通常可以建模成数轴上的问题或数列的问题，具体的操作一一般是每次对数轴上一个区间或连续若干个数进行**相同的**操作，下面以例子引入区间树，并逐渐加深。

## 问题1
描述：有一个长度为n的数列，数列初始的时候都是零，现在执行m次操作，每次可以执行一下两种操作之一：
1.将数列中的某个数加上某个数值
2. 查询给定区间中所有数的和

假设：m >> n

## 分析
如果采用简单的模拟算法的话，每次修改（操作1）时间复杂度是$\Theta(1)$，每次查询（操作2）则为$\Theta(n)$，如果查询操作占比很大的话，那么这m次操作的时间就是$O(mn)$，那么其效率往往不能令人满意。

> 这个算法低效的一个重要原因就是所有的维护都是针对元素的,而题目中所用到的查询对区间的。所以,我们的优化也就应该从这里着手。假如我们设计一种数据结构,能够直接维护所需处理的区间,那么就能更加有效地解决这个问题了。线段树就是这样一种数据结构,它能够将我们需要处理的区间不相交地分成若干个小区间,每次维护都可以在这样一些分解后的区间上进行,并且查询的时候,我们也能够根据这些被分解了的区间上的信息合并出整个询问区间上的查询结果。

## 线段树
线段树是一棵**二叉树**，同时是一棵**平衡二叉树**，如下图，它表示了问题1中n为9的线段树。

![](example-n=10.drawio.svg)

性质：
1. 每个节点都代表了一个区间，叶子节点则是长度为1的区间，也就是一个元素。
2. 高度不会超过$\log_2(n)$
3. 节点数量不会超过$2n$

2和3的证明稍后再写。

## 代码概况
### 节点定义
```cpp
template <typename T>
struct Node {
  int l, r;// [l, r)
  Node<T> *lc, *rc;
  T val;
  Node(int left, int right, Node<T> *plc = nullptr, Node<T> *prc = nullptr, T const &total = T()):l(left), r(right), lc(plc), rc(prc), val(total){}
};
```
属性`l`和`r`用来表示节点所代表的区间`[l, r)`，`val`用来表示区间`[r, l)`元素的和。
### 代码框架
```cpp
template <typename T>
class SegmentTree {
public:
  ~SegmentTree() {
    destory(_root);
  }
protected:
  Node<T> *_root = nullptr;
  //free the tree rooted at `root`
  void destory(Node<T> *root) {
    if(root == nullptr)
      return;
    destory(root -> lc);
    destory(root -> rc);
    delete root;
  }
};
```

## 问题1的实现
### 初始化
```cpp
// build the segment tree
Node<T>* build(int l, int r) {
  auto node = new Node<T>(l, r);
  if(l + 1 < r) {
    int mid = (l + r) / 2;
    node -> lc = build(l, mid);
    node -> rc = build(mid, r);
  }
  return node;
}

SegmentTree(int n) {
  _root = build(0, n);
}
```

### 查询
```cpp
T query(int l, int r) const {
  return query(l, r, _root);
}
T query(int l, int r, Node<T> const *root) const {
  if(l <= root -> l && root -> r <= r) /* The interval of the query contains the interval of the current node */{
    return root -> val;
  } else {
    T ans = 0;
    int mid = (root -> l + root -> r) / 2;
    if(l < mid)
      ans += query(l, r, root -> lc);
    if(r > mid)
      ans += query(l, r, root -> rc);
    return ans;
  }
}
```
查询的复杂度为$\Theta(\log n)$
### 修改
```cpp
void change(int x, T const &delta) {
  change(x, delta, _root);
}
void change(int x, T const &delta, Node<T> * root) {
  if(root -> l + 1 == root -> r) {
    root -> val += delta;
  } else {
    change(x, delta, x < (root -> l + root -> r) / 2 ? root -> lc : root -> rc);
    root -> val = root -> lc -> val + root -> rc -> val;
  }
}
```

修改的复杂度为$\Theta(\log n)$
## 问题2
在问题1中，我们每次修改的元素只有一个，将该操作泛化，改为每次修改的是一个区间（`[l, r)`）的元素。

最简单的实现便是把上面的`void change(int x, T const &delta)`函数修改成如下。
```cpp
void change(int l, int r, T const &delta) {
  for(;l < r; ++l)
    change(l, delta, _root);
}
```
如果这样的话，其时间复杂度为$O(n \log n)$，比我们简单模拟的复杂度（$O(n)$）还高。比如，当$n = 9$（如示例中的线段树所示），如果我们要修改的区间的是`[0, 8)`的话，那么修改的节点一共有16个，只有`[8, 9)`这个节点不用修改。

为了让修改区间的复杂度依旧是$\Theta(\log n)$，我们修改线段树中延迟标志。
## 延迟标志

> 有一种可行的方法是对上面的维护操作进行修改。为了保证每次修改操作的时间复杂度仍然为$\Theta(\log n)$,在递归过程中,如果发现修改的区间已经覆盖了当前结点,那么就要停止继续递归(参考查询操作)。由于没能实际更新到区间中每个元素,也就是叶结点,所以在下次查询的时候为了能够得到足够的信息,我们需要在这些区间上进行标记。但是与前面介绍的情况不同,这里的这个标记不仅仅是一个结点的性质,它是作用于整个子树的。设想如果我们的另一个查询区间分解后包括一个在当前区间子孙中的区间,那么这个标记显然也要对之后的查询产生影响。

延迟标记：每个节点新增加一个标记，记录这个节点是否进行了某种修改(这种修改操作会影响其子节点)。

对于区间的修改，我们先按照递归的方式查找要修改的区间。
- 如果当前节点的区间被包含于要修改的区间，修改这些节点的信息，并给这些节点标记上代表这种修改操作的标记，停止递归。
- 如果当前节点并不被包含于要修改的区间，要看该节点是否被标记，如果有，就要按照标记修改其子节点的信息，并且给子节点都标上标记，同时消掉该节点的标记，继续递归。

对于区间的查询：我们需要增加一步操作。由于节点的信息可能是没有更新好的，也就是修改操作没有完全修改线段树的所有要修改的节点，我们就要看该节点是否被标记，如果有，就要按照标记修改其子节点的信息，并且给子节点都标上标记，同时消掉该节点的标记。

## 问题2的实现
### 节点定义
```cpp
template <typename T>
struct Node {
  int l, r;
  Node<T> *lc, *rc;
  mutable T val;
  mutable T mark;
  Node(int left, int right, Node<T> *plc = nullptr, Node<T> *prc = nullptr, T const &total = T()):l(left), r(right), lc(plc), rc(prc), val(total), mark(0){}
};

```
比原先的节点多了个属性`mark`用来储存标志信息。

### 传递标志
```cpp
void update(Node<T> const *root) const {
  if(root -> mark == T(0))
    return;
  auto lc = root -> lc, rc = root -> rc;
  lc -> mark += root -> mark;
  lc -> val += root -> mark * (lc -> r - lc -> l);
  rc -> mark += root -> mark;
  rc -> val += root -> mark * (rc -> r - rc -> l);
  root -> mark = T(0);
}
```
### 修改
```cpp
void change(int l, int r, T const &delta, Node<T> *root) {
  if(l <= root -> l && root -> r <= r) {
    root -> val += delta * (root -> r - root -> l);
    root -> mark += delta;
  } else {
    update(root);
    int mid = (root -> l + root -> r) / 2;
    if(l < mid)
      change(l, r, delta, root -> lc);
    if(r > mid)
      change(l, r, delta, root -> rc);
    root -> val = root -> lc -> val + root -> rc -> val;
  }
}
```
### 查询
```cpp
T query(int l, int r, Node<T> const *root) const {
  if(l <= root -> l && root -> r <= r) /* The interval of the query contains the interval of the current node */{
    return root -> val;
  } else {
    update(root);
    T ans = 0;
    int mid = (root -> l + root -> r) / 2;
    if(l < mid)
      ans += query(l, r, root -> lc);
    if(r > mid)
      ans += query(l, r, root -> rc);
    return ans;
  }
}
```

## 问题2的例子
假设我们经过多次修改元素的值，形成了如下的线段树（实际上按照我们写的代码，不可能形成如下的树，稍后说明，但不影响我们对代码的理解）。
![](lazy-propagation-1.drawio.svg)

现在我们要给`[0, 5)`的所有元素加上1，`change`函数调用如下。
![](lazy-propagation-2.drawio.svg)

接着查询`[1,4)`，`query`函数调用如下
![](lazy-propagation-3.drawio.svg)

最后，我们线段树的节点如下。
![](lazy-propagation-4.drawio.svg)

1. `update`函数可以看作是对`mark`的分解，将`mark`分解给它的左右孩子。

2. 我们可以看到叶子节点的`mark`只会增加，不会减少。
因为清除`mark`只出现在`update`，在`query`和`change`函数中，如果`root`是叶子的话，，那么必定满足`l <= root -> l && root -> r <= r`（可以从进入叶子节点的条件进行分析），所以都不会调用`update`函数，叶子的`mark`只会增加不会减少，也就不可能形成我们例子中第一幅图了。

3. 某个节点上到根节点路径上所有祖辈节点的标志都会对该节点产生影响
因为祖辈节点的标志都会通过`update`函数一步步传递下来。