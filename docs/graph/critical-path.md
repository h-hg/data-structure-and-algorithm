# 关键路径

## 简介

## AOV

## AOE

## 动态规划法

符号说明：
- `e[i][j]`：表示顶点$i$到顶点$j$ 的长度，也就是邻接矩阵的表示方法。
- `dp[i]`：表示从顶点$i$出发的最长路径的长度

从`dp[i]`的意义中，我们可以知道要计算图中的最长路径，只需要计算出所有顶点的`dp`值，然后从中获得最大的`dp`值即可。

动态规划更新公式：若$i$有一条边指向$j_k$的话，那么$d[i] = \underset{i \ has \ a \ edge \ to \ j_k}{\max}\{dp[j_k] + e[i][j_k]\}$

上面的公式说明我们想得到`dp[i]`，必须想得到其后面顶点$j_k$的`dp[jk]`。这一点很类似逆拓扑排序，但是我们可以使用更加简单的方法来实现，也就是使用递归的方法。

```cpp
int dp_helper(int i, vector<int> &dp, vector<vector<int>> &e) {
  if(dp[i] > 0) {
    return dp[i];
  }
  for(int j = 0; j < e[i].size(); ++j) {
    if(e[i][j] != INT_MAX) {
      dp[i] = max(dp[i], dp[j] + e[i][j]);
    }
  }
  return dp[i];
}

int cpm(vector<vector<int>> &e,) {
  int n = e.size();
  vector<int> dp(n, 0);
  for(int i = 0; i < n; ++i) {
    if(dp[i] != 0)
      dp_helper(i, dp, e);
  }
  return *max_element(dp.begin(), dp.end());
}
```

### 路径的求取

#### 路径唯一

之前在

#### 路径不唯一

#### 参考资料

- 胡凡、曾磊 《算法笔记》