#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
 public:
  int minMoves2(vector<int>& nums) {
    nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    return accumulate(
      nums.begin(),
      nums.end(),
      0,
      [median = nums[nums.size() / 2]](int sum, int elem) {
        return sum + abs(elem - median);
      }
    );
  }
};