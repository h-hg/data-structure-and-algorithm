#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if(int maxVal = *max_element(nums.begin(), nums.end()); maxVal < 0)
      return maxVal;
    int ans = 0, wndSum = 0;  // the sum of elements in the window
    for (int l = 0, r = 0; r < nums.size();) {
      // enlarge the window
      wndSum += nums[r++];
      // shrink the window
      while(wndSum < 0)
        wndSum -= nums[l++];
      // update the ans
      ans = max(ans, wndSum);
    }
    return ans;
  }
};