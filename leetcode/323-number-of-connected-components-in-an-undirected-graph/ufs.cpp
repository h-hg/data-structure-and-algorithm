#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
  vector<int> father;
  void merge(int x, int y) {
    int rootX = findRoot(x), rootY = findRoot(y);
    father[rootX] = rootY;
  }
  int findRoot(int x) {
    int root = x;
    while(root != father[root])
      root = father[root];
    while(x != root) {
      auto tmp = father[x];
      father[x] = root;
      x = tmp;
    }
    return root;
  }
  int countComponents(int n, vector<vector<int>>& edges) {
    // init union find set
    father = vector<int>(n);
    iota(father.begin(), father.end(), 0);
    // union
    for(auto &edge : edges)
      merge(edge[0], edge[1]);
    // count
    vector<bool> flags(n ,false);
    for(int i = 0; i < n; ++i)
      flags[findRoot(i)] = true;
    return count(flags.begin(), flags.end(), true);
  }
};