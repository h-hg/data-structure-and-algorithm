#include <vector>
using namespace std;
class Solution {
public:
  bool canWinNim(int n) {
    if(n <= 3)
      return true;
    auto dp = vector<bool>(n + 1);
    dp[1] = dp[2] = dp[3] = true;
    for(int i = 4; i <= n; ++i)
      dp[i] = !dp[i-1] || !dp[i-2] || !dp[i-3];
    return dp[n];
  }
};
