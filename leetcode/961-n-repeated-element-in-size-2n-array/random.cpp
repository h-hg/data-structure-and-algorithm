#include <random>
#include <vector>
using namespace std;
class Solution {
public:
  int repeatedNTimes(vector<int>& nums) {
    default_random_engine rand_eng;
    uniform_int_distribution<int> u(0, nums.size() - 1);
    while(true) {
      int idx1 = u(rand_eng), idx2 = u(rand_eng);
      if(idx1 != idx2 && nums[idx1] == nums[idx2])
        return nums[idx1];
    }
    return -1;
  }
};
