#include <vector>
using namespace std;
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int dp = nums.front(), ans = dp;
    for (int i = 1; i < nums.size(); ++i) {
      dp = max(nums[i], nums[i] + dp);
      ans = max(ans, dp);
    }
    return ans;
  }
};