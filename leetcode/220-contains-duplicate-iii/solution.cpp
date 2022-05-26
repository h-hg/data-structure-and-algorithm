#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    unordered_map<int, int> val2pos;
    for(int i = 0; i < nums.size(); ++i) {
      int num = nums[i];
      if(val2pos.count(num) && i - val2pos[i] <= k && abs(num ))
    }
  }
};