#include <vector>
#include <set>
#include <map>
using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> val2pos;
    for(int i = 0; i < nums.size(); ++i) {
      int remainder = target - nums[i];
      if(val2pos.find(remainder) != val2pos.end())
        return {val2pos[remainder], i};
      val2pos[nums[i]] = i;
    }
    return {};
  }
};