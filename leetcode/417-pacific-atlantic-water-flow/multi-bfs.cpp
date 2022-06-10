#include <vector>
#include <queue>
#include <tuple>
using namespace std;
class Solution {
public:
  const vector<pair<int,int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  vector<vector<bool>> bfs(vector<vector<int>> &height, queue<pair<int, int>> &q) {
    int m = height.size(), n = height[0].size();
    vector<vector<bool>> dp(m, vector<bool>(n, false));
    while(q.size()) {
      int r, c;
      tie(r, c) = q.front();
      q.pop();
      dp[r][c] = true;
      for(auto &dir : dirs) {
        auto newR = r + dir.first, newC = c + dir.second;
        if(
          newR >= 0 && newR < m && newC >= 0 && newC < n
          && height[r][c] <= height[newR][newC]
          && !dp[newR][newC]
        )
          q.push({newR, newC});
      }
    }
    return dp;
  }
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    queue<pair<int,int>> qPacific, qAltantic;
    // add BFS source
    for(int j = 0; j < n; ++j) {
      qPacific.push({0, j});
      qAltantic.push({m - 1, j});
    }
    for(int i = 0; i < m; ++i) {
      qPacific.push({i, 0});
      qAltantic.push({i, n - 1});
    }
    // multi-BFS
    auto pacific = bfs(heights, qPacific);
    auto altantic = bfs(heights, qAltantic);
    // both
    vector<vector<int>> ans;
    for(int i = 0; i < m; ++i)
      for(int j = 0; j < n; ++j)
        if(pacific[i][j] && altantic[i][j])
          ans.push_back({i, j});
    return ans;
  }
};