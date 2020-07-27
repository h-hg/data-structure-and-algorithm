# Warshall 算法

给定一个图，计算出两个顶点之间是否可以存在一条或多条路径，即两个顶点是否可以相互到达。在离散数学上，即传递闭包问题。

最显而易见的做法便是，如果两点顶点是给定的，我们可以从中其中一个顶点出发，使用深度搜索和广度搜索的方法来计算这两点之间是否存在路径。如果要计算出图中任意两点之间是否存在路径的话，按照上面的方法的话，复杂度太高了。

为了方便描述，引入下面的记号

- 图中的顶点的个数为$n$
- 图中的顶点的编号为$0...(n-1)$

在介绍 Warshall 算法之前，先引入一个$n$阶布尔矩阵$W$，如果顶点$i$与顶点$j$存在路径，则$W_{ij} = 1$，否则为0。

下面引入$W^{(k)}$的意义，矩阵$W^{(k)}$第$i$行$j$列元素$W^{(k)}_{ij}=1$，则表示顶点$i$与顶点$j$之间存在的所有路径，并且这条路径上的顶点$v_i$的编号小于$k$，换句话说，即路径为$i \rightarrow ... v_i ... \rightarrow j, v_i < k$。

从上面对$W^{(k)}$的定义，很容易知道

- $W^{(0)}_{ij}=1$，则表示顶点$i$和顶点$j$存在一条相邻的边。
- $W^{(n)}_{ij}=1$，则表示顶点$i$和顶点$j$存在一条路径，因为所有顶点都可以出现在这条路径中。

从上面可以看出$W^{(n)}$就是我们要算出的，Warshall 算法也就是要得出$W^{(n)}$。

为了计算$W^{(n)}$，我们给出$W^{(k)}$与$W^{(k-1)}$的关系。

$W^{(k)}_{ij}=1$，表示顶点$i$与顶点$j$之间存在一条路径，这条路径上的顶点的编号不超过$k$。

- 如果所有路径上的顶点的编号都不包含编号为$k-1$的顶点的话，即所有顶点的编号小于$k-1$，那么$W^{(k-1)}_{ij}=1$；
- 如果某在某一条路径包含编号为$k-1$的顶点的话，我们将该路径$i \rightarrow ... \rightarrow (k-1) \rightarrow ... \rightarrow j $拆分成两端路径，即$i \rightarrow .. \rightarrow (k-1)$和$(k-1) \rightarrow ... \rightarrow (k-1)$，那么易得$W^{(k-1)}\_{ik}=1$和$W^{(k-1)}_{kj}=1$

综上所述$W^{(k)}\_{ij} = W^{(k-1)}\_{ij}\ OR\ (W^{(k-1)}\_{ik}\ AND\ W^{(k-1)}_{kj})$，可以是找到了$W^{(k)}$和$W^{(k-1)}$之间的递推关系。

由$W^{(k-1)}$得到$W^{(k)}$的代码如下

```cpp
vector<vector<int>> f(vector<vector<int>> const &w, int k) {
  int n = w.size();
  auto ret = w;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      ret[i][j] = w[i][j] || (w[i][k-1] && w[k-1][j]);
  return ret; 
}
```

对于$W^{(0)}$的获取，如果顶点$i$和顶点$j$存在相邻的边，我们将$W^{(0)}_{ij}$设置为1。

进一步我们可以得到，由$W^{(0)}$到$W^{(n)}$的代码

```cpp
vector<vector<int>> warshall(vector<vector<int>> const &w0) {
  auto ret = w0;
  for(int k = 1; k <= n; ++k)
    ret = f(ret, k-1);
  return ret;
}
```

简化上面的代码，得

```cpp
vector<vector<int>> warshall(vector<vector<int>> const&w0) {
  int n = w0.size();
  auto w = w0;
  for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        w[i][j] = w[i][j] || (w[i][k] && w[k][j]);
  return w;
}
```