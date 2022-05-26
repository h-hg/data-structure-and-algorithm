#include "solution.h"
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  TreeNode* helper(vector<int>::const_iterator first, vector<int>::const_iterator last) {
    if(first == last)
      return nullptr;
    auto maxPos = max_element(first, last);
    auto l = helper(first, maxPos),
         r = helper(next(maxPos), last);
    return new TreeNode(*maxPos, l, r);
  }
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return helper(nums.begin(), nums.end());
  }
};