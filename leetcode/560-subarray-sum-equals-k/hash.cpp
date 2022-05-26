#include <vector>
#include <map>
using namespace std;
class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    map<int, int> sum2cnt;
    sum2cnt[0] = 1;
    int ans = 0, sum = 0;
    for(auto &num : nums) {
      sum += num;
      auto complement = sum - k;
      if(auto iter = sum2cnt.find(complement); iter != sum2cnt.end())
        ans += iter -> second;
      ++sum2cnt[sum];
    }
    return ans;
  }
};