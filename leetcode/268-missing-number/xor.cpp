#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int ans = 0, n = nums.size();
    ans ^= n;
    for(int i = 0; i < n; ++i)
      ans ^= i ^ nums[i];
    return ans;
  }
};