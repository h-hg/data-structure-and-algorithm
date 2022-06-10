# Word Ladder

- [Leetcode](https://leetcode.com/problems/word-ladder)
- [力扣中国](https://leetcode.cn/problems/word-ladder)

## Problem

[](desc.md ':include')

## Solution

### BFS

由于中间单词必须在 `wordList` 中，所以可以建立一个 `wordList` 单词关系的无向图。
若单词 a 可以通过修改一个字符变化为单词 b，则在无向图中，存在一条 a 到 b 的（无向）边。
那么问题就可以转化为查找 `beginWord` 到 `endWord` 的最短路径长度。

记 $N$ 为 `wordList` 的长度，$n$ 为单词的最大长度。
有如下两种方案来构建无向图。

1. 让两个单词两两比较，判断他们是否只有一个字母不一样，那么构建无向图的复杂度为 $N^2 n$。
2. 让单词都映射到一个哈希表，然后遍历每个单词，对每个字符进行修改（从 `a` 改到 `z`），然后判断修改后的单词是否在哈希表，若存在的话，则可构建一条无向边。那么构建无向图的复杂度为 $N \cdot 26n$。

由题目可以知道

- $1 \le N \le 5000$
- $1 \le n \le 10$

所以选择哈希表来建立哈希表的复杂度比较低。

BFS 的代码如下

[](bfs1.cpp ':include :type=code cpp')

其实，我们还可以构图进一步优化。
图中有些边在搜索过程中是没有用到的，例如
```
beginWord = "hit"
endWord = "hot"
wordList = ["hot","dot","dog","lot","log","cog"]
ans =  2, "hit" -> "hot"
```
那么 `dot` 和 `dog` 等边构建在搜索中过程是没有用到的。
所以，可以在边搜索边“建图”。

[](bfs2.cpp ':include :type=code cpp')

### Bi-BFS

这道题可以从 `beginWord` 和 `endWord` 两端搜索（双向 BFS），这样可以减少搜索访问的节点数，进一步减少搜索时间。

[](bi-bfs.cpp ':include :type=code cpp')

注意：

- 由于要判断元素是否在另一端搜素，所以使用 `set`，而不是 `queue`
- 使用了贪心的思想，每次从两端交替搜索时，总是使用节点少的一端搜索，可以加快搜索的速度。
