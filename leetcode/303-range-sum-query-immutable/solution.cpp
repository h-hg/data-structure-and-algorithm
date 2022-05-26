#include <vector>
using namespace std;
class NumArray {
public:
  vector<int> dp;
  NumArray(vector<int>& nums) : dp(nums.size() + 1, 0) {
    for(int i = 1; i <= nums.size(); ++i)
      dp[i] = dp[i-1] + nums[i - 1];
  }

  int sumRange(int left, int right) {
    return dp[right + 1] - dp[left];
  }
};