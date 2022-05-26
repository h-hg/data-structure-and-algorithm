#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
  vector<int> findErrorNums(vector<int>& nums) {
    // find the repeat
    int repeat;
    for(auto num : nums) {
      auto idx = abs(num) - 1;
      if(nums[idx] < 0)
        repeat = idx + 1;
      else
        nums[idx] = - nums[idx];
    }
    // find the miss
    for(int i = 0; i < nums.size(); ++i)
      if(nums[i] > 0)
        return {repeat, i + 1};
    return {};
  }
};