#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return adjacent_find(nums.begin(), nums.end()) != nums.end();
  }
};