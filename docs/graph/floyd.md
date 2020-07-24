# Floyd

Floyd（弗洛伊德）算法用来解决全源最短路径问题，即给出图 G(V, E)，求任意两点 u、v 之间的最短路径的长高度，时间复杂度为$O(n^3)$，其中$n$为图中节点的个数。

## 原理

为了方便描述，引入如下记号：
- $n$：图中节点的个数
- $e[u][v]$：节点$u$与其相邻节点$v$的距离，也就是邻接矩阵的表示方法
- $d[u][v]$：节点$u$与节点$v$的最短距离

Floyd算法基于这样一个事实:如果存在顶点$k$，使得以$k$作为中介点时顶点$i$和顶点$j$的当前最短距离缩短，则使用顶点$k$作为顶点$i$和顶点$j$的中介点，即当$d[i][k] + d[k][j] < d[i][j]$时，令$d[i][j] = d[i][k] + d[k][j]$。

## 实现

基于上面的事实，Foyd算法的伪代码

```
for k in [0, n)
  for i, j in [0, n)
    if(d[i][k] + d[k][j] < d[i][j])
      d[i][j] <- d[i][k] + d[k][j]
```

C++ 代码如下

```cpp
#include <vector>
using namespace std;
//e is adjacent matrix
vector<vector<int>> floyd(const vector<vector<int>> &e) {
  //init the d
  auto d = e;
  int n = d.size();
  for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j) {
        if(d[i][k] == INT_MAX || d[k][j] == INT_MAX)
          continue;
        else if(d[i][k] + d[k][j] < d[i][j])
          d[i][j] = d[i][k] + d[k][j];
  return d;
}
```