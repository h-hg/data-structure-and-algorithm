#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    vector<int> dpMax(n, 0), dpMin(n, 0);
    dpMax[0] = dpMin[0] = nums[0];
    for(int i = 1; i < n; ++i) {
      dpMax[i] = max(nums[i], dpMax[i - 1] + nums[i]);
      dpMin[i] = min(nums[i], dpMin[i - 1] + nums[i]);
    }
    auto maxVal = *max_element(dpMax.begin(), dpMax.end());
    return maxVal < 0 ? maxVal : max(maxVal, accumulate(nums.begin(), nums.end(), 0) - *min_element(dpMin.begin(), dpMin.end()));
  }
};