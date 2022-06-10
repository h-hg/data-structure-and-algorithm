#include <vector>
#include <queue>
#include <tuple>
using namespace std;
class Solution {
public:
  const int FLAG = -1;
  const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int shortestBridge(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    // find one of bridge
    int r, c;
    for(r = 0; r < m; ++r)
      for(c = 0; c < n; ++c)
        if(grid[r][c] == 1)
          goto FOUND;
FOUND:
    // using bfs to label the bridge
    queue<pair<int, int>> q1, q2;
    q1.push({r, c});
    q2.push({r, c}); // add multi-bfs source
    // set visited
    grid[r][c] = FLAG;
    while(q1.size()) {
      tie(r, c) = q1.front();
      q1.pop();
      for(auto [deltaR, deltaC] : dirs) {
        auto newR = r + deltaR, newC = c + deltaC;
        if(
          newR >= 0 && newR < m && newC >= 0 && newC < n
          && grid[newR][newC] == 1
        ) {
          q1.push({newR, newC});
          q2.push({newR, newC}); // add multi-bfs source
          grid[newR][newC] = FLAG;
        }
      }
    }
    // calculate the shortest path length
    int ans = 0;
    for(ans = 0; q2.size(); ++ans) {
      for(int i = 0, t = q2.size(); i < t; ++i) {
        tie(r, c) = q2.front();
        q2.pop();
        for(auto [deltaR, deltaC] : dirs) {
          auto newR = r + deltaR, newC = c + deltaC;
          if(!(newR >= 0 && newR < m && newC >= 0 && newC < n))
            continue;
          if(grid[newR][newC] == 0) {
            grid[newR][newC] = FLAG;
            q2.push({newR, newC});
          } else if(grid[newR][newC] == 1)
            goto ANS;
        }
      }
    }
ANS:
    return ans;
  }
};