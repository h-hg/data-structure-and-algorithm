#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    return (n + 1) * n / 2 - accumulate(nums.begin(), nums.end(), 0);
  }
};