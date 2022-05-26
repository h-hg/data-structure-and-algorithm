#include <vector>
using namespace std;
class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int n = nums.size(), slow = -1, fast = 0;
    // move
    while(fast != n) {
      if(nums[fast] != 0)
        nums[++slow] = nums[fast];
      ++fast;
    }
    // set zero in the end
    while(++slow != n)
      nums[slow] = 0;
  }
};