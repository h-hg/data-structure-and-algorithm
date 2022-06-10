#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    auto &dp = nums;
    for(int i = 1, n = nums.size(); i < n; ++i)
      dp[i] = max(dp[i], dp[i - 1] + nums[i]);
    return *max_element(dp.begin(), dp.end());
  }
};