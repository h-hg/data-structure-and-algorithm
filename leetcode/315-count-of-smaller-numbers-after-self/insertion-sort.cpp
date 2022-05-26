#include <vector>
using namespace std;
class Solution {
public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> ans(nums.size(), 0);
    for(int n = nums.size() - 1, i = n - 1; i >= 0; --i) {
      int nStep = 0;
      // move and swap
      for(int j = i; j < n && nums[j] > nums[j + 1]; ++j) {
        swap(nums[j], nums[j+1]);
        ++nStep;
      }
      ans[i] = nStep;
    }
    return ans;
  }
};