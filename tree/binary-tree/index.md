# 二叉树

二叉树就是树中结点的度最多为2的树。

### 分类

二叉树按照结点个数情况可以分为

- 满二叉树
- 完全二叉树
- 普通二叉树

### 性质

1. 非空二叉树上的叶子结点数等于度为2的结点数加1，即no=n2＋1。

证明∶设度为0，1和2的结点个数分别为no，n和n2，结点总数n=no+n+n2。再看二叉树中的分支数，除根结点外，其余结点都有一个分支进入，设B为分支总数，则n=B＋1。由于这些分支是由度为1或2的结点射出的，所以又有B=n+2n2。于是得no+n1+n2=n1+2n2＋1，则n0=n2＋1。
注意∶该结论经常在选择题中用到，希望考生牢记并灵活应用。拓展到任意一棵树，若
结点数量为 n，则边的数量为n-1。

2. 对完全二叉树按从上到下、从左到右的顺序依次编号1，2，…，n，则有以下关系∶①当i>1时，结点i的双亲的编号为i/2，即当i为偶数时，其双亲的编号为2，它是双亲的左孩子;当i为奇数时，其双亲的编号为（i-1）/2，它是双亲的右孩子。②当2i≤n时，结点i的左孩子编号为2i，否则无左孩子。③当2i＋1≤n时，结点i的右孩子编号为2i+1，否则无右孩子。④结点i所在层次（深度）为Llog2i+1。
3. 具有n个（n>0）结点的完全二叉树的高度为「log2（n＋1）或Llogn+1。

设高度为h，根据性质3和完全二叉树的定义有2-1-1<n≤2*-1或2≤n<2* 得2<n＋1≤2，即h-1<log（an+1）≤h，因为h为正整数，所以h=【log（n＋1）】。或得h-1≤logn<h，所以h=Llog2n】+1。

3. 空指针的个数为n+1

## 顺序存储

填充成完全二叉树，空间利用率低下

## 链式存储

一般的实现方式

## 遍历

1. pre-order: 根、左、右
2. in-order：左、根、右
3. post-order：左、右、根
4. 层次遍历

注意看非递归的实现。
```cpp
void inOrder(Node<T> *root) {
  stack<Node<T>*, vector<Node<T*>>> st;
  while(root || st.size()) {
    if(root) {
      st.push(root);
      root = root -> l;
    } else {
      root = st.
    }
  }
}
```

树的层次遍历与图有点小区别

```cpp
void levelOrder(Node<T> *root) {
  queue<Node<T> *> q;
  q.push(root);
  while(q.size()) {
    // every level
    for(int i = 0, n = q.size(); i < n; ++i) {
      auto node = q.front();
      q.pop();
      //visit the node
      if(node -> lc)
        q.push(node -> lc);
      if(node -> rc)
        q.push(node -> rc);
    }
  }
}
```

连接表的图的层次遍历

```cpp
void levelOrder(int source, vector<vector<int>> &graph) {
  vector<bool> vis(graph.size() + 1, false);
  queue<int> q;
  q.push(source);
  while(q.size()) {
    //every level
    for(int i = 0, n = q.size(); i < n; ++i) {
      auto node = q.front();
      q.pop();
      if(vis[node])
        continue;
      vis[node] = true;
      //visit the node
      for(auto &neighbor : graph[node])
        q.push(neighbor);
    }
  }
}
```

## 构建

由先序遍历和中序遍历构建二叉树。

一道有趣的题目（利用先序遍历的特点）：[1099 Build A Binary Search Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805367987355648)


先序序列构建BST = 第一个结点为根结点，然后将后面的序列结点不断插入。
[1135 Is It A Red-Black Tree (30point(s))](https://pintia.cn/problem-sets/994805342720868352/problems/994805346063728640)

构建完全二叉搜索树 [1064 Complete Binary Search Tree (30point(s))](https://pintia.cn/problem-sets/994805342720868352/problems/994805407749357568)
