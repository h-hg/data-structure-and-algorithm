#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
  int rob(vector<int>& nums) {
    if(nums.size() == 1)
        return nums.front();
    int dp1 = nums[0], dp2 = max(nums[0], nums[1]);
    for(int i = 2; i < nums.size(); ++i) {
      int tmp = dp2;
      dp2 = max(dp2, dp1 + nums[i]);
      dp1 = tmp;
    }
    return dp2;
  }
};