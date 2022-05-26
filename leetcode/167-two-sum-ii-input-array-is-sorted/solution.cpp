#include <vector>
using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size() - 1;
    while(l < r) {
      auto sum = numbers[l] + numbers[r];
      if(sum < target)
        ++l;
      else if(sum == target)
        return {l + 1, r + 1};
      else
        --r;
    }
    return {l + 1, r + 1};
  }
};