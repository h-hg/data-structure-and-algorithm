# Construct Binary Tree from Preorder and Inorder Traversal

- [Leetcode](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal)
- [力扣中国](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal)

## Problem

[](desc.md ':include')

## Solution

[](solution.h ':include :type=code cpp')

```
   3
  /  \
 9   20
/ \  / \
7 6 15  7

preOrder = [3, 9, 7, 6, 20, 15, 7]
inOrder  = [7, 9, 6, 3, 15, 20, 7]
```

- `preOder` = 根节点（3）+ 左子树 `preOder`（`9, 7, 6`） + 右子树 `preOrder`（`20, 15, 7`）
- `inOrder` = 左子树 `inOder`（`7, 9, 6`）+ 根节点（3）+ 右子树 `inOrder`（`15, 20, 7`）

从上面的介绍中，不难看出只要把 `preOrder` 和 `inOrder` 拆成左右子树，就可以实现递归。

[](solution.cpp ':include :type=code cpp')

由于每次都需要在 `inOrder` 数组进行查找，可以对这一部分进行加速。
这里使用 `unordered_map` 进行加速。

[](map.cpp ':include :type=code cpp')
