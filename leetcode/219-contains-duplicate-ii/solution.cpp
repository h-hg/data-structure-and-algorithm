#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> val2pos;
    for(int i  = 0; i < nums.size(); ++i){
      if(val2pos.count(nums[i]) && i - val2pos[nums[i]] <= k)
        return true;
      val2pos[nums[i]] = i;
    }
    return false;
  }
};