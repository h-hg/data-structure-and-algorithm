#include "solution.h"
#include <algorithm>
using namespace std;
class Solution {
public:
  int ans = 0;
  // return diameter of BinaryTree `root`
  int helper(TreeNode *root) {
    if(!root)
      return 0;
    int l = helper(root -> left),
        r = helper(root -> right);
    ans = max(ans, l + r);
    return max(l, r) + 1;
  }
  int diameterOfBinaryTree(TreeNode* root) {
    helper(root);
    return ans;
  }
};