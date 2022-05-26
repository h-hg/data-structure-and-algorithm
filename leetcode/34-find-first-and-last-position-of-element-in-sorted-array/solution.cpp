#include <vector>
using namespace std;
class Solution {
public:
  int findLeft(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while(l <= r) {
      int mid = l + (r - l) / 2;
      if(nums[mid] < target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return l == nums.size() || nums[l] != target ? -1 : l;
  }
  int findRight(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while(l <= r) {
      int mid = l + (r - l) / 2;
      if(nums[mid] <= target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return r < 0 || nums[r] != target ? -1 : r;
  }
  vector<int> searchRange(vector<int>& nums, int target) {
    int l = findLeft(nums, target);
    if(l == -1)
      return {-1, -1};
    return {l, findRight(nums, target)};
  }
};