#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> dp;
  int helper(vector<int> &nums, int i) {
    if(dp[i] != -1)
      return dp[i];
    int ans = 1;
    for(int j = 0; j < i; ++j)
      if(nums[j] < nums[i])
        ans = max(ans, helper(nums, j) + 1);
    return dp[i] = ans;
  }
  int lengthOfLIS(vector<int>& nums) {
    dp = vector<int>(nums.size(), -1);
    return *max_element(dp.begin(), dp.end());
  }
};