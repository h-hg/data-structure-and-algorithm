# 并查集

并查集（union find set）是一种维和集合的数据结构，它支持下面两个操作。
1. 查找：判断两个元素是否在同一个集合
2. 合并：合并两个集合

## 实现

并查集常见的实现是使用数组，例如我们给每一个元素一个id，这个id用自然数来表示（与数组下标相同），也就是说我们用一个非零整数来表示一个元素。

```cpp
int father[N];
```

其中，`father[i]`表示元素i（i是id，下面不再指出）的父亲。我们利用这种树结构来边是一个集合，在同一个集合的元素具有一个共同的祖先，值得注意的是，若`father[i] = i`则表示元素i是这个集合的根元素。

![example](union-find-set/example.drawio.svg)

例如在上面的图中，`int father[] = {0, 0, 1, 1, 4, 4}`，包含两个集合

## 查找

从图中看出，如何判断两个元素是否在同一个集合，只需要判断两个元素的根元素是否为同一个元素即可。下面给出查找某个元素的根元素的代码。

```cpp
int findRoot(int x) {
  while(x != father[x]) {
    x = father[x];
  }
  return x;
}
bool isSameSet(int a, int b) {
  return findRoot(a) == findRoot(b);
}
```

## 合并

合并指的是两个集合合并为同一个集合。最简单的方法就是找出两个集合的根元素，然后把其中的一个根元素的father设置为另一个根元素。

例如，把上图的4指向0.

![merge](union-find-set/merge.drawio.svg)

实现代码

```cpp
void merge(int a, int b) {
  int rootA = findRoot(a),
      rootB = findRoot(b);
  if(rootA != rootB) {
    father[rootB] = rootA;
  }
}
```

## 优化

树的层越多，每次执行`findRoot`就会越久，最极端的情况下，也就是形成一个直链，其复杂度达到了$O(n)$。

最明显的优化便是采用路径压缩。也就是把每个元素直接指向它的根元素。例如我们可以把最开始的图优化成如下的图。

![optimization](union-find-set/optimization.drawio.svg)

我们选择每次执行`findRoot`的时候就执行一个路径压缩，把查询的元素以及它所有的祖先都直接指向它的根元素。

```cpp
int findRoot(int x) {
  int root = x;
  // the old findRoot
  while(root != father[root]) {
    root = father[root];
  }
  //The second pass: let nodes point to root
  while(x != father[x]) {
    int tmp = father[x];
    father[x] = root;
    x = tmp;
  }
  return root;
}
```