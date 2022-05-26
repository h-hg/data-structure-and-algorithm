#include <vector>
using namespace std;
class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int n = nums.size(), ans = 0;
    vector<vector<int>> dp(n + 1, 0);
    for(int j = 1; j <= n; ++j)
      dp[j] = dp[j - 1] + nums[j - 1];
    for(int st = 0; st < n; ++st)
      for(int ed = st + 1; ed <= n; ++ed)
        if(dp[ed] - dp[st] == k)
          ++ans;
    return ans;
  }
};