#include <vector>
using namespace std;
class Solution {
public:
  enum {NONE = -1, FAIL = false, WIN = true};
  vector<int> dp;
  bool dfs(int n) {
    if(dp[n] != NONE)
      return dp[n];
    dp[n] = !dfs(n-1) || !dfs(n-2) || !dfs(n-3) ? WIN : FAIL;
    return dp[n];
  }
  bool canWinNim(int n) {
    if(n <= 3)
      return true;
    dp = vector<int>(n + 1, NONE);
    dp[1] = dp[2] = dp[3] = WIN;
    return dfs(n);
  }
};