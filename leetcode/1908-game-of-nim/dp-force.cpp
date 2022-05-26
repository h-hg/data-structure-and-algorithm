#include <map>
#include <vector>
using namespace std;
class Solution {
public:
  map<vector<int>, bool> dp;
  bool dfs(vector<int>& piles) {
    if (auto iter = dp.find(piles); iter != dp.end())
      return iter->second;

    bool flag = false;
    for (int i = 0; i < piles.size() && !flag; ++i)
      for (int j = 1; j <= piles[i] && !flag; ++j) {
        piles[i] -= j;
        flag = !dfs(piles);
        // tracebacking
        piles[i] += j;
      }
    return dp[piles] = flag;
  }
  bool nimGame(vector<int>& piles) {
    dp[vector<int>(piles.size(), 0)] = false;
    return dfs(piles);
  }
};