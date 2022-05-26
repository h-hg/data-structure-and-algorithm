#include <vector>
using namespace std;
class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int ans = 0, n = nums.size();
    for(int st = 0; st < n; ++st) {
      int sum = 0;
      for(int ed = st; ed < n; ++ed) {
        sum += nums[ed];
        if(sum == k)
          ++ans;
      }
    }
    return ans;
  }
};