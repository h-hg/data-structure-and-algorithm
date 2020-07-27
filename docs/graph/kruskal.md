## Kruskal

## 简介
Kruskal（克鲁斯卡尔算法）用于解决最小生成树的问题，它采用了贪心的策略。

为了方便描述，我们引入下面的记号。

- 无向连通图$G(V, E)$，节点个数为$n$
- 集合$S$：已经被访问过的节点的集合
- $T$：最小生成树
- $e[u][v]$：节点$u$与其邻居节点$v$的边或其距离

步骤：

1. 对所有边按照权值从小到大进行排列。
2. 从小到大测试所有边，如果当前测试边所连接的两个顶点不在同一个连通块（另一种表达，如果将该测试边加入当前最小生成树，最小生成树是否存在环路），则将这条测试边加入当前最小生成树，否则，将边舍弃。
3. 所以节点是否已加入到最小生成树（换句话说，最小生成树的边的个数等于图的顶点数减一），否的话，重复步骤2

## 例子

![](kruskal/kruskal-example.drawio.svg)

## 实现

由于kruskal 算法是围绕边出发的，所以边的定义是需要的。

```cpp
struct Edge {
  int u, v;// edge from u to v (or v to u)
  int w;//weight
  Edge(int i, int j, int weight):u(i), v(j), w(weight) {}
  bool operator<(Edge const&e) const {return w < e.w;}
};
```

Kruskal 大体的伪代码如下

```
ret <- 0
edge_cnt <- 0
for e in sort(edges)
  if e.u and e.v are in the same connected component
    continue
  add e to T
  ret <- ret + e.w
  edge_cnt <- edge_cnt + 1
  if edge_cnt = n + 1
    break
return ret
```

从上面我们可以看到“最难的部分”就是`if e.u and e.v are not in the same connected component`和`add e to T`，也就是
- 如何判断测试边的两个端点是否在同一个连通块
- 如何将测试边加入最小生成树

如果把每个连通块看成一个集合，集合的元素是图中的顶点，那么“判断测试边的两个端点是否在同一个连通块”可转化为“判断两个元素是否在同一个集合”，“将测试边加入最小生成树”可转化为“合并测试边所在的集合和最小生成树的集合”，也就是并查集的问题了。

```cpp
//e is adjacent matrix
//return the sum of the smallest edge weight, return -1 when the graph is not the connected graph
int kruskal(vector<vector<int>> const &e) {
  int n = e.size(), ret = 0;
  //init the edge
  vector<Edge> edges;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < i; ++j)
      if(e[i][j] != INT_MAX)
        edges.push_back(Edge(i, j, e[i][j]));
  //sort the edge
  sort(edges.begin(), edges.end());
  //init the union find set
  UFSB ufs(n);
  for(auto &e : edges) {
    int faU = ufs.findRoot(e.u), faV = ufs.findRoot(e.v);
    if(faU == faV)
      continue;
    ufs.merge(faU, faV);
    ret += e.w;
    if(--n == 1)
      break;
  }
  return n == 1 ? -1 : ret;
}
```

上面的`USFB`为一个并查集的类，提供`findRoot`和`merge`的方法。