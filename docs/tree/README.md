# 树型结构

树是$$个结点的有限集，它具有如下的定义

1. 要么有且仅有一个特定的结点称为根的结点。
2. 要么除去该结点后，其余结点可分为$m(m>0)$个互不相交的有限集$T_1,...,T_m$，其中每个集合本身又是一棵树，并且称为根的子树。

从上面可以看到树的定义满足递归定义。

## 基本概念

- 度：孩子的个数
- 深度、高度

关系

- 祖先
- 父亲
- 兄弟

## 分类

- 二叉树
- 树
- 森林

## 性质

树具有如下最基本的性质∶
1. 树中的结点数等于所有结点的度数加1。
2. 度为m的树中第i层上至多有m-个结点（i≥1）。3）高度为h的m叉树至多有（m²-1）/（m-1）个结点①。4）具有n个结点的m叉树的最小高度为【logm（n（m-1）+1）】】。
