#include "solution.h"
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> ans;
  void helper(TreeNode *root, int level) {
    if(!root)
      return;
    if(level == ans.size())
      ans.push_back({});
    ans[level].push_back(root -> val);
    helper(root -> left, level + 1);
    helper(root -> right, level + 1);
  }
  vector<vector<int>> levelOrder(TreeNode* root) {
    helper(root, 0);
    return ans;
  }
};