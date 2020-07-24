## Prim 算法

## 简介

Prim（普里姆算法）用于解决最小生成树的问题。

为了方便描述，我们引入下面的记号。
- 无向连通图$G(V, E)$，节点个数为$n$
- 集合$S$：已经被访问过的节点的集合
- $T$：最小生成树
- $d[i]$：表示顶点$i$到集合$S$的最短距离，即顶点$i$与集合$S$链接的边长。
- $e[u][v]$：节点$u$与其邻居节点$v$的边或其距离

步骤
1. 从集合$V$随机选出一个节点$s$作为初始节点，加入集合$S$（设置为已访问），加入$T$
2. 从集合$V-S$中选出一个节点$u$，使得$\underset{\forall s \in S}{\min}\ e[s][u]$最小，将$v$加入集合$S$，将$u$和$e[s][u]$加入$T$
3. 判断集合$V-S$是否为空，否的话，重复步骤2

## 例子
在例子中，我们选择了$v_0$作为初始节点，红色部分表示当前的最前生成树。

![](prim/prim-example.drawio.svg)

## 实现
步骤2并没有说明如何从集合$V-S$中找出距离$S$最近的顶点，下面给出步骤2的一种具体实现。
从上面的描述，我们可以看到 prim 与 dijkstra 在步骤2存在着相似的地方，dijkstra 将离起点$s$最后的顶点加入集合$S$，prim 将离集合$S$最近的顶点加入集合$S$，类比 dijkstra，将上面的步骤改成如下

1. 从集合$V$随机选出一个节点$s$作为初始节点，将$d$全部元素初始化为$\infty$，并令$d[s] = 0$。
2. 从集合$V - S$中寻找最小值$d[u]$，标记$u$为已访问，使用 $d[v_i] = \underset{v_i \ is \ neighbour \ of \  u}{\min} (d[v_i], e[u][v_i])$更新节点$u$与其邻居并且是集合$V-S$的节点$v_i$的$d[v_i]$
3. 判断$V-S$是否为空集，否的话，跳转到步骤2

具体的 C++ 代码如下
```cpp
//e is adjacent matrix
//return the sum of the smallest edge weight, return -1 when the graph is not the connected graph
int prim(vector<vector<int>> const &e) {
  int n = e.size(), ret = 0;
  //init
  vector<int> d(n, INT_MAX);
  vector<bool> vis(n, false);
  //select v0 as starting vertex
  d[0] = 0;
  for(int i = 0; i < n; ++i) {
    int u = -1;
    for(int j = 0, curMin = INT_MAX; j < n; ++j)
      if(vis[j] == false && d[j] < curMin) {
        u = j;
        curMin = d[j];
      }
    if(u == -1)
      return -1;
    vis[u] = true;
    ret += d[u];
    for(int v = 0; v < n; ++v)
      if(vis[v] || e[u][v] == INT_MAX)
        continue;
      else if(e[u][v] < d[v])
        d[v] = e[u][v];
  }
  cout << endl;
  return ret;
}
```

上面函数的返回值是最小生成树的边权之和，如果删去累计边权之和的代码，该实现与 dijkstra 的差别只是在更新$d[i]$部分，值得注意的是，两者$d[i]$的意义是不同的。
- dijkstra: 表示当前起点$s$到节点$i$的最短距离。
- prim: 表示顶点$i$到集合$S$的最短距离，即顶点$i$与集合$S$链接的边长。

## 优化
与 dijkstra 相同的，我们可以使用堆来优化查找节点$u$，具体描述见 dijkstra的博文。

```cpp
int prim(const vector<vector<int>> &e) {
  int n = e.size(), ret = 0;
  //init
  vector<int> d(n, INT_MAX);
  vector<bool> vis(n, false);
  //select v0 as starting vertex
  d[0] = 0;
  using P = pair<int, int>;//node id, d[id]
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push({0, 0});
  while(pq.empty() == false) {
    //find the u
    auto p = pq.top();
    pq.pop();
    int u = p.second;
    if(vis[u])
      continue;
    // mark u
    vis[u] = true;
    ret += d[u];
    // update the d
    for(int v = 0; v < n; ++v)
      if(vis[v] || e[u][v] == INT_MAX)
        continue;
      else if(e[u][v] < d[v]) {
        d[v] = e[u][v];
        pq.push({d[v], v});
      }
  }
  return ret;
}
```