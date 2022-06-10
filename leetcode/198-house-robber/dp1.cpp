#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
  int rob(vector<int>& nums) {
    if(nums.size() == 1)
        return nums.front();
    auto &dp = nums;
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < nums.size(); ++i)
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    return dp.back();
  }
};