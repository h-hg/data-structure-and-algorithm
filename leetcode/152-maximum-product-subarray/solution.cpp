#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
  int maxProduct(vector<int>& nums) {
    auto dpMax = nums;
    auto dpMin = nums;
    for(int i = 1, n = nums.size(); i < n; ++i) {
        auto val1 = dpMax[i - 1] * nums[i], val2 = dpMin[i - 1] * nums[i];
        if(val1 > val2)
            swap(val1, val2);
        dpMax[i] = max(dpMax[i], val2);
        dpMin[i] = min(dpMin[i], val1);
    }
    return *max_element(dpMax.begin(), dpMax.end());
  }
};