#include <vector>
using namespace std;
class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int n = nums.size(), slow = 0, fast = 1;
    while(fast != n) {
      if(nums[fast] != nums[slow])
        // add element to the new nums
        nums[++slow] = nums[fast];
      ++fast;
    }
    return slow + 1;
  }
};