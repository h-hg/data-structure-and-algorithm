#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void print(vector<int> &v) {
  for(int i = 0; i < v.size(); ++i)
    cout << (i+1) << ':' << v[i] << ' ';
  cout << endl;
}
class Solution {
public:
  vector<int> findErrorNums(vector<int>& nums) {
    // find the repeat
    for(auto num : nums) {
      while(nums[num - 1] != num) {
        int tmp = nums[num - 1];
        nums[num - 1] = num;
        num = tmp;
      }
    }
    for(int i = 0; i < nums.size(); ++i)
      if(nums[i] != i + 1)
        return {nums[i], i + 1};
    return {};
  }
};

int main() {
  vector<int> v = {3, 2, 2};
  Solution sl;
  sl.findErrorNums(v);
  print(v);
  return 0;
}