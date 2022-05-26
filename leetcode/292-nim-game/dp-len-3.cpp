#include <vector>
using namespace std;
class Solution {
public:
  bool canWinNim(int n) {
    auto dp = vector<bool>(3, true);
    for(int i = 4; i <= n; ++i)
      // equal to dp[i % 3] = !dp[(i-1) % 3] || !dp[(i-2) % 3] || !dp[(i-3) % 3]
      dp[i % 3] = !dp[0] || !dp[1] || !dp[2];
    return dp[n % 3];
  }
};