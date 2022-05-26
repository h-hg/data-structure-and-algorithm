#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> sortArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums;
  }
};