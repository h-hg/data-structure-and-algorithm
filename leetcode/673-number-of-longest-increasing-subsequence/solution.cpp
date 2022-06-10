#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<pair<int, int>> dp(n, {1, 1});
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < i; ++j)
        if(nums[j] < nums[i]) {
          auto diff = dp[j].first + 1 - dp[i].first;
          if(diff == 0)
            dp[i].second += dp[j].second;
          else if(diff > 0)
            dp[i] = {dp[j].first + 1, dp[j].second};
        }
    int maxLen = max_element(dp.begin(), dp.end(), [](pair<int, int> &x, pair<int, int> &y) {
      return x.first < y.first;
    }) -> first;
    int ans = 0;
    for(auto &p : dp)
      if(p.first == maxLen)
        ans += p.second;
    return ans;
  }
};