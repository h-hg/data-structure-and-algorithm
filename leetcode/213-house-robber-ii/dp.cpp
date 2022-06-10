#include <vector>
using namespace std;
class Solution {
public:
  using Iter = vector<int>::const_iterator;
  int robRange(Iter first, Iter last) {
    int dp1 = *first, dp2 = max(dp1, *++first);
    for(++first; first != last; ++first) {
      int tmp = dp2;
      dp2 = max(dp1 + *first, dp2);
      dp1 = tmp;
    }
    return dp2;
  }
  int rob(vector<int>& nums) {
    if(nums.size() == 1)
      return nums.front();
    else if(nums.size() == 2)
      return max(nums[0], nums[1]);
    else
      return max(robRange(nums.begin(), --nums.end()), robRange(++nums.begin(), nums.end()));
  }
};